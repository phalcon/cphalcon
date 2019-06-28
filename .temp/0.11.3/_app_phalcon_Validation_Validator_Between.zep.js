[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
        "line": 61,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Validates that a value is between an inclusive range of two values.\n * For a value x, the test is passed if minimum<=x<=maximum.\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Between;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"price\",\n *     new Between(\n *         [\n *             \"minimum\" => 0,\n *             \"maximum\" => 100,\n *             \"message\" => \"The price must be between 0 and 100\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"price\",\n *         \"amount\",\n *     ],\n *     new Between(\n *         [\n *             \"minimum\" => [\n *                 \"price\"  => 0,\n *                 \"amount\" => 0,\n *             ],\n *             \"maximum\" => [\n *                 \"price\"  => 100,\n *                 \"amount\" => 50,\n *             ],\n *             \"message\" => [\n *                 \"price\"  => \"The price must be between 0 and 100\",\n *                 \"amount\" => \"The amount must be between 0 and 50\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
        "line": 62,
        "char": 5
    },
    {
        "type": "class",
        "name": "Between",
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
                        "value": "Field :field must be within the range of :min to :max",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                        "line": 64,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                    "line": 68,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                "line": 69,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 69,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 69,
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
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 71,
                                    "char": 18
                                },
                                {
                                    "variable": "minimum",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 71,
                                    "char": 27
                                },
                                {
                                    "variable": "maximum",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 71,
                                    "char": 36
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 71,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 73,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                            "line": 73,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 73,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                "line": 73,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 73,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 73,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "minimum",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                            "line": 74,
                                            "char": 28
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "minimum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 74,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                "line": 74,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 74,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 74,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "maximum",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                            "line": 75,
                                            "char": 28
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "maximum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 75,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                "line": 75,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 75,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 75,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 77,
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
                                        "value": "minimum",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 77,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 77,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 77,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                "line": 77,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "minimum",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "minimum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 78,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 78,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                "line": 78,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                            "line": 78,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 79,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 81,
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
                                        "value": "maximum",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 81,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 81,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 81,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                "line": 81,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "maximum",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "maximum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 82,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 82,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                "line": 82,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                            "line": 82,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 83,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 85,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "less",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 85,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "minimum",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 85,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 85,
                                    "char": 29
                                },
                                "right": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 85,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "maximum",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 85,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 85,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                "line": 85,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "replacePairs",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": ":min",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                            "line": 87,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "minimum",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                            "line": 87,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                        "line": 87,
                                                        "char": 32
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": ":max",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                            "line": 88,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "maximum",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                            "line": 89,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                        "line": 89,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                "line": 89,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                            "line": 89,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 91,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                            "line": 91,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                        "line": 92,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                                "line": 92,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                            "line": 92,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                                "line": 92,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                            "line": 92,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                                "line": 92,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                            "line": 92,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                    "line": 93,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                                "line": 93,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 93,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 95,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                        "line": 95,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                    "line": 96,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                "line": 98,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                            "line": 99,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                                "line": 70,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                        "line": 70,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
                    "line": 69,
                    "last-line": 100,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
            "line": 62,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Between.zep",
        "line": 62,
        "char": 5
    }
]