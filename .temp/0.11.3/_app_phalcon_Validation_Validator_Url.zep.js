[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
        "line": 50,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a value has a url format\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Url as UrlValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"url\",\n *     new UrlValidator(\n *         [\n *             \"message\" => \":field must be a url\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"url\",\n *         \"homepage\",\n *     ],\n *     new UrlValidator(\n *         [\n *             \"message\" => [\n *                 \"url\"      => \"url must be a url\",\n *                 \"homepage\" => \"homepage must be a url\",\n *             ]\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
        "line": 51,
        "char": 5
    },
    {
        "type": "class",
        "name": "Url",
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
                        "value": "Field :field must be a url",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                        "line": 53,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                "line": 58,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
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
                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
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
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 60,
                                    "char": 20
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 60,
                                    "char": 28
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 60,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                    "line": 62,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                "line": 62,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                        "line": 62,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 62,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                            "line": 64,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 64,
                                    "char": 50
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                            "line": 64,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                            "line": 64,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                        "line": 64,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                        "line": 64,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 64,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                "line": 64,
                                "char": 50
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
                                                "type": "fcall",
                                                "name": "filter_var",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                            "line": 65,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                        "line": 65,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "FILTER_VALIDATE_URL",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                            "line": 65,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                        "line": 65,
                                                        "char": 63
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                            "line": 65,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                        "line": 65,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                "line": 65,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                            "line": 65,
                                            "char": 73
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 66,
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
                                                "type": "fcall",
                                                "name": "filter_var",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                            "line": 67,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                        "line": 67,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "FILTER_VALIDATE_URL",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                            "line": 67,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                        "line": 67,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                "line": 67,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                            "line": 67,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 68,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                            "line": 70,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 70,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                "line": 70,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                            "line": 71,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                        "line": 72,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                                "line": 72,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                            "line": 72,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                                "line": 72,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                            "line": 72,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                    "line": 73,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                                "line": 73,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                        "line": 73,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 75,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                        "line": 75,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                            "line": 78,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                "line": 78,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                            "line": 79,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                                "line": 59,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
                    "line": 58,
                    "last-line": 80,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
            "line": 51,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Url.zep",
        "line": 51,
        "char": 5
    }
]