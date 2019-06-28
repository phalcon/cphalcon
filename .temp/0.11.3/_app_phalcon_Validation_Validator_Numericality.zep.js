[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
        "line": 50,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Check for a valid numeric value\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Numericality;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"price\",\n *     new Numericality(\n *         [\n *             \"message\" => \":field is not numeric\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"price\",\n *         \"amount\",\n *     ],\n *     new Numericality(\n *         [\n *             \"message\" => [\n *                 \"price\"  => \"price is not numeric\",\n *                 \"amount\" => \"amount is not numeric\",\n *             ]\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
        "line": 51,
        "char": 5
    },
    {
        "type": "class",
        "name": "Numericality",
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
                        "value": "Field :field does not have a valid numeric format",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                        "line": 53,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                "line": 58,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
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
                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
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
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 60,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                            "line": 61,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 61,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                            "line": 64,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                            "line": 64,
                                            "char": 34
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                    "line": 64,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                "line": 64,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                        "line": 64,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 64,
                                    "char": 50
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                            "line": 65,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                        "line": 65,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 65,
                                    "char": 37
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "str_replace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                    "line": 66,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                "line": 66,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                    "line": 66,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                "line": 66,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                    "line": 66,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                "line": 66,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                        "line": 66,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 66,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pattern",
                                    "expr": {
                                        "type": "string",
                                        "value": "\/((^[-]?[0-9,]+(.[0-9]+)?$)|(^[-]?[0-9.]+(,[0-9]+)?$))\/",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                        "line": 67,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 67,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                            "line": 69,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "preg_match",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                "line": 69,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                            "line": 69,
                                            "char": 31
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                "line": 69,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                            "line": 69,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 69,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                "line": 69,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                            "line": 70,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                        "line": 71,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                                "line": 71,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                            "line": 71,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                                "line": 71,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                            "line": 71,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                    "line": 72,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                                "line": 72,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                        "line": 72,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 74,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                        "line": 74,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                    "line": 75,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                            "line": 77,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                "line": 77,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                            "line": 78,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                                "line": 59,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
                    "line": 58,
                    "last-line": 79,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
            "line": 51,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Numericality.zep",
        "line": 51,
        "char": 5
    }
]