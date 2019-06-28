[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator\\StringLength",
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 63,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Validates that a string has the specified minimum constraints\n * The test is passed if for a string's length L, min<=L, i.e. L must\n * be at least min.\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\StringLength\\Min;\n *\n * $validator = new Validation();\n *\n * $validation->add(\n *     \"name_last\",\n *     new Min(\n *         [\n *             \"min\"     => 2,\n *             \"message\" => \"We want more than just their initials\",\n *             \"included\" => true\n *         ]\n *     )\n * );\n *\n * $validation->add(\n *     [\n *         \"name_last\",\n *         \"name_first\",\n *     ],\n *     new Min(\n *         [\n *             \"min\" => [\n *                 \"name_last\"  => 2,\n *                 \"name_first\" => 4,\n *             ],\n *             \"message\" => [\n *                 \"name_last\"  => \"We don't like too short last names\",\n *                 \"name_first\" => \"We don't like too short first names\",\n *             ],\n *             \"included\" => [\n *                 \"name_last\"  => false,\n *                 \"name_first\" => true,\n *             ]\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 64,
        "char": 5
    },
    {
        "type": "class",
        "name": "Min",
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
                        "value": "Field :field must be at least :min characters long",
                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                        "line": 66,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                    "line": 70,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 71,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 71,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 71,
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
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 73,
                                    "char": 18
                                },
                                {
                                    "variable": "length",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 73,
                                    "char": 26
                                },
                                {
                                    "variable": "minimum",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 73,
                                    "char": 35
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 73,
                                    "char": 49
                                },
                                {
                                    "variable": "included",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 73,
                                    "char": 59
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 73,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 75,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 75,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 75,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 75,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 75,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 75,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 78,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strlen",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 78,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 78,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 78,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "length",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "mb_strlen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                            "line": 79,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                        "line": 79,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 79,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 79,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 80,
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
                                            "variable": "length",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strlen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                            "line": 81,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                        "line": 81,
                                                        "char": 38
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 81,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 81,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 84,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "minimum",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 84,
                                            "char": 28
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "min",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 84,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 84,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 84,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 84,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 86,
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
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 86,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 86,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 86,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 86,
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 87,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 87,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 87,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 87,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 88,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 90,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "included",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 90,
                                            "char": 29
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "included",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 90,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 90,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 90,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 90,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 92,
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
                                        "value": "included",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 92,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 92,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 92,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 92,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "included",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "included",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                        "line": 93,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                        "line": 93,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 93,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 93,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 93,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 94,
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
                                            "variable": "included",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "included",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 95,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 95,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 95,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 96,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 98,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "included",
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 98,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "less-equal",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 99,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "minimum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 99,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 99,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 99,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 100,
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
                                            "variable": "result",
                                            "expr": {
                                                "type": "less",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 101,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "minimum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 101,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 101,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 101,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 102,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 104,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 104,
                                "char": 19
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
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                            "line": 106,
                                                            "char": 24
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "minimum",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                            "line": 107,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                        "line": 107,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 107,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 107,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 109,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                            "line": 109,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                        "line": 110,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                                "line": 110,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                            "line": 110,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                                "line": 110,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                            "line": 110,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                                "line": 110,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                            "line": 110,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                    "line": 111,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                                "line": 111,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 111,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 113,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                        "line": 113,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 116,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 116,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                            "line": 117,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                                "line": 72,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
                    "line": 71,
                    "last-line": 118,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
            "line": 64,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength\/Min.zep",
        "line": 64,
        "char": 5
    }
]