[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
        "line": 55,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a value is identical to other\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Identical;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"terms\",\n *     new Identical(\n *         [\n *             \"accepted\" => \"yes\",\n *             \"message\" => \"Terms and conditions must be accepted\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"terms\",\n *         \"anotherTerms\",\n *     ],\n *     new Identical(\n *         [\n *             \"accepted\" => [\n *                 \"terms\"        => \"yes\",\n *                 \"anotherTerms\" => \"yes\",\n *             ],\n *             \"message\" => [\n *                 \"terms\"        => \"Terms and conditions must be accepted\",\n *                 \"anotherTerms\" => \"Another terms  must be accepted\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
        "line": 56,
        "char": 5
    },
    {
        "type": "class",
        "name": "Identical",
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
                        "value": "Field :field does not have the expected value",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                        "line": 58,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                "line": 63,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
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
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
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
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 65,
                                    "char": 18
                                },
                                {
                                    "variable": "accepted",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 65,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                            "line": 66,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "valid",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 66,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                            "line": 68,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 68,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 68,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                "line": 68,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                        "line": 68,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 68,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                            "line": 70,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 70,
                                    "char": 17
                                },
                                "name": "hasOption",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "accepted",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 70,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                        "line": 70,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
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
                                            "variable": "accepted",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 71,
                                                    "char": 33
                                                },
                                                "name": "getOption",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "accepted",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                            "line": 71,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                        "line": 71,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                "line": 71,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 71,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 72,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 72,
                                            "char": 23
                                        },
                                        "name": "hasOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 72,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                "line": 72,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                        "line": 72,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accepted",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                            "line": 73,
                                                            "char": 33
                                                        },
                                                        "name": "getOption",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                                    "line": 73,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                                "line": 73,
                                                                "char": 49
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                        "line": 73,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 73,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 74,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 76,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                            "line": 76,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "accepted",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                "line": 76,
                                "char": 21
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
                                                "value": "accepted",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                "line": 77,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 77,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 77,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                        "line": 77,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accepted",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "accepted",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                            "line": 78,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                            "line": 78,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                        "line": 78,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 78,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 79,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 81,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "valid",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 81,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "accepted",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 81,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                "line": 81,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 81,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                            "line": 84,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "valid",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 84,
                                    "char": 19
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                "line": 84,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                            "line": 85,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                        "line": 86,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                                "line": 86,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                            "line": 86,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                                "line": 86,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                            "line": 86,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                    "line": 87,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                                "line": 87,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                        "line": 87,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 89,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                        "line": 89,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                            "line": 92,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                "line": 92,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                            "line": 93,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                                "line": 64,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
                    "line": 63,
                    "last-line": 94,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
            "line": 56,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Identical.zep",
        "line": 56,
        "char": 5
    }
]