[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation",
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection",
                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                "line": 15,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                "line": 16,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                "line": 17,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\ValidatorInterface",
                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                "line": 18,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is a base class for validators\n *",
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 23,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractValidator",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ValidatorInterface",
                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                "line": 24,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "template",
                    "docblock": "**\n    * Message template\n    *\n    * @var string|null\n    *",
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 36,
                    "char": 5
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "templates",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 37,
                        "char": 29
                    },
                    "docblock": "**\n    * Message templates\n    *\n    * @var array\n    *",
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 39,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 43,
                    "char": 6
                }
            ],
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
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 44,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 44,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "template",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 46,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 48,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "template",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "current",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Arr",
                                                    "dynamic": 0,
                                                    "name": "whiteList",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "options",
                                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                "line": 48,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 48,
                                                            "char": 54
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "string",
                                                                            "value": "template",
                                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                            "line": 48,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                        "line": 48,
                                                                        "char": 65
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "string",
                                                                            "value": "message",
                                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                            "line": 48,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                        "line": 48,
                                                                        "char": 74
                                                                    },
                                                                    {
                                                                        "value": {
                                                                            "type": "int",
                                                                            "value": "0",
                                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                            "line": 48,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                        "line": 48,
                                                                        "char": 77
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                "line": 48,
                                                                "char": 78
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 48,
                                                            "char": 78
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 48,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 48,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 48,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 48,
                                    "char": 80
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 50,
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
                                        "value": "template",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 50,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 50,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 50,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 50,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 51,
                                            "char": 18
                                        },
                                        "name": "setTemplates",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "template",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 51,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 51,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 51,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 52,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "template",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 52,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 52,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 52,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 52,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 53,
                                                    "char": 18
                                                },
                                                "name": "setTemplate",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "template",
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 53,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 53,
                                                        "char": 39
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 53,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 54,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 56,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 56,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "template",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 56,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 57,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "template",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 57,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 57,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 58,
                                    "char": 17
                                },
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 58,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 58,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 58,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 59,
                                    "char": 17
                                },
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 59,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 59,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 59,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 60,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 62,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 62,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 62,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 63,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Validation\\Validator constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 45,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 44,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTemplate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 71,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 71,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 74,
                                        "char": 20
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 74,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 74,
                                    "char": 28
                                },
                                "right": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 74,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "templates",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 74,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 74,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 74,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 74,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 74,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 74,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 75,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "templates",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 75,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 75,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 75,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 75,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 79,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 79,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "template",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 79,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 79,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 80,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "template",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 80,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 80,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 81,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 84,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "The field :field is not valid for ",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 84,
                                    "char": 51
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "get_class",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 84,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 84,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 84,
                                    "char": 68
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 84,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 85,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Get the template message\n    *\n    * @return string\n    * @throw InvalidArgumentException When the field does not exists\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 72,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 71,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTemplates",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 94,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "templates",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 94,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 94,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Get templates collection object\n    *\n    * @return array\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 93,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 92,
                    "last-line": 101,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTemplates",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "templates",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 102,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 104,
                                    "char": 18
                                },
                                {
                                    "variable": "template",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 104,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 106,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "templates",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 106,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 106,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 108,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "templates",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 108,
                                "char": 42
                            },
                            "key": "field",
                            "value": "template",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "field",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 109,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 109,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 109,
                                            "char": 56
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "template",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "template",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 110,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 110,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 110,
                                            "char": 59
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "templates",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 111,
                                                    "char": 38
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "template",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 111,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 111,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 112,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 114,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 114,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 115,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Clear current templates and set new from an array,\n    *\n    * @return Validator\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidatorInterface",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 103,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 103,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 103,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 102,
                    "last-line": 121,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTemplate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "template",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 122,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "template",
                                    "expr": {
                                        "type": "variable",
                                        "value": "template",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 124,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 124,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 126,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 126,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 127,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Set a new template message\n    *\n    * @return Validator\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidatorInterface",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 123,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 123,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 123,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 122,
                    "last-line": 132,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 133,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 133,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 133,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 135,
                                    "char": 18
                                },
                                {
                                    "variable": "fieldValue",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 135,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 137,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 137,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 137,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 137,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 137,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 137,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 137,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 137,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 137,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 138,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 139,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 145,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 145,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "attribute",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 145,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 145,
                                    "char": 30
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 145,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 145,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 145,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 145,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 145,
                                "char": 54
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "fieldValue",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 146,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 146,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 146,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 146,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 146,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "fieldValue",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 147,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 148,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 149,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 151,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 151,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 152,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an option in the validator's options\n     * Returns null if the option hasn't set\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 133,
                    "last-line": 156,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 157,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 159,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 159,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 159,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 159,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 159,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 159,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 160,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if an option is defined\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 158,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 158,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 157,
                    "last-line": 164,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 165,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 165,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 167,
                                            "char": 30
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 167,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 167,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 168,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an option in the validator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 166,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 165,
                    "last-line": 172,
                    "char": 19
                },
                {
                    "visibility": [
                        "abstract",
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
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 173,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 173,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 173,
                            "char": 73
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
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 173,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 173,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 173,
                    "last-line": 177,
                    "char": 28
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareCode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 178,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 180,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 182,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 182,
                                            "char": 25
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "code",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 182,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 182,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 182,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 182,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 184,
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
                                        "value": "code",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 184,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 184,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 184,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 184,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "code",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 185,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 185,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 185,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 185,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 186,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 188,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 188,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 189,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepares a validation code.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 178,
                                "char": 58
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 179,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 179,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 178,
                    "last-line": 193,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareLabel",
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
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 194,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 194,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 194,
                            "char": 75
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "label",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 196,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "label",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 198,
                                            "char": 26
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "label",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 198,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 198,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 198,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 198,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 200,
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
                                        "value": "label",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 200,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 200,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 200,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 200,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "label",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "label",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 201,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 201,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 201,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 201,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 202,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 204,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "label",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 204,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 204,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "label",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 205,
                                                    "char": 36
                                                },
                                                "name": "getLabel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 205,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 205,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 205,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 205,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 206,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 208,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "label",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 208,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 209,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepares a label for the field.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 195,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 195,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 194,
                    "last-line": 217,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "messageFactory",
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
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 218,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 218,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 218,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "replacements",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 218,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 218,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "singleField",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 220,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 222,
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
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 222,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 222,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 222,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 222,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "singleField",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "implode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": ", ",
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 223,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 223,
                                                        "char": 41
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 223,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 223,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 223,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 223,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 224,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 224,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 224,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 224,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 224,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "singleField",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 225,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 225,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 226,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 226,
                                    "char": 14
                                }
                            ],
                            "else_statements": [
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
                                                    "value": "The field can not be printed",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 227,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 227,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 227,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 228,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 230,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "replacements",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": ":field",
                                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                "line": 232,
                                                                "char": 24
                                                            },
                                                            "value": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                    "line": 232,
                                                                    "char": 31
                                                                },
                                                                "name": "prepareLabel",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "validation",
                                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                            "line": 232,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                        "line": 232,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "singleField",
                                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                            "line": 232,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                        "line": 232,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                "line": 233,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 233,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 233,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 233,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "replacements",
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 235,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 235,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 235,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 235,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 237,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Message",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                            "line": 238,
                                                            "char": 24
                                                        },
                                                        "name": "getTemplate",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "singleField",
                                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                    "line": 238,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                                "line": 238,
                                                                "char": 48
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 238,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 238,
                                                    "char": 49
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "replacements",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 238,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 238,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 238,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 238,
                                        "char": 64
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 239,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 239,
                                        "char": 18
                                    },
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "get_class",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 240,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 240,
                                                    "char": 27
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 240,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 240,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                "line": 241,
                                                "char": 18
                                            },
                                            "name": "prepareCode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "singleField",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                        "line": 241,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                                    "line": 241,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                            "line": 242,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                        "line": 242,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 242,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                            "line": 243,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Create a default message by factory\n    *\n    * @return Message\n    *\n    * @throw Exception\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Message",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                    "line": 219,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                                "line": 219,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                        "line": 219,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
                    "line": 218,
                    "last-line": 244,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
            "line": 23,
            "char": 14
        },
        "file": "\/app\/phalcon\/Validation\/AbstractValidator.zep",
        "line": 23,
        "char": 14
    }
]