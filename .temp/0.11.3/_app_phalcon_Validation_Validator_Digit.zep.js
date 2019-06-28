[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
        "line": 50,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Check for numeric character(s)\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Digit as DigitValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"height\",\n *     new DigitValidator(\n *         [\n *             \"message\" => \":field must be numeric\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"height\",\n *         \"width\",\n *     ],\n *     new DigitValidator(\n *         [\n *             \"message\" => [\n *                 \"height\" => \"height must be numeric\",\n *                 \"width\"  => \"width must be numeric\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
        "line": 51,
        "char": 5
    },
    {
        "type": "class",
        "name": "Digit",
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
                        "value": "Field :field must be numeric",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                        "line": 53,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                "line": 58,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
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
                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
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
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                            "line": 60,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                    "line": 60,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                "line": 60,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                        "line": 60,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                    "line": 60,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                            "line": 62,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "fcall",
                                    "name": "is_int",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                "line": 62,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                            "line": 62,
                                            "char": 24
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                    "line": 62,
                                    "char": 27
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "ctype_digit",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                "line": 62,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                            "line": 62,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                    "line": 62,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                "line": 62,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                        "line": 63,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                    "line": 64,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                            "line": 66,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "validation",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                    "line": 66,
                                    "char": 20
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
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                "line": 67,
                                                "char": 18
                                            },
                                            "name": "messageFactory",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "validation",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                        "line": 67,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                    "line": 67,
                                                    "char": 44
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                        "line": 67,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                                    "line": 67,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                            "line": 68,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                        "line": 68,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                "line": 68,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                            "line": 70,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                "line": 70,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                            "line": 71,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                                "line": 59,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
                    "line": 58,
                    "last-line": 72,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
            "line": 51,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Digit.zep",
        "line": 51,
        "char": 5
    }
]