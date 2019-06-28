[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation",
        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is a base class for combined fields validators\n *",
        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
        "line": 18,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractValidatorComposite",
        "abstract": 1,
        "final": 0,
        "extends": "AbstractValidator",
        "implements": [
            {
                "type": "variable",
                "value": "ValidatorCompositeInterface",
                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                "line": 19,
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
                    "name": "validators",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                        "line": 23,
                        "char": 31
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                            "line": 23,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                    "line": 27,
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
                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                "line": 28,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                            "line": 28,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                            "line": 28,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "validator",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                    "line": 30,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                            "line": 32,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                        "line": 32,
                                                        "char": 32
                                                    },
                                                    "name": "getValidators",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                    "line": 32,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                "line": 32,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                        "line": 32,
                                        "char": 52
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                        "line": 32,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                    "line": 32,
                                    "char": 56
                                },
                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                "line": 32,
                                "char": 56
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "get_class",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                                    "line": 33,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                                "line": 33,
                                                                "char": 47
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                        "line": 33,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " does not have any validator added",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                        "line": 33,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                    "line": 33,
                                                    "char": 85
                                                },
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                "line": 33,
                                                "char": 85
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                        "line": 33,
                                        "char": 86
                                    },
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                    "line": 34,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                            "line": 36,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                    "line": 36,
                                    "char": 31
                                },
                                "name": "getValidators",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                "line": 36,
                                "char": 48
                            },
                            "value": "validator",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "validator",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                "line": 37,
                                                "char": 26
                                            },
                                            "name": "validate",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "validation",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                        "line": 37,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                    "line": 37,
                                                    "char": 46
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                        "line": 37,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                    "line": 37,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                            "line": 37,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                            "line": 37,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                        "line": 37,
                                        "char": 65
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                                "line": 38,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                            "line": 39,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                    "line": 40,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                            "line": 42,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                "line": 42,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                            "line": 43,
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
                                "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                                "line": 29,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                        "line": 29,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
                    "line": 28,
                    "last-line": 44,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
            "line": 18,
            "char": 14
        },
        "file": "\/app\/phalcon\/Validation\/AbstractValidatorComposite.zep",
        "line": 18,
        "char": 14
    }
]