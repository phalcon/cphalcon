[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation",
        "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is a base class for combined fields validators\n *",
        "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ValidatorCompositeInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getValidators",
                    "docblock": "**\n     * Executes the validation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                                "line": 23,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                        "line": 23,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                    "line": 23,
                    "last-line": 27,
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
                                "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                                "line": 28,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
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
                            "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                            "line": 28,
                            "char": 64
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
                                "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                                "line": 28,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                        "line": 28,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
                    "line": 28,
                    "last-line": 29,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
            "line": 29,
            "char": 1
        },
        "file": "\/app\/phalcon\/Validation\/ValidatorCompositeInterface.zep",
        "line": 0,
        "char": 0
    }
]