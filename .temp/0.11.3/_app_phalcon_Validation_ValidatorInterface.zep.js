[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation",
        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection",
                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Validation\\AbstractValidator\n *",
        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ValidatorInterface",
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 27,
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
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 27,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 27,
                            "char": 67
                        }
                    ],
                    "docblock": "**\n     * Returns an option in the validator's options\n     * Returns null if the option hasn't set\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 27,
                                "char": 75
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                        "line": 27,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                    "line": 27,
                    "last-line": 33,
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
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 34,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Checks if an option is defined\n     *\n     * @return boolean\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 34,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                        "line": 34,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                    "line": 34,
                    "last-line": 40,
                    "char": 19
                },
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
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 41,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 41,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 41,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Executes the validation\n     *\n     * @return boolean\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 41,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                        "line": 41,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                    "line": 41,
                    "last-line": 48,
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
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 49,
                            "char": 46
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
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 49,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                        "line": 49,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                    "line": 49,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTemplates",
                    "docblock": "**\n    * Get message templates\n    *\n    * @return array\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 56,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                        "line": 56,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                    "line": 56,
                    "last-line": 62,
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
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 63,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n    * Clear current template and set new from an array,\n    *\n    * @return ValidatorInterface\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidatorInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                    "line": 63,
                                    "char": 75
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 63,
                                "char": 75
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                        "line": 63,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                    "line": 63,
                    "last-line": 69,
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
                            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                            "line": 70,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n    * Set a new temlate message\n    *\n    * @return ValidatorInterface\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidatorInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                    "line": 70,
                                    "char": 74
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                                "line": 70,
                                "char": 74
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                        "line": 70,
                        "char": 74
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
                    "line": 70,
                    "last-line": 71,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
            "line": 71,
            "char": 1
        },
        "file": "\/app\/phalcon\/Validation\/ValidatorInterface.zep",
        "line": 0,
        "char": 0
    }
]