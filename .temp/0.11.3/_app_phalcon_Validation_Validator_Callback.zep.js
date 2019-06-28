[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
        "line": 60,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Calls user function for validation\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\Callback as CallbackValidator;\n * use Phalcon\\Validation\\Validator\\Numericality as NumericalityValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     [\"user\", \"admin\"],\n *     new CallbackValidator(\n *         [\n *             \"message\" => \"There must be only an user or admin set\",\n *             \"callback\" => function($data) {\n *                 if (!empty($data->getUser()) && !empty($data->getAdmin())) {\n *                     return false;\n *                 }\n *\n *                 return true;\n *             }\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     \"amount\",\n *     new CallbackValidator(\n *         [\n *             \"callback\" => function($data) {\n *                 if (!empty($data->getProduct())) {\n *                     return new NumericalityValidator(\n *                         [\n *                             \"message\" => \"Amount must be a number.\"\n *                         ]\n *                     );\n *                 }\n *             }\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
        "line": 61,
        "char": 5
    },
    {
        "type": "class",
        "name": "Callback",
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
                        "value": "Field :field must match the callback function",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                        "line": 63,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                    "line": 67,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                "line": 68,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                            "line": 68,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                            "line": 68,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "callback",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 70,
                                    "char": 21
                                },
                                {
                                    "variable": "returnedValue",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 70,
                                    "char": 36
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 70,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                            "line": 72,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "callback",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 72,
                                            "char": 29
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "callback",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 72,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 72,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                        "line": 72,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 72,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                            "line": 74,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_callable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "callback",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 74,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                        "line": 74,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                "line": 74,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 75,
                                                    "char": 35
                                                },
                                                "name": "getEntity",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 75,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 75,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 77,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 77,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                        "line": 77,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "data",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "validation",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                            "line": 78,
                                                            "char": 39
                                                        },
                                                        "name": "getData",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 78,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 78,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 79,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 81,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "returnedValue",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "call_user_func",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "callback",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                            "line": 81,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 81,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                            "line": 81,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 81,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 81,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 81,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 83,
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
                                                "value": "returnedValue",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 83,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 83,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "boolean",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 83,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                        "line": 83,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "returnedValue",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 84,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 84,
                                                "char": 35
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "validation",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                            "line": 85,
                                                            "char": 32
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
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                        "line": 86,
                                                                        "char": 30
                                                                    },
                                                                    "name": "messageFactory",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "validation",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                                "line": 86,
                                                                                "char": 56
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                            "line": 86,
                                                                            "char": 56
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "field",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                                "line": 86,
                                                                                "char": 63
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                            "line": 86,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                    "line": 87,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                "line": 87,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 87,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 89,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 89,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 90,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 92,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 92,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 93,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "returnedValue",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                            "line": 93,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 93,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 93,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 93,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "instanceof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "returnedValue",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 93,
                                                        "char": 79
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "Validator",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 93,
                                                        "char": 91
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 93,
                                                    "char": 91
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 93,
                                                "char": 91
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "returnedValue",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                            "line": 94,
                                                            "char": 38
                                                        },
                                                        "name": "validate",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "validation",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                    "line": 94,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                "line": 94,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "field",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                    "line": 94,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                                "line": 94,
                                                                "char": 65
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                        "line": 94,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 95,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                            "line": 97,
                                            "char": 17
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 97,
                                    "char": 17
                                },
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
                                                    "value": "Callback must return bool or Phalcon\\\\Validation\\\\Validator object",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                    "line": 99,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                                "line": 99,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                        "line": 99,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                    "line": 100,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                            "line": 102,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                "line": 102,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                            "line": 103,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                                "line": 69,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                        "line": 69,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
                    "line": 68,
                    "last-line": 104,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
            "line": 61,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Callback.zep",
        "line": 61,
        "char": 5
    }
]