[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
        "line": 50,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a value has a valid credit card number\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\CreditCard as CreditCardValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"creditCard\",\n *     new CreditCardValidator(\n *         [\n *             \"message\" => \"The credit card number is not valid\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"creditCard\",\n *         \"secondCreditCard\",\n *     ],\n *     new CreditCardValidator(\n *         [\n *             \"message\" => [\n *                 \"creditCard\"       => \"The credit card number is not valid\",\n *                 \"secondCreditCard\" => \"The second credit card number is not valid\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
        "line": 51,
        "char": 5
    },
    {
        "type": "class",
        "name": "CreditCard",
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
                        "value": "Field :field is not valid for a credit card number",
                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                        "line": 53,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                    "line": 57,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                "line": 58,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 58,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 58,
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
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 60,
                                    "char": 18
                                },
                                {
                                    "variable": "valid",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 60,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 62,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                            "line": 62,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                    "line": 62,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                "line": 62,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 62,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 62,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 64,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "valid",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                            "line": 64,
                                            "char": 26
                                        },
                                        "name": "verifyByLuhnAlgorithm",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                    "line": 64,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                "line": 64,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 64,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 64,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 66,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "valid",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 66,
                                    "char": 19
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                "line": 66,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                            "line": 67,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                        "line": 68,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                                "line": 68,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                            "line": 68,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                                "line": 68,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                            "line": 68,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                    "line": 69,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                "line": 69,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 69,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 71,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 71,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 72,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 74,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                "line": 74,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 75,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                "line": 59,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                    "line": 58,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "verifyByLuhnAlgorithm",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "number",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 81,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "digit",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 83,
                                    "char": 18
                                },
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 83,
                                    "char": 28
                                },
                                {
                                    "variable": "hash",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 83,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 83,
                                    "char": 37
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 83,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 84,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "digits",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 84,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 86,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "digits",
                                    "expr": {
                                        "type": "cast",
                                        "left": "array",
                                        "right": {
                                            "type": "fcall",
                                            "name": "str_split",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "number",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                        "line": 86,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                    "line": 86,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                            "line": 86,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 86,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 86,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 88,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "digits",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 88,
                                    "char": 39
                                },
                                "name": "reversed",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                "line": 88,
                                "char": 51
                            },
                            "key": "position",
                            "value": "digit",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "hash",
                                            "expr": {
                                                "type": "list",
                                                "left": {
                                                    "type": "ternary",
                                                    "left": {
                                                        "type": "mod",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "position",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                            "line": 89,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "2",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                            "line": 89,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                        "line": 89,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "mul",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "digit",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                            "line": 89,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "2",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                            "line": 89,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                        "line": 89,
                                                        "char": 50
                                                    },
                                                    "extra": {
                                                        "type": "variable",
                                                        "value": "digit",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                        "line": 89,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                    "line": 89,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                "line": 89,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                            "line": 89,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 92,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_sum",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "str_split",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "hash",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                                "line": 93,
                                                                "char": 27
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                            "line": 93,
                                                            "char": 27
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                    "line": 94,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                                "line": 94,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 94,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 94,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 96,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "mod",
                                        "left": {
                                            "type": "variable",
                                            "value": "result",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                            "line": 96,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "10",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                            "line": 96,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 96,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                        "line": 96,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                    "line": 96,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                "line": 96,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                            "line": 97,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * is a simple checksum formula used to validate a variety of identification\n     * numbers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                                "line": 82,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                        "line": 82,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
                    "line": 81,
                    "last-line": 98,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
            "line": 51,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/CreditCard.zep",
        "line": 51,
        "char": 5
    }
]