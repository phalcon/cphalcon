[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractCombinedFieldsValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 15,
                "char": 55
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 17,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\CollectionInterface",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 18,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 19,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection",
                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                "line": 20,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 91,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Check that a field is unique in the related table\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Uniqueness as UniquenessValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"username\",\n *     new UniquenessValidator(\n *         [\n *             \"model\"   => new Users(),\n *             \"message\" => \":field must be unique\",\n *         ]\n *     )\n * );\n * ```\n *\n * Different attribute from the field:\n * ```php\n * $validator->add(\n *     \"username\",\n *     new UniquenessValidator(\n *         [\n *             \"model\"     => new Users(),\n *             \"attribute\" => \"nick\",\n *         ]\n *     )\n * );\n * ```\n *\n * In model:\n * ```php\n * $validator->add(\n *     \"username\",\n *     new UniquenessValidator()\n * );\n * ```\n *\n * Combination of fields in model:\n * ```php\n * $validator->add(\n *     [\n *         \"firstName\",\n *         \"lastName\",\n *     ],\n *     new UniquenessValidator()\n * );\n * ```\n *\n * It is possible to convert values before validation. This is useful in\n * situations where values need to be converted to do the database lookup:\n *\n * ```php\n * $validator->add(\n *     \"username\",\n *     new UniquenessValidator(\n *         [\n *             \"convert\" => function (array $values) {\n *                 $values[\"username\"] = strtolower($values[\"username\"]);\n *\n *                 return $values;\n *             }\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 92,
        "char": 5
    },
    {
        "type": "class",
        "name": "Uniqueness",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractCombinedFieldsValidator",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "template",
                    "default": {
                        "type": "string",
                        "value": "Field :field must be unique",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                        "line": 94,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                    "line": 96,
                    "char": 11
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "columnMap",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                        "line": 96,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                    "line": 100,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "validate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "validation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Validation",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 101,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 101,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 101,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 103,
                                        "char": 18
                                    },
                                    "name": "isUniqueness",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "validation",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 103,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 103,
                                            "char": 42
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 103,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 103,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 103,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 103,
                                "char": 51
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 104,
                                            "char": 24
                                        },
                                        "name": "appendMessage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 105,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 105,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 105,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 105,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 105,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 106,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 106,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 106,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 108,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 108,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 109,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 111,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 111,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 112,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Executes the validation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 102,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                        "line": 102,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                    "line": 101,
                    "last-line": 116,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getColumnNameReal",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 117,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 117,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fcall",
                                    "name": "globals_get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "orm.column_renaming",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 120,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 120,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 120,
                                    "char": 46
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 120,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "columnMap",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 120,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 120,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 120,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 120,
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
                                            "property": "columnMap",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 121,
                                                            "char": 42
                                                        },
                                                        "name": "getDI",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 122,
                                                        "char": 18
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "modelsMetadata",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 122,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 122,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 123,
                                                    "char": 18
                                                },
                                                "name": "getColumnMap",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 123,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 123,
                                                        "char": 38
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 123,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 123,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 124,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 126,
                            "char": 10
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
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 126,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "columnMap",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 126,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 126,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 126,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 126,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 126,
                                    "char": 45
                                },
                                "right": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 126,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "columnMap",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 126,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 126,
                                            "char": 68
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 126,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 126,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 126,
                                    "char": 76
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 126,
                                "char": 76
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 127,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "columnMap",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 127,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 127,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 127,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 127,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 128,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 130,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "field",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 130,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 131,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * The column map is used in the case to get real column name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 118,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                        "line": 118,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                    "line": 117,
                    "last-line": 133,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "isUniqueness",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "validation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Validation",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 133,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 133,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 133,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "values",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 135,
                                    "char": 19
                                },
                                {
                                    "variable": "convert",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 135,
                                    "char": 28
                                },
                                {
                                    "variable": "record",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 135,
                                    "char": 36
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 135,
                                    "char": 44
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 135,
                                    "char": 55
                                },
                                {
                                    "variable": "isModel",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 135,
                                    "char": 64
                                },
                                {
                                    "variable": "isDocument",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 135,
                                    "char": 76
                                },
                                {
                                    "variable": "singleField",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 136,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 138,
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
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 138,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 138,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 138,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 138,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "singleField",
                                            "expr": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 139,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 139,
                                            "char": 36
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "field",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 140,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 140,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 142,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "field",
                                            "expr": {
                                                "type": "variable",
                                                "value": "singleField",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 142,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 142,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 143,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 145,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "values",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 145,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 145,
                                    "char": 24
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "convert",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 146,
                                            "char": 28
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "convert",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 146,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 146,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 146,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 146,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 148,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "field",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 148,
                                "char": 34
                            },
                            "value": "singleField",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "values",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "singleField",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 149,
                                                    "char": 35
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 149,
                                                    "char": 50
                                                },
                                                "name": "getValue",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "singleField",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 149,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 149,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 149,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 149,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 150,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 152,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "convert",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 152,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 152,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 152,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "values",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "convert",
                                                "call-type": 2,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "values",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 153,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 153,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 153,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 153,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 155,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "fcall",
                                                "name": "is_array",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "values",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 155,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 155,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 155,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 155,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 155,
                                        "char": 43
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
                                                            "value": "Value conversion must return an array",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 156,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 156,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 156,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 157,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 158,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 160,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "record",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 160,
                                            "char": 27
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 160,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 160,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 160,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 160,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 162,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "record",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 162,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 162,
                                    "char": 26
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "record",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 162,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 162,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 162,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 162,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 162,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "record",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 164,
                                                    "char": 37
                                                },
                                                "name": "getEntity",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 164,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 164,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 166,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "record",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 166,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 166,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 166,
                                        "char": 38
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
                                                            "value": "Model of record must be set to property \\\"model\\\"",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 169,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 169,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 169,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 170,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 171,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 173,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "isModel",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "record",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 173,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "ModelInterface",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 173,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 173,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 173,
                                    "char": 55
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "isDocument",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "record",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 174,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CollectionInterface",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 174,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 174,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 174,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 176,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "isModel",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 176,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 177,
                                                    "char": 31
                                                },
                                                "name": "isUniquenessModel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 177,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 177,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 177,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 177,
                                                        "char": 63
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "values",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 177,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 177,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 177,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 177,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 178,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "isDocument",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 178,
                                        "char": 29
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 179,
                                                            "char": 31
                                                        },
                                                        "name": "isUniquenessCollection",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "record",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 179,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 179,
                                                                "char": 61
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "field",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 179,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 179,
                                                                "char": 68
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "values",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 179,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 179,
                                                                "char": 76
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 179,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 179,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 180,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 180,
                                    "char": 14
                                }
                            ],
                            "else_statements": [
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
                                                    "value": "The uniqueness validator works only with Phalcon\\\\Mvc\\\\Model or Phalcon\\\\Mvc\\\\Collection",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 183,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 183,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 183,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 184,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 186,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "record",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 186,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 186,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 186,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 186,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 188,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "scall",
                                    "dynamic-class": 1,
                                    "class": "className",
                                    "dynamic": 0,
                                    "name": "count",
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 188,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 188,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 188,
                                    "char": 44
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 188,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 188,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 189,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                    "line": 133,
                    "last-line": 193,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "isUniquenessCollection",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 194,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 194,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 194,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "exceptConditions",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 196,
                                    "char": 29
                                },
                                {
                                    "variable": "fieldExcept",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 196,
                                    "char": 42
                                },
                                {
                                    "variable": "notInValues",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 196,
                                    "char": 55
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 196,
                                    "char": 62
                                },
                                {
                                    "variable": "singleField",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 196,
                                    "char": 75
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 197,
                                    "char": 19
                                },
                                {
                                    "variable": "except",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 197,
                                    "char": 27
                                },
                                {
                                    "variable": "singleExcept",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 197,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 199,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "exceptConditions",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 199,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 199,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 200,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 201,
                                                    "char": 24
                                                },
                                                "value": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 202,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 202,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 202,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 202,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 204,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "field",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 204,
                                "char": 34
                            },
                            "value": "singleField",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fieldExcept",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 205,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 205,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 206,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "notInValues",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 206,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 206,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 207,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "values",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 207,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "singleField",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 207,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 207,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 207,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 209,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "except",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 209,
                                                    "char": 31
                                                },
                                                "name": "getOption",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "except",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 209,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 209,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 209,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 209,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 211,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 211,
                                                    "char": 34
                                                },
                                                {
                                                    "type": "variable",
                                                    "value": "singleField",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 211,
                                                    "char": 47
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 211,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 211,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 213,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "except",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 213,
                                        "char": 23
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
                                                            "type": "variable",
                                                            "value": "except",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 214,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 214,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 214,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 214,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "greater",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "count",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "field",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 214,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 214,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 214,
                                                        "char": 59
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 214,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 214,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 214,
                                                "char": 63
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "except",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 215,
                                                                "char": 36
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "singleField",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 215,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 215,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 215,
                                                        "char": 50
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "fieldExcept",
                                                                    "expr": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "except",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 216,
                                                                            "char": 49
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "singleField",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 216,
                                                                            "char": 61
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 216,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 216,
                                                                    "char": 62
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 217,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 218,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 220,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "fieldExcept",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 220,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 220,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 220,
                                                "char": 40
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
                                                                "value": "fieldExcept",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 221,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 221,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 221,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 221,
                                                        "char": 52
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "for",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "fieldExcept",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 222,
                                                                "char": 57
                                                            },
                                                            "value": "singleExcept",
                                                            "reverse": 0,
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable-append",
                                                                            "operator": "assign",
                                                                            "variable": "notInValues",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "singleExcept",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 223,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 223,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 224,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 226,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "exceptConditions",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "singleField",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 226,
                                                                            "char": 57
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "array",
                                                                        "left": [
                                                                            {
                                                                                "key": {
                                                                                    "type": "string",
                                                                                    "value": "$nin",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 227,
                                                                                    "char": 33
                                                                                },
                                                                                "value": {
                                                                                    "type": "variable",
                                                                                    "value": "notInValues",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 228,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 228,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 228,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 228,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 229,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "exceptConditions",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "singleField",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 230,
                                                                            "char": 57
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "array",
                                                                        "left": [
                                                                            {
                                                                                "key": {
                                                                                    "type": "string",
                                                                                    "value": "$ne",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 231,
                                                                                    "char": 32
                                                                                },
                                                                                "value": {
                                                                                    "type": "variable",
                                                                                    "value": "fieldExcept",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 232,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 232,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 232,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 232,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 233,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 234,
                                                    "char": 17
                                                }
                                            ],
                                            "elseif_statements": [
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
                                                                    "value": "except",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 234,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 234,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "array",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 234,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 234,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "fcall",
                                                                "name": "count",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "field",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 234,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 234,
                                                                        "char": 63
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 234,
                                                                "char": 66
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 234,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 234,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 234,
                                                        "char": 70
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "for",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "except",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 235,
                                                                "char": 48
                                                            },
                                                            "value": "singleExcept",
                                                            "reverse": 0,
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable-append",
                                                                            "operator": "assign",
                                                                            "variable": "notInValues",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "singleExcept",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 236,
                                                                                "char": 57
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 236,
                                                                            "char": 57
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 237,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 239,
                                                            "char": 23
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "params",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "string",
                                                                            "value": "conditions",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 239,
                                                                            "char": 42
                                                                        },
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "singleField",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 239,
                                                                            "char": 55
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "array",
                                                                        "left": [
                                                                            {
                                                                                "key": {
                                                                                    "type": "string",
                                                                                    "value": "$nin",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 240,
                                                                                    "char": 29
                                                                                },
                                                                                "value": {
                                                                                    "type": "variable",
                                                                                    "value": "notInValues",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 241,
                                                                                    "char": 21
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 241,
                                                                                "char": 21
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 241,
                                                                        "char": 22
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 241,
                                                                    "char": 22
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 242,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 242,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "count",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "field",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 242,
                                                                        "char": 37
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 242,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 242,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 242,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 242,
                                                        "char": 44
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "params",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "string",
                                                                            "value": "conditions",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 243,
                                                                            "char": 42
                                                                        },
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "singleField",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 243,
                                                                            "char": 55
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "array",
                                                                        "left": [
                                                                            {
                                                                                "key": {
                                                                                    "type": "string",
                                                                                    "value": "$ne",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 244,
                                                                                    "char": 28
                                                                                },
                                                                                "value": {
                                                                                    "type": "variable",
                                                                                    "value": "except",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 245,
                                                                                    "char": 21
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 245,
                                                                                "char": 21
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 245,
                                                                        "char": 22
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 245,
                                                                    "char": 22
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 246,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 247,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 247,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 248,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 250,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "record",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 250,
                                        "char": 19
                                    },
                                    "name": "getDirtyState",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 250,
                                    "char": 37
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "Collection",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 250,
                                        "char": 74
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "DIRTY_STATE_PERSISTENT",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 250,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 250,
                                    "char": 74
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 250,
                                "char": 74
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 251,
                                                    "char": 34
                                                },
                                                {
                                                    "type": "string",
                                                    "value": "_id",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 251,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "$ne",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 252,
                                                            "char": 20
                                                        },
                                                        "value": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "record",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 252,
                                                                "char": 29
                                                            },
                                                            "name": "getId",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 253,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 253,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 253,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 253,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 254,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 256,
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
                                        "value": "exceptConditions",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 256,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 256,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 256,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 257,
                                                    "char": 34
                                                },
                                                {
                                                    "type": "string",
                                                    "value": "$or",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 257,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "exceptConditions",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 257,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 257,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 257,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 257,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 258,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 260,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "params",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 260,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 261,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Uniqueness method used for collection\n     *",
                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                    "line": 194,
                    "last-line": 265,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "isUniquenessModel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 266,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 266,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 266,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "index",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 268,
                                    "char": 18
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 268,
                                    "char": 26
                                },
                                {
                                    "variable": "attribute",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 268,
                                    "char": 37
                                },
                                {
                                    "variable": "metaData",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 268,
                                    "char": 47
                                },
                                {
                                    "variable": "primaryField",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 268,
                                    "char": 61
                                },
                                {
                                    "variable": "singleField",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 268,
                                    "char": 74
                                },
                                {
                                    "variable": "fieldExcept",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 269,
                                    "char": 24
                                },
                                {
                                    "variable": "singleExcept",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 269,
                                    "char": 38
                                },
                                {
                                    "variable": "notInValues",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 269,
                                    "char": 51
                                },
                                {
                                    "variable": "exceptConditions",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 269,
                                    "char": 69
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 269,
                                    "char": 76
                                },
                                {
                                    "variable": "except",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 270,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 272,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "exceptConditions",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 272,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 272,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "index",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 273,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 273,
                                    "char": 23
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 275,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 275,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 275,
                                                "char": 31
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "bind",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 276,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 277,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 277,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 277,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 277,
                                    "char": 14
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "except",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 278,
                                            "char": 27
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "except",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 278,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 278,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 278,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 278,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 280,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "field",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 280,
                                "char": 34
                            },
                            "value": "singleField",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fieldExcept",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 281,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 281,
                                            "char": 35
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "notInValues",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 282,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 282,
                                            "char": 33
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "values",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 283,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "singleField",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 283,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 283,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 283,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 285,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "attribute",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 285,
                                                    "char": 34
                                                },
                                                "name": "getOption",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "attribute",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 285,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 285,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "singleField",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 285,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 285,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 285,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 285,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 286,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "attribute",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 286,
                                                    "char": 34
                                                },
                                                "name": "getColumnNameReal",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 286,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 286,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "attribute",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 286,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 286,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 286,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 286,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 288,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 288,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 288,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 288,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index-append",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "conditions",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 289,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "attribute",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 289,
                                                                "char": 54
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": " = ?",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 289,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 289,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "index",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 289,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 289,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 289,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 290,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index-append",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "bind",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 290,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 290,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 290,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 291,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "incr",
                                                    "variable": "index",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 291,
                                                    "char": 28
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 292,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index-append",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "conditions",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 293,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "attribute",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 293,
                                                            "char": 54
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": " IS NULL",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 293,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 293,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 293,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 294,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 296,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "except",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 296,
                                        "char": 23
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
                                                            "type": "variable",
                                                            "value": "except",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 297,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 297,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 297,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 297,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "not-identical",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "array_keys",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "except",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 297,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 297,
                                                                "char": 63
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 297,
                                                        "char": 67
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "range",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 297,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 297,
                                                                "char": 76
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "sub",
                                                                    "left": {
                                                                        "type": "fcall",
                                                                        "name": "count",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "except",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 297,
                                                                                    "char": 90
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 297,
                                                                                "char": 90
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 297,
                                                                        "char": 92
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 297,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 297,
                                                                    "char": 95
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 297,
                                                                "char": 95
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 297,
                                                        "char": 97
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 297,
                                                    "char": 97
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 297,
                                                "char": 97
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "except",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 298,
                                                        "char": 60
                                                    },
                                                    "key": "singleField",
                                                    "value": "fieldExcept",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "attribute",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 299,
                                                                            "char": 46
                                                                        },
                                                                        "name": "getColumnNameReal",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "record",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 300,
                                                                                    "char": 35
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 300,
                                                                                "char": 35
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 301,
                                                                                        "char": 34
                                                                                    },
                                                                                    "name": "getOption",
                                                                                    "call-type": 1,
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "string",
                                                                                                "value": "attribute",
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 301,
                                                                                                "char": 54
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 301,
                                                                                            "char": 54
                                                                                        },
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "variable",
                                                                                                "value": "singleField",
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 301,
                                                                                                "char": 67
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 301,
                                                                                            "char": 67
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 302,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 302,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 302,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 302,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 304,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "typeof",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "fieldExcept",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 304,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 304,
                                                                    "char": 48
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "array",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 304,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 304,
                                                                "char": 56
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "for",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "fieldExcept",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 305,
                                                                        "char": 61
                                                                    },
                                                                    "value": "singleExcept",
                                                                    "reverse": 0,
                                                                    "statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "variable-append",
                                                                                    "operator": "assign",
                                                                                    "variable": "notInValues",
                                                                                    "expr": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "string",
                                                                                            "value": "?",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 306,
                                                                                            "char": 55
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "index",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 306,
                                                                                            "char": 62
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 306,
                                                                                        "char": 62
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 306,
                                                                                    "char": 62
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 307,
                                                                            "char": 35
                                                                        },
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "array-index-append",
                                                                                    "operator": "assign",
                                                                                    "variable": "params",
                                                                                    "index-expr": [
                                                                                        {
                                                                                            "type": "string",
                                                                                            "value": "bind",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 307,
                                                                                            "char": 48
                                                                                        }
                                                                                    ],
                                                                                    "expr": {
                                                                                        "type": "variable",
                                                                                        "value": "singleExcept",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 307,
                                                                                        "char": 66
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 307,
                                                                                    "char": 66
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 308,
                                                                            "char": 35
                                                                        },
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "incr",
                                                                                    "variable": "index",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 308,
                                                                                    "char": 44
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 309,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 311,
                                                                    "char": 31
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable-append",
                                                                            "operator": "assign",
                                                                            "variable": "exceptConditions",
                                                                            "expr": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "attribute",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 311,
                                                                                            "char": 64
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "string",
                                                                                            "value": " NOT IN (",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 311,
                                                                                            "char": 76
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 311,
                                                                                        "char": 76
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "fcall",
                                                                                        "name": "join",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": ",",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 311,
                                                                                                    "char": 84
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 311,
                                                                                                "char": 84
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "variable",
                                                                                                    "value": "notInValues",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 311,
                                                                                                    "char": 97
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 311,
                                                                                                "char": 97
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 311,
                                                                                        "char": 99
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 311,
                                                                                    "char": 99
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": ")",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 311,
                                                                                    "char": 102
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 311,
                                                                                "char": 102
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 311,
                                                                            "char": 102
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 312,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable-append",
                                                                            "operator": "assign",
                                                                            "variable": "exceptConditions",
                                                                            "expr": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "attribute",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 313,
                                                                                        "char": 64
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": " <> ?",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 313,
                                                                                        "char": 72
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 313,
                                                                                    "char": 72
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "index",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 313,
                                                                                    "char": 79
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 313,
                                                                                "char": 79
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 313,
                                                                            "char": 79
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 314,
                                                                    "char": 31
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "array-index-append",
                                                                            "operator": "assign",
                                                                            "variable": "params",
                                                                            "index-expr": [
                                                                                {
                                                                                    "type": "string",
                                                                                    "value": "bind",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 314,
                                                                                    "char": 44
                                                                                }
                                                                            ],
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "fieldExcept",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 314,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 314,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 315,
                                                                    "char": 31
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "incr",
                                                                            "variable": "index",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 315,
                                                                            "char": 40
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 316,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 317,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 318,
                                                    "char": 17
                                                }
                                            ],
                                            "elseif_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "count",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "field",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 318,
                                                                        "char": 37
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 318,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 318,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 318,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 318,
                                                        "char": 44
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "attribute",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 319,
                                                                            "char": 42
                                                                        },
                                                                        "name": "getColumnNameReal",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "record",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 320,
                                                                                    "char": 31
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 320,
                                                                                "char": 31
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 321,
                                                                                        "char": 30
                                                                                    },
                                                                                    "name": "getOption",
                                                                                    "call-type": 1,
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "string",
                                                                                                "value": "attribute",
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 321,
                                                                                                "char": 50
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 321,
                                                                                            "char": 50
                                                                                        },
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "array-access",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "field",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 321,
                                                                                                    "char": 57
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "int",
                                                                                                    "value": "0",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 321,
                                                                                                    "char": 59
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 321,
                                                                                                "char": 60
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 321,
                                                                                            "char": 60
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 322,
                                                                                    "char": 21
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 322,
                                                                                "char": 21
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 322,
                                                                        "char": 22
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 322,
                                                                    "char": 22
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 324,
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
                                                                        "value": "except",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 324,
                                                                        "char": 39
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 324,
                                                                    "char": 39
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "array",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 324,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 324,
                                                                "char": 47
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "for",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "except",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 325,
                                                                        "char": 52
                                                                    },
                                                                    "value": "singleExcept",
                                                                    "reverse": 0,
                                                                    "statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "variable-append",
                                                                                    "operator": "assign",
                                                                                    "variable": "notInValues",
                                                                                    "expr": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "string",
                                                                                            "value": "?",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 326,
                                                                                            "char": 51
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "index",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 326,
                                                                                            "char": 58
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 326,
                                                                                        "char": 58
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 326,
                                                                                    "char": 58
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 327,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "array-index-append",
                                                                                    "operator": "assign",
                                                                                    "variable": "params",
                                                                                    "index-expr": [
                                                                                        {
                                                                                            "type": "string",
                                                                                            "value": "bind",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 327,
                                                                                            "char": 44
                                                                                        }
                                                                                    ],
                                                                                    "expr": {
                                                                                        "type": "variable",
                                                                                        "value": "singleExcept",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 327,
                                                                                        "char": 62
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 327,
                                                                                    "char": 62
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 328,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "incr",
                                                                                    "variable": "index",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 328,
                                                                                    "char": 40
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 329,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 331,
                                                                    "char": 27
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable-append",
                                                                            "operator": "assign",
                                                                            "variable": "exceptConditions",
                                                                            "expr": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "attribute",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 331,
                                                                                            "char": 60
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "string",
                                                                                            "value": " NOT IN (",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 331,
                                                                                            "char": 72
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 331,
                                                                                        "char": 72
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "fcall",
                                                                                        "name": "join",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "string",
                                                                                                    "value": ",",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 331,
                                                                                                    "char": 80
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 331,
                                                                                                "char": 80
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "variable",
                                                                                                    "value": "notInValues",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 331,
                                                                                                    "char": 93
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 331,
                                                                                                "char": 93
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 331,
                                                                                        "char": 95
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 331,
                                                                                    "char": 95
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": ")",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 331,
                                                                                    "char": 98
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 331,
                                                                                "char": 98
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 331,
                                                                            "char": 98
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 332,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "else_statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "array-index-append",
                                                                            "operator": "assign",
                                                                            "variable": "params",
                                                                            "index-expr": [
                                                                                {
                                                                                    "type": "string",
                                                                                    "value": "conditions",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 333,
                                                                                    "char": 46
                                                                                }
                                                                            ],
                                                                            "expr": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "attribute",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 333,
                                                                                        "char": 62
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": " <> ?",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 333,
                                                                                        "char": 70
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 333,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "index",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 333,
                                                                                    "char": 77
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 333,
                                                                                "char": 77
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 333,
                                                                            "char": 77
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 334,
                                                                    "char": 27
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "array-index-append",
                                                                            "operator": "assign",
                                                                            "variable": "params",
                                                                            "index-expr": [
                                                                                {
                                                                                    "type": "string",
                                                                                    "value": "bind",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 334,
                                                                                    "char": 40
                                                                                }
                                                                            ],
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "except",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 334,
                                                                                "char": 52
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 334,
                                                                            "char": 52
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 335,
                                                                    "char": 27
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "incr",
                                                                            "variable": "index",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 335,
                                                                            "char": 36
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 336,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 337,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 337,
                                                    "char": 24
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
                                                                        "value": "field",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 337,
                                                                        "char": 37
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 337,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 337,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 337,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 337,
                                                        "char": 43
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "for",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 338,
                                                                "char": 46
                                                            },
                                                            "value": "singleField",
                                                            "reverse": 0,
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "attribute",
                                                                            "expr": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 339,
                                                                                    "char": 46
                                                                                },
                                                                                "name": "getColumnNameReal",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "record",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 340,
                                                                                            "char": 35
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 340,
                                                                                        "char": 35
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "mcall",
                                                                                            "variable": {
                                                                                                "type": "variable",
                                                                                                "value": "this",
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 341,
                                                                                                "char": 34
                                                                                            },
                                                                                            "name": "getOption",
                                                                                            "call-type": 1,
                                                                                            "parameters": [
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "string",
                                                                                                        "value": "attribute",
                                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                        "line": 341,
                                                                                                        "char": 54
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 341,
                                                                                                    "char": 54
                                                                                                },
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "variable",
                                                                                                        "value": "singleField",
                                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                        "line": 341,
                                                                                                        "char": 67
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 341,
                                                                                                    "char": 67
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 342,
                                                                                            "char": 25
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 342,
                                                                                        "char": 25
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 342,
                                                                                "char": 26
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 342,
                                                                            "char": 26
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 344,
                                                                    "char": 26
                                                                },
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "equals",
                                                                        "left": {
                                                                            "type": "typeof",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "except",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 344,
                                                                                "char": 43
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 344,
                                                                            "char": 43
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "array",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 344,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 344,
                                                                        "char": 51
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "for",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "except",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 345,
                                                                                "char": 56
                                                                            },
                                                                            "value": "singleExcept",
                                                                            "reverse": 0,
                                                                            "statements": [
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "variable-append",
                                                                                            "operator": "assign",
                                                                                            "variable": "notInValues",
                                                                                            "expr": {
                                                                                                "type": "concat",
                                                                                                "left": {
                                                                                                    "type": "string",
                                                                                                    "value": "?",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 346,
                                                                                                    "char": 55
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "variable",
                                                                                                    "value": "index",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 346,
                                                                                                    "char": 62
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 346,
                                                                                                "char": 62
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 346,
                                                                                            "char": 62
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 347,
                                                                                    "char": 35
                                                                                },
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "array-index-append",
                                                                                            "operator": "assign",
                                                                                            "variable": "params",
                                                                                            "index-expr": [
                                                                                                {
                                                                                                    "type": "string",
                                                                                                    "value": "bind",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 347,
                                                                                                    "char": 48
                                                                                                }
                                                                                            ],
                                                                                            "expr": {
                                                                                                "type": "variable",
                                                                                                "value": "singleExcept",
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 347,
                                                                                                "char": 66
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 347,
                                                                                            "char": 66
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 348,
                                                                                    "char": 35
                                                                                },
                                                                                {
                                                                                    "type": "let",
                                                                                    "assignments": [
                                                                                        {
                                                                                            "assign-type": "incr",
                                                                                            "variable": "index",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 348,
                                                                                            "char": 44
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 349,
                                                                                    "char": 29
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 351,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "variable-append",
                                                                                    "operator": "assign",
                                                                                    "variable": "exceptConditions",
                                                                                    "expr": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "concat",
                                                                                            "left": {
                                                                                                "type": "concat",
                                                                                                "left": {
                                                                                                    "type": "variable",
                                                                                                    "value": "attribute",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 351,
                                                                                                    "char": 64
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "string",
                                                                                                    "value": " NOT IN (",
                                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                    "line": 351,
                                                                                                    "char": 76
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 351,
                                                                                                "char": 76
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "fcall",
                                                                                                "name": "join",
                                                                                                "call-type": 1,
                                                                                                "parameters": [
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "string",
                                                                                                            "value": ",",
                                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                            "line": 351,
                                                                                                            "char": 84
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                        "line": 351,
                                                                                                        "char": 84
                                                                                                    },
                                                                                                    {
                                                                                                        "parameter": {
                                                                                                            "type": "variable",
                                                                                                            "value": "notInValues",
                                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                            "line": 351,
                                                                                                            "char": 97
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                        "line": 351,
                                                                                                        "char": 97
                                                                                                    }
                                                                                                ],
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 351,
                                                                                                "char": 99
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 351,
                                                                                            "char": 99
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "string",
                                                                                            "value": ")",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 351,
                                                                                            "char": 102
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 351,
                                                                                        "char": 102
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 351,
                                                                                    "char": 102
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 352,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "else_statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "array-index-append",
                                                                                    "operator": "assign",
                                                                                    "variable": "params",
                                                                                    "index-expr": [
                                                                                        {
                                                                                            "type": "string",
                                                                                            "value": "conditions",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 353,
                                                                                            "char": 50
                                                                                        }
                                                                                    ],
                                                                                    "expr": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "concat",
                                                                                            "left": {
                                                                                                "type": "variable",
                                                                                                "value": "attribute",
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 353,
                                                                                                "char": 66
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "string",
                                                                                                "value": " <> ?",
                                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                                "line": 353,
                                                                                                "char": 74
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 353,
                                                                                            "char": 74
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "index",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 353,
                                                                                            "char": 81
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 353,
                                                                                        "char": 81
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 353,
                                                                                    "char": 81
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 354,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "array-index-append",
                                                                                    "operator": "assign",
                                                                                    "variable": "params",
                                                                                    "index-expr": [
                                                                                        {
                                                                                            "type": "string",
                                                                                            "value": "bind",
                                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                            "line": 354,
                                                                                            "char": 44
                                                                                        }
                                                                                    ],
                                                                                    "expr": {
                                                                                        "type": "variable",
                                                                                        "value": "except",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                        "line": 354,
                                                                                        "char": 56
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 354,
                                                                                    "char": 56
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 355,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "incr",
                                                                                    "variable": "index",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                    "line": 355,
                                                                                    "char": 40
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 356,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 357,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 358,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 359,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 359,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 360,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 365,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "record",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 365,
                                        "char": 19
                                    },
                                    "name": "getDirtyState",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 365,
                                    "char": 37
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "Model",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 365,
                                        "char": 69
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "DIRTY_STATE_PERSISTENT",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 365,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 365,
                                    "char": 69
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 365,
                                "char": 69
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "metaData",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "record",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 366,
                                                        "char": 35
                                                    },
                                                    "name": "getDI",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 366,
                                                    "char": 44
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "modelsMetadata",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 366,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 366,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 366,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 366,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 368,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "metaData",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 368,
                                            "char": 42
                                        },
                                        "name": "getPrimaryKeyAttributes",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "record",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 368,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 368,
                                                "char": 73
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 368,
                                        "char": 75
                                    },
                                    "value": "primaryField",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index-append",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "conditions",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 369,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 369,
                                                                    "char": 49
                                                                },
                                                                "name": "getColumnNameReal",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "record",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 369,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 369,
                                                                        "char": 74
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "primaryField",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 369,
                                                                            "char": 88
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 369,
                                                                        "char": 88
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 369,
                                                                "char": 90
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": " <> ?",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 369,
                                                                "char": 98
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 369,
                                                            "char": 98
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "index",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 369,
                                                            "char": 105
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 369,
                                                        "char": 105
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 369,
                                                    "char": 105
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 371,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index-append",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "bind",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 371,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                            "line": 371,
                                                            "char": 45
                                                        },
                                                        "name": "readAttribute",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                        "line": 372,
                                                                        "char": 26
                                                                    },
                                                                    "name": "getColumnNameReal",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "record",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 372,
                                                                                "char": 51
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 372,
                                                                            "char": 51
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "primaryField",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                                "line": 372,
                                                                                "char": 65
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                            "line": 372,
                                                                            "char": 65
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 373,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 373,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 373,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 373,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 375,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "incr",
                                                    "variable": "index",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 375,
                                                    "char": 28
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 376,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 377,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 379,
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
                                        "value": "exceptConditions",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 379,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 379,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 379,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index-append",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 380,
                                                    "char": 34
                                                }
                                            ],
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "(",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 380,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "join",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": " OR ",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 380,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 380,
                                                                "char": 53
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "exceptConditions",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                    "line": 380,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                                "line": 380,
                                                                "char": 71
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 380,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 380,
                                                    "char": 73
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 380,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 380,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 380,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 381,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 383,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "params",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "conditions",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                            "line": 383,
                                            "char": 30
                                        }
                                    ],
                                    "expr": {
                                        "type": "fcall",
                                        "name": "join",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": " AND ",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 384,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 384,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "params",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 385,
                                                        "char": 19
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "conditions",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                        "line": 385,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                    "line": 386,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                                "line": 386,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                        "line": 386,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                    "line": 386,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 388,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "params",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                                "line": 388,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                            "line": 389,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Uniqueness method used for model\n     *",
                    "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
                    "line": 266,
                    "last-line": 390,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
            "line": 92,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Uniqueness.zep",
        "line": 92,
        "char": 5
    }
]