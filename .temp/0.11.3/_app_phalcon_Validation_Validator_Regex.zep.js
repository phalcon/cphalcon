[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
        "line": 55,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Allows validate if the value of a field matches a regular expression\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Regex as RegexValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"created_at\",\n *     new RegexValidator(\n *         [\n *             \"pattern\" => \"\/^[0-9]{4}[-\\\/](0[1-9]|1[12])[-\\\/](0[1-9]|[12][0-9]|3[01])$\/\",\n *             \"message\" => \"The creation date is invalid\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"created_at\",\n *         \"name\",\n *     ],\n *     new RegexValidator(\n *         [\n *             \"pattern\" => [\n *                 \"created_at\" => \"\/^[0-9]{4}[-\\\/](0[1-9]|1[12])[-\\\/](0[1-9]|[12][0-9]|3[01])$\/\",\n *                 \"name\"       => \"\/^[a-z]$\/\",\n *             ],\n *             \"message\" => [\n *                 \"created_at\" => \"The creation date is invalid\",\n *                 \"name\"       => \"The name is invalid\",\n *             ]\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
        "line": 56,
        "char": 5
    },
    {
        "type": "class",
        "name": "Regex",
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
                        "value": "Field :field does not match the required format",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                        "line": 58,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                    "line": 62,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                "line": 63,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 63,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 63,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 65,
                                    "char": 20
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 65,
                                    "char": 27
                                },
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 65,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 66,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "failed",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 66,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 70,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "matches",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 70,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 70,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 71,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 71,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                    "line": 71,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                "line": 71,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 71,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 71,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 73,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pattern",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 73,
                                            "char": 28
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "pattern",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                    "line": 73,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                "line": 73,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 73,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 73,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 75,
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
                                        "value": "pattern",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 75,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 75,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 75,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                "line": 75,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "pattern",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "pattern",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                    "line": 76,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                    "line": 76,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                "line": 76,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 76,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 77,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 79,
                            "char": 10
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
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 79,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 79,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 79,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 79,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "matches",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 79,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 79,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                "line": 79,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "failed",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "matches",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                        "line": 80,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                        "line": 80,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                    "line": 80,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                    "line": 80,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                "line": 80,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 80,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 81,
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
                                            "variable": "failed",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                "line": 82,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 82,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 83,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 85,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "failed",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                "line": 85,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                            "line": 86,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                        "line": 87,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                                "line": 87,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                            "line": 87,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                                "line": 87,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                            "line": 87,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                    "line": 88,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                                "line": 88,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 88,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 90,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                        "line": 90,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                    "line": 91,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 93,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                "line": 93,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                            "line": 94,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                                "line": 64,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
                    "line": 63,
                    "last-line": 95,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
            "line": 56,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Regex.zep",
        "line": 56,
        "char": 5
    }
]