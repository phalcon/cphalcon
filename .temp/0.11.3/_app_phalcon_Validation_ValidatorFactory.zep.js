[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation",
        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "ValidatorFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
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
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 21,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 21,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                    "line": 23,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 23,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 23,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 23,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 24,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * TagFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                    "line": 21,
                    "last-line": 28,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 29,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                    "line": 31,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 33,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                    "line": 33,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 33,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 33,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 33,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 35,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                "line": 35,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                "line": 35,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 35,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 35,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 35,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                    "line": 35,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 35,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                        "line": 36,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                        "line": 36,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                    "line": 36,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                    "line": 36,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                "line": 36,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 36,
                                            "char": 58
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "services",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                    "line": 37,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "definition",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                                "line": 37,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 37,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                    "line": 38,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 40,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 40,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 40,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                    "line": 40,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                    "line": 40,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 40,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 41,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates a new instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 30,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                        "line": 30,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                    "line": 29,
                    "last-line": 43,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "alnum",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 46,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Alnum",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 46,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 46,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "alpha",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 47,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Alpha",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 47,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 47,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "between",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 48,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Between",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 48,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 48,
                                        "char": 69
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "callback",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 49,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Callback",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 49,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 49,
                                        "char": 70
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "confirmation",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 50,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Confirmation",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 50,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 50,
                                        "char": 74
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "creditCard",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 51,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\CreditCard",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 51,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 51,
                                        "char": 72
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "date",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 52,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Date",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 52,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 52,
                                        "char": 66
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "digit",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 53,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Digit",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 53,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 53,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "email",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 54,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Email",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 54,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 54,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "exception",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 55,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Exception",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 55,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 55,
                                        "char": 71
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "exclusionIn",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 56,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\ExclusionIn",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 56,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 56,
                                        "char": 73
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "file",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 57,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\File",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 57,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 57,
                                        "char": 66
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "identical",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 58,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Identical",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 58,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 58,
                                        "char": 71
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "inclusionIn",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 59,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\InclusionIn",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 59,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 59,
                                        "char": 73
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "ip",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 60,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Ip",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 60,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 60,
                                        "char": 64
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "numericality",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 61,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Numericality",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 61,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 61,
                                        "char": 74
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "presenceOf",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 62,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\PresenceOf",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 62,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 62,
                                        "char": 72
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "regex",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 63,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Regex",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 63,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 63,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "stringLength",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 64,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\StringLength",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 64,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 64,
                                        "char": 74
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "uniqueness",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 65,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Uniqueness",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 65,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 65,
                                        "char": 72
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "url",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 66,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Validation\\\\Validator\\\\Url",
                                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                            "line": 67,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                        "line": 67,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 67,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                            "line": 68,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                                "line": 44,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                        "line": 44,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
                    "line": 43,
                    "last-line": 69,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/ValidatorFactory.zep",
        "line": 16,
        "char": 5
    }
]