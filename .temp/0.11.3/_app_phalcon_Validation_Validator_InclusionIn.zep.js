[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 56,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Check if a value is included into a list of values\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\InclusionIn;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"status\",\n *     new InclusionIn(\n *         [\n *             \"message\" => \"The status must be A or B\",\n *             \"domain\"  => [\"A\", \"B\"],\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"status\",\n *         \"type\",\n *     ],\n *     new InclusionIn(\n *         [\n *             \"message\" => [\n *                 \"status\" => \"The status must be A or B\",\n *                 \"type\"   => \"The status must be 1 or 2\",\n *             ],\n *             \"domain\" => [\n *                 \"status\" => [\"A\", \"B\"],\n *                 \"type\"   => [1, 2],\n *             ]\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 57,
        "char": 5
    },
    {
        "type": "class",
        "name": "InclusionIn",
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
                        "value": "Field :field must be a part of list: :domain",
                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                        "line": 59,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                "line": 64,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
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
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
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
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 66,
                                    "char": 18
                                },
                                {
                                    "variable": "domain",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 66,
                                    "char": 26
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 66,
                                    "char": 40
                                },
                                {
                                    "variable": "strict",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 66,
                                    "char": 48
                                },
                                {
                                    "variable": "fieldDomain",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 66,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 68,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 68,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 68,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 68,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 73,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "domain",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 73,
                                            "char": 27
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "domain",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 73,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 73,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 73,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 73,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 75,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "fieldDomain",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 75,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 75,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 75,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 75,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                "line": 75,
                                "char": 45
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
                                                "value": "fieldDomain",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 76,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 76,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 76,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 76,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "domain",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "fieldDomain",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                        "line": 77,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 77,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 78,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 79,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 81,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 81,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 81,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 81,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 81,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                "line": 81,
                                "char": 44
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
                                                    "value": "Option 'domain' must be an array",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 82,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 82,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 82,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 83,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 85,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "strict",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 85,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 85,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 87,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 87,
                                    "char": 17
                                },
                                "name": "hasOption",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "strict",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 87,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 87,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                "line": 87,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "strict",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 88,
                                                    "char": 31
                                                },
                                                "name": "getOption",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "strict",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 88,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                        "line": 88,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 88,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 88,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 90,
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
                                                "value": "strict",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 90,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 90,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 90,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 90,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "strict",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "strict",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 91,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 91,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                        "line": 91,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 91,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 92,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 94,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "strict",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 94,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 94,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "boolean",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 94,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 94,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 94,
                                        "char": 50
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
                                                            "value": "Option 'strict' must be a bool",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 95,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                        "line": 95,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 95,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 96,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 97,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 102,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "in_array",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 102,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 102,
                                            "char": 27
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "domain",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 102,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 102,
                                            "char": 35
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "strict",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 102,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 102,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 102,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                "line": 102,
                                "char": 45
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
                                                            "value": ":domain",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 104,
                                                            "char": 24
                                                        },
                                                        "value": {
                                                            "type": "fcall",
                                                            "name": "join",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": ", ",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                                        "line": 104,
                                                                        "char": 33
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                                    "line": 104,
                                                                    "char": 33
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "domain",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                                        "line": 104,
                                                                        "char": 41
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                                    "line": 104,
                                                                    "char": 41
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 105,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                        "line": 105,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 105,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 105,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 107,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                            "line": 107,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                        "line": 108,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                                "line": 108,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 108,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                                "line": 108,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 108,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                                "line": 108,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                            "line": 108,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                    "line": 109,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                                "line": 109,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 109,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 111,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                        "line": 111,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                    "line": 112,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 114,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                "line": 114,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                            "line": 115,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
                    "line": 64,
                    "last-line": 116,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
            "line": 57,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/InclusionIn.zep",
        "line": 57,
        "char": 5
    }
]