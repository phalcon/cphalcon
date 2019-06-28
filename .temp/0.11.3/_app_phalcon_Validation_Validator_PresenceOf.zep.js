[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
        "line": 50,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Validates that a value is not null or empty string\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\PresenceOf;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"name\",\n *     new PresenceOf(\n *         [\n *             \"message\" => \"The name is required\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"name\",\n *         \"email\",\n *     ],\n *     new PresenceOf(\n *         [\n *             \"message\" => [\n *                 \"name\"  => \"The name is required\",\n *                 \"email\" => \"The email is required\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
        "line": 51,
        "char": 5
    },
    {
        "type": "class",
        "name": "PresenceOf",
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
                        "value": "Field :field is required",
                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                        "line": 53,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                "line": 58,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
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
                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                    "line": 60,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                "line": 60,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                        "line": 60,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                    "line": 60,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                            "line": 62,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                        "line": 62,
                                        "char": 20
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                        "line": 62,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                    "line": 62,
                                    "char": 28
                                },
                                "right": {
                                    "type": "identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                        "line": 62,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                        "line": 62,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                    "line": 62,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                "line": 62,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                            "line": 63,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                        "line": 64,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                                "line": 64,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                            "line": 64,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                                "line": 64,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                            "line": 64,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                    "line": 65,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                                "line": 65,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                        "line": 65,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                    "line": 67,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                        "line": 67,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                    "line": 68,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                            "line": 70,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                "line": 70,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                                "line": 59,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
                    "line": 58,
                    "last-line": 72,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
            "line": 51,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/PresenceOf.zep",
        "line": 51,
        "char": 5
    }
]