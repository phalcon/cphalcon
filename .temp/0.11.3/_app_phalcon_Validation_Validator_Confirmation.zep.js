[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                "line": 15,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                "line": 16,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 56,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks that two values have the same value\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Confirmation;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"password\",\n *     new Confirmation(\n *         [\n *             \"message\" => \"Password doesn't match confirmation\",\n *             \"with\"    => \"confirmPassword\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"password\",\n *         \"email\",\n *     ],\n *     new Confirmation(\n *         [\n *             \"message\" => [\n *                 \"password\" => \"Password doesn't match confirmation\",\n *                 \"email\"    => \"Email doesn't match confirmation\",\n *             ],\n *             \"with\" => [\n *                 \"password\" => \"confirmPassword\",\n *                 \"email\"    => \"confirmEmail\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 57,
        "char": 5
    },
    {
        "type": "class",
        "name": "Confirmation",
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
                        "value": "Field :field must be the same as :with",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                        "line": 59,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                    "line": 63,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 64,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 64,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 64,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "fieldWith",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 66,
                                    "char": 22
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 66,
                                    "char": 29
                                },
                                {
                                    "variable": "valueWith",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 66,
                                    "char": 40
                                },
                                {
                                    "variable": "labelWith",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 66,
                                    "char": 51
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 66,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 68,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fieldWith",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 68,
                                            "char": 30
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "with",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 68,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 68,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 68,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 68,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 70,
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
                                        "value": "fieldWith",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 70,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 70,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 70,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 70,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fieldWith",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "fieldWith",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 71,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 71,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 71,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 71,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 72,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 74,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 74,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 74,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 74,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 74,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 74,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "valueWith",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 75,
                                            "char": 36
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fieldWith",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 75,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 75,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 75,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 75,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 77,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 77,
                                        "char": 18
                                    },
                                    "name": "compare",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 77,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 77,
                                            "char": 32
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "valueWith",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 77,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 77,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 77,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 77,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "labelWith",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 78,
                                                    "char": 34
                                                },
                                                "name": "getOption",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "labelWith",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 78,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 78,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 78,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 78,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 80,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "labelWith",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 80,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 80,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 80,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 80,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "labelWith",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "labelWith",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 81,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "fieldWith",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 81,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 81,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 81,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 82,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 84,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "labelWith",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 84,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 84,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "labelWith",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "validation",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 85,
                                                            "char": 44
                                                        },
                                                        "name": "getLabel",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "fieldWith",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                                    "line": 85,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                                "line": 85,
                                                                "char": 63
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 85,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 85,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 86,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 88,
                                    "char": 15
                                },
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
                                                            "value": ":with",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 89,
                                                            "char": 22
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "labelWith",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 90,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 90,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 90,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 90,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 92,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 92,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 93,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                                "line": 93,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 93,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                                "line": 93,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 93,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                                "line": 93,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 93,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                    "line": 94,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 94,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 94,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 96,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 96,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 97,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 99,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 99,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 100,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                    "line": 64,
                    "last-line": 104,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "compare",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "a",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 105,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "b",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 105,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 107,
                                    "char": 17
                                },
                                "name": "getOption",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "ignoreCase",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 107,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 107,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 107,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 107,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 107,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "fcall",
                                                "name": "function_exists",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "mb_strtolower",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 111,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 111,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 111,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 111,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                        "line": 111,
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
                                                            "value": "Extension 'mbstring' is required",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 112,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 112,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 112,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 113,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 115,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "a",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "mb_strtolower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "a",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 115,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 115,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "utf-8",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 115,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 115,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 115,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 115,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 116,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "b",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "mb_strtolower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "b",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 116,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 116,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "utf-8",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                            "line": 116,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                        "line": 116,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                                "line": 116,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                            "line": 116,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 117,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 119,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "a",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 119,
                                    "char": 19
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "b",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                    "line": 119,
                                    "char": 22
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 119,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                            "line": 120,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Compare strings\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                                "line": 106,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                        "line": 106,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
                    "line": 105,
                    "last-line": 121,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
            "line": 57,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Confirmation.zep",
        "line": 57,
        "char": 5
    }
]