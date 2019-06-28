[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                "line": 14,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
        "line": 49,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Check for alphanumeric character(s)\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Alnum as AlnumValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"username\",\n *     new AlnumValidator(\n *         [\n *             \"message\" => \":field must contain only alphanumeric characters\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"username\",\n *         \"name\",\n *     ],\n *     new AlnumValidator(\n *         [\n *             \"message\" => [\n *                 \"username\" => \"username must contain only alphanumeric characters\",\n *                 \"name\"     => \"name must contain only alphanumeric characters\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
        "line": 50,
        "char": 5
    },
    {
        "type": "class",
        "name": "Alnum",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractValidator",
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
                        "value": "Field :field must contain only letters and numbers",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                        "line": 52,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                    "line": 56,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                "line": 57,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                            "line": 57,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                            "line": 57,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                    "line": 59,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                            "line": 61,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                            "line": 61,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                    "line": 61,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                "line": 61,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                        "line": 61,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                    "line": 61,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                            "line": 63,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "ctype_alnum",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                "line": 63,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                            "line": 63,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                    "line": 63,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                "line": 63,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                            "line": 64,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                        "line": 65,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                                "line": 65,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                            "line": 65,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                                "line": 65,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                            "line": 65,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                    "line": 66,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                                "line": 66,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                        "line": 66,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                    "line": 68,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                        "line": 68,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                    "line": 69,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                            "line": 71,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                "line": 71,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                            "line": 72,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                                "line": 58,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                        "line": 58,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
                    "line": 57,
                    "last-line": 73,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
            "line": 50,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Alnum.zep",
        "line": 50,
        "char": 5
    }
]