[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation",
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                "line": 14,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Messages",
                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                "line": 15,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\ValidatorInterface",
                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                "line": 17,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for the Phalcon\\Validation component\n *",
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 22,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ValidationInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "add",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 27,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "validator",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ValidatorInterface",
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 27,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 27,
                            "char": 69
                        }
                    ],
                    "docblock": "**\n     * Adds a validator to a field\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidationInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 27,
                                    "char": 95
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 27,
                                "char": 95
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 27,
                        "char": 95
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 27,
                    "last-line": 31,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "appendMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "MessageInterface",
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 32,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 32,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Appends a message to the messages list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidationInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 32,
                                    "char": 87
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 32,
                                "char": 87
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 32,
                        "char": 87
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 32,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "bind",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "entity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 41,
                            "char": 32
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 41,
                            "char": 38
                        }
                    ],
                    "docblock": "**\n     * Assigns the data to an entity\n     * The entity is used to obtain the validation values\n     *\n     * @param object entity\n     * @param array|object data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidationInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 41,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 41,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 41,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEntity",
                    "docblock": "**\n     * Returns the bound entity\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 46,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 46,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFilters",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 51,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 51,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Returns all the filters or a specific one\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 51,
                                "char": 60
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 51,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 51,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLabel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 56,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Get label for field\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 56,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 56,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "docblock": "**\n     * Returns the registered validators\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Messages",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 61,
                                    "char": 48
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 61,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 61,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getValidators",
                    "docblock": "**\n     * Returns the validators added to the validation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 66,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 66,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 66,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 71,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Gets the a value to validate in the array\/object data source\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 71,
                                "char": 51
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 71,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 71,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 71,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rule",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 76,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "validator",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ValidatorInterface",
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 76,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 76,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Alias of `add` method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidationInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 76,
                                    "char": 96
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 76,
                                "char": 96
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 76,
                        "char": 96
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rules",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 81,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "validators",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 81,
                            "char": 59
                        }
                    ],
                    "docblock": "**\n     * Adds the validators to a field\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidationInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 81,
                                    "char": 85
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 81,
                                "char": 85
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 81,
                        "char": 85
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 81,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFilters",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 88,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 88,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Adds filters to the field\n     *\n     * @param array|string filters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidationInterface",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 88,
                                    "char": 79
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 88,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 88,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 88,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLabels",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "labels",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 93,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Adds labels for fields\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 93,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 93,
                    "last-line": 100,
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
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 101,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 101,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "entity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 101,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                            "line": 101,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Validate a set of data according to a set of rules\n     *\n     * @param array|object data\n     * @param object entity\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Messages",
                                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                    "line": 101,
                                    "char": 79
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                                "line": 101,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                        "line": 101,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
                    "line": 101,
                    "last-line": 102,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
            "line": 102,
            "char": 1
        },
        "file": "\/app\/phalcon\/Validation\/ValidationInterface.zep",
        "line": 0,
        "char": 0
    }
]