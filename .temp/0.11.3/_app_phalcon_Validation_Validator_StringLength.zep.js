[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                "line": 14,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidatorComposite",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                "line": 15,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\StringLength\\Max",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                "line": 16,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\StringLength\\Min",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                "line": 17,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                "line": 18,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 81,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Validates that a string has the specified maximum and minimum constraints\n * The test is passed if for a string's length L, min<=L<=max, i.e. L must\n * be at least min, and at most max.\n * Since Phalcon v4.0 this valitor works like a container\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\StringLength as StringLength;\n *\n * $validator = new Validation();\n *\n * $validation->add(\n *     \"name_last\",\n *     new StringLength(\n *         [\n *             \"max\"             => 50,\n *             \"min\"             => 2,\n *             \"messageMaximum\"  => \"We don't like really long names\",\n *             \"messageMinimum\"  => \"We want more than just their initials\",\n *             \"includedMaximum\" => true,\n *             \"includedMinimum\" => false,\n *         ]\n *     )\n * );\n *\n * $validation->add(\n *     [\n *         \"name_last\",\n *         \"name_first\",\n *     ],\n *     new StringLength(\n *         [\n *             \"max\" => [\n *                 \"name_last\"  => 50,\n *                 \"name_first\" => 40,\n *             ],\n *             \"min\" => [\n *                 \"name_last\"  => 2,\n *                 \"name_first\" => 4,\n *             ],\n *             \"messageMaximum\" => [\n *                 \"name_last\"  => \"We don't like really long last names\",\n *                 \"name_first\" => \"We don't like really long first names\",\n *             ],\n *             \"messageMinimum\" => [\n *                 \"name_last\"  => \"We don't like too short last names\",\n *                 \"name_first\" => \"We don't like too short first names\",\n *             ],\n *             \"includedMaximum\" => [\n *                 \"name_last\"  => false,\n *                 \"name_first\" => true,\n *             ],\n *             \"includedMinimum\" => [\n *                 \"name_last\"  => false,\n *                 \"name_first\" => true,\n *             ]\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 82,
        "char": 5
    },
    {
        "type": "class",
        "name": "StringLength",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractValidatorComposite",
        "definition": {
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
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                "line": 87,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                            "line": 87,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "included",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                        "line": 89,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                    "line": 89,
                                    "char": 28
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                    "line": 89,
                                    "char": 33
                                },
                                {
                                    "variable": "message",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                        "line": 89,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                    "line": 89,
                                    "char": 49
                                },
                                {
                                    "variable": "validator",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                    "line": 89,
                                    "char": 60
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                    "line": 89,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                            "line": 92,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "options",
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                "line": 92,
                                "char": 35
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strcasecmp",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 93,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 93,
                                                    "char": 30
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "min",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 93,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 93,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 93,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 93,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                        "line": 93,
                                        "char": 43
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
                                                        "value": "options",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 95,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "message",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 95,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 95,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 95,
                                                "char": 43
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "message",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "options",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 96,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "message",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 96,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 96,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 96,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 97,
                                                    "char": 17
                                                }
                                            ],
                                            "elseif_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "options",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 97,
                                                                "char": 39
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "messageMinimum",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 97,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 97,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 97,
                                                        "char": 56
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "message",
                                                                    "expr": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 98,
                                                                            "char": 42
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "messageMinimum",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 98,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 98,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 98,
                                                                    "char": 58
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 99,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 102,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 102,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "options",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 102,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "included",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 102,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 102,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 102,
                                                "char": 44
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
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "options",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 103,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "included",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 103,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 103,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 103,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 104,
                                                    "char": 17
                                                }
                                            ],
                                            "elseif_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "options",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 104,
                                                                "char": 39
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "includedMinimum",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 104,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 104,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 104,
                                                        "char": 57
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
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 105,
                                                                            "char": 43
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "includedMinimum",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 105,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 105,
                                                                        "char": 60
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 105,
                                                                    "char": 60
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 106,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 108,
                                                    "char": 19
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 108,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "validator",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "Min",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array",
                                                                    "left": [
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": "min",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 110,
                                                                                "char": 29
                                                                            },
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "value",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 110,
                                                                                "char": 36
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 110,
                                                                            "char": 36
                                                                        },
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": "message",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 111,
                                                                                "char": 33
                                                                            },
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "message",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 111,
                                                                                "char": 42
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 111,
                                                                            "char": 42
                                                                        },
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": "included",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 112,
                                                                                "char": 34
                                                                            },
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "included",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 113,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 113,
                                                                            "char": 21
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 114,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 114,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 114,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 114,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 116,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 116,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "min",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 116,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 116,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 117,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 117,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 117,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 117,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 118,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 118,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "messageMinimum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 118,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 118,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 119,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 119,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "included",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 119,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 119,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 120,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 120,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "includedMinimum",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 120,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 120,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 121,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 121,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 121,
                                                            "char": 36
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "max",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 121,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 121,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 121,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 121,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 121,
                                                "char": 49
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
                                                                "value": "options",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 123,
                                                                "char": 33
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "message",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 123,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 123,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 123,
                                                        "char": 43
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "message",
                                                                    "expr": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 124,
                                                                            "char": 42
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "message",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 124,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 124,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 124,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 125,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "elseif_statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "isset",
                                                                "left": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "options",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 125,
                                                                        "char": 39
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "messageMaximum",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 125,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 125,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 125,
                                                                "char": 56
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "message",
                                                                            "expr": {
                                                                                "type": "array-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "options",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                    "line": 126,
                                                                                    "char": 42
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "messageMaximum",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                    "line": 126,
                                                                                    "char": 57
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 126,
                                                                                "char": 58
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 126,
                                                                            "char": 58
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 127,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 130,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 130,
                                                    "char": 18
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "options",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 130,
                                                                "char": 33
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "included",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 130,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 130,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 130,
                                                        "char": 44
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
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 131,
                                                                            "char": 43
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "included",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 131,
                                                                            "char": 52
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 131,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 131,
                                                                    "char": 53
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 132,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "elseif_statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "isset",
                                                                "left": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "options",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 132,
                                                                        "char": 39
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "includedMaximum",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 132,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 132,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 132,
                                                                "char": 57
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
                                                                                "type": "array-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "options",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                    "line": 133,
                                                                                    "char": 43
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "includedMaximum",
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                    "line": 133,
                                                                                    "char": 59
                                                                                },
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                "line": 133,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 133,
                                                                            "char": 60
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                    "line": 134,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 136,
                                                            "char": 19
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 136,
                                                    "char": 19
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "validator",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Max",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "max",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                        "line": 138,
                                                                                        "char": 29
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                        "line": 138,
                                                                                        "char": 36
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                    "line": 138,
                                                                                    "char": 36
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                        "line": 139,
                                                                                        "char": 33
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                        "line": 139,
                                                                                        "char": 42
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                    "line": 139,
                                                                                    "char": 42
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                        "line": 140,
                                                                                        "char": 34
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                        "line": 141,
                                                                                        "char": 21
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                                    "line": 141,
                                                                                    "char": 21
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                            "line": 142,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                        "line": 142,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                                "line": 142,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 142,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 144,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 144,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "max",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 144,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 144,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 145,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 145,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 145,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 145,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 146,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 146,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "messageMaximum",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 146,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 146,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 147,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 147,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "included",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 147,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 147,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 148,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 148,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "includedMaximum",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                            "line": 148,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                        "line": 148,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                    "line": 149,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 149,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 151,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                    "line": 153,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "validators",
                                            "expr": {
                                                "type": "variable",
                                                "value": "validator",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                                "line": 153,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 153,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                    "line": 154,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                            "line": 156,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                            "line": 156,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                        "line": 156,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                                "line": 156,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                            "line": 157,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                        "line": 88,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
                    "line": 87,
                    "last-line": 158,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
            "line": 82,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/StringLength.zep",
        "line": 82,
        "char": 5
    }
]