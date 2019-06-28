[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Reference.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/Reference.zep",
        "line": 33,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Allows to define reference constraints on tables\n *\n *```php\n * $reference = new \\Phalcon\\Db\\Reference(\n *     \"field_fk\",\n *     [\n *         \"referencedSchema\"  => \"invoicing\",\n *         \"referencedTable\"   => \"products\",\n *         \"columns\"           => [\n *             \"producttype\",\n *             \"product_code\",\n *         ],\n *         \"referencedColumns\" => [\n *             \"type\",\n *             \"code\",\n *         ],\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Db\/Reference.zep",
        "line": 34,
        "char": 5
    },
    {
        "type": "class",
        "name": "Reference",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ReferenceInterface",
                "file": "\/app\/phalcon\/Db\/Reference.zep",
                "line": 35,
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
                    "docblock": "**\n     * Local reference columns\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 41,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 47,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "docblock": "**\n     * Constraint name\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 48,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 54,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "referencedColumns",
                    "docblock": "**\n     * Referenced Columns\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 55,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 61,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "referencedSchema",
                    "docblock": "**\n     * Referenced Schema\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 62,
                            "char": 38
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 68,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "referencedTable",
                    "docblock": "**\n     * Referenced Table\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 69,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 75,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "schemaName",
                    "docblock": "**\n     * Schema name\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 76,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 82,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "onDelete",
                    "docblock": "**\n     * ON DELETE\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 83,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 89,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "onUpdate",
                    "docblock": "**\n     * ON UPDATE\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 90,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 94,
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
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 95,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 95,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 97,
                                    "char": 20
                                },
                                {
                                    "variable": "schema",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 97,
                                    "char": 28
                                },
                                {
                                    "variable": "referencedTable",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 97,
                                    "char": 45
                                },
                                {
                                    "variable": "referencedSchema",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 97,
                                    "char": 63
                                },
                                {
                                    "variable": "referencedColumns",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 98,
                                    "char": 30
                                },
                                {
                                    "variable": "onDelete",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 98,
                                    "char": 40
                                },
                                {
                                    "variable": "onUpdate",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 98,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 100,
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
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 100,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 100,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 102,
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
                                            "value": "referencedTable",
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 102,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 102,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "referencedTable",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 102,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 102,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 102,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 102,
                                    "char": 73
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 102,
                                "char": 73
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
                                                    "value": "Referenced table is required",
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 103,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 103,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 103,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 104,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 106,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "referencedTable",
                                    "expr": {
                                        "type": "variable",
                                        "value": "referencedTable",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 106,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 106,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
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
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 108,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 108,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 108,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 108,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 108,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 108,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
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
                                                    "value": "Foreign key columns are required",
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 109,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 109,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 109,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 110,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 112,
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
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 112,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 112,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 114,
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
                                            "value": "referencedColumns",
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 114,
                                            "char": 77
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 114,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "referencedColumns",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 114,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 114,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 114,
                                        "char": 77
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 114,
                                    "char": 77
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 114,
                                "char": 77
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
                                                    "value": "Referenced columns of the foreign key are required",
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 117,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 117,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 117,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 118,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 120,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "referencedColumns",
                                    "expr": {
                                        "type": "variable",
                                        "value": "referencedColumns",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 120,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 120,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 122,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "schema",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 122,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 122,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "schema",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 122,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 122,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 122,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "schemaName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "schema",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 123,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 123,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 124,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 126,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "referencedSchema",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 126,
                                    "char": 65
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 126,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "referencedSchema",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 126,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 126,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 126,
                                "char": 65
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "referencedSchema",
                                            "expr": {
                                                "type": "variable",
                                                "value": "referencedSchema",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 127,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 127,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 128,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 130,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "onDelete",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 130,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 130,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "onDelete",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 130,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 130,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 130,
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
                                            "property": "onDelete",
                                            "expr": {
                                                "type": "variable",
                                                "value": "onDelete",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 131,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 131,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 132,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 134,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "onUpdate",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 134,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 134,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "onUpdate",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 134,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 134,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 134,
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
                                            "property": "onUpdate",
                                            "expr": {
                                                "type": "variable",
                                                "value": "onUpdate",
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 135,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 135,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 136,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 138,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "columns",
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 138,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 138,
                                                "char": 34
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 138,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "referencedColumns",
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 138,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 138,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 138,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 138,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 138,
                                "char": 64
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
                                                    "value": "Number of columns is not equals than the number of columns referenced",
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 141,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 141,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 141,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Db\\Reference constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                        "line": 96,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 95,
                    "last-line": 147,
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
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 148,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "referencedSchema",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 150,
                                    "char": 29
                                },
                                {
                                    "variable": "referencedTable",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 150,
                                    "char": 46
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 150,
                                    "char": 55
                                },
                                {
                                    "variable": "referencedColumns",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 150,
                                    "char": 74
                                },
                                {
                                    "variable": "constraintName",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 151,
                                    "char": 27
                                },
                                {
                                    "variable": "onDelete",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 151,
                                    "char": 37
                                },
                                {
                                    "variable": "onUpdate",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 151,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 153,
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
                                        "value": "constraintName",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 153,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 153,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "referenceName",
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 153,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 153,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 153,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 153,
                                "char": 55
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
                                                    "value": "constraintName",
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 154,
                                                    "char": 59
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 154,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 154,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 154,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 154,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 154,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 154,
                                        "char": 59
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
                                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                            "line": 155,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 155,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                "line": 155,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 156,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 157,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 159,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "referencedSchema",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 159,
                                    "char": 55
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 159,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "referencedSchema",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 159,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 159,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 159,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 160,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "referencedTable",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 160,
                                    "char": 53
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 160,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "referencedTable",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 160,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 160,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 160,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 161,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "columns",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 161,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 161,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "columns",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 161,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 161,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 161,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 162,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "referencedColumns",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 162,
                                    "char": 57
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 162,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "referencedColumns",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 162,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 162,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 162,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 163,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "onDelete",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 163,
                                    "char": 39
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 163,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "onDelete",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 163,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 163,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 163,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 164,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "onUpdate",
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 164,
                                    "char": 39
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 164,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "onUpdate",
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 164,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 164,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 164,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 166,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Reference",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "constraintName",
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 167,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 167,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "referencedSchema",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 169,
                                                        "char": 33
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "referencedSchema",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 169,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 169,
                                                    "char": 52
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "referencedTable",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 170,
                                                        "char": 32
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "referencedTable",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 170,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 170,
                                                    "char": 51
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "columns",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 171,
                                                        "char": 24
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "columns",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 171,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 171,
                                                    "char": 43
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "referencedColumns",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 172,
                                                        "char": 34
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "referencedColumns",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 172,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 172,
                                                    "char": 53
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "onDelete",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 173,
                                                        "char": 25
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "onDelete",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 173,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 173,
                                                    "char": 44
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "onUpdate",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 174,
                                                        "char": 25
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "onUpdate",
                                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                        "line": 175,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                                    "line": 175,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                                            "line": 176,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                                        "line": 176,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 176,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Reference.zep",
                            "line": 177,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                                    "line": 149,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Reference.zep",
                                "line": 149,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Reference.zep",
                        "line": 149,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Reference.zep",
                    "line": 148,
                    "last-line": 178,
                    "char": 26
                }
            ],
            "file": "\/app\/phalcon\/Db\/Reference.zep",
            "line": 34,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Reference.zep",
        "line": 34,
        "char": 5
    }
]