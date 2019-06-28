[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 10,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 12,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 12,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 14,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\CriteriaInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 15,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 16,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaDataInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 17,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\ResultsetInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\TransactionInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 19,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                "line": 20,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 26,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\ModelInterface\n *\n * Interface for Phalcon\\Mvc\\Model\n *",
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 27,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ModelInterface",
        "definition": {
            "methods": [
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
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 32,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 32,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Appends a customized message on the validation process\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 32,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 32,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 32,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 32,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "assign",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 39,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "dataColumnMap",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 39,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 39,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "whiteList",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 39,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 39,
                            "char": 87
                        }
                    ],
                    "docblock": "**\n     * Assigns values to a model from an array\n     *\n     * @param array columnMap\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 39,
                                    "char": 108
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 39,
                                "char": 108
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 39,
                        "char": 108
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 39,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "average",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 48,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 48,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Allows to calculate the average value on a column matching the specified\n     * conditions\n     *\n     * @param array parameters\n     * @return double\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "double",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 48,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 48,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "cloneResult",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "base",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 53,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 53,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 53,
                            "char": 74
                        },
                        {
                            "type": "parameter",
                            "name": "dirtyState",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 53,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 53,
                            "char": 94
                        }
                    ],
                    "docblock": "**\n     * Assigns values to a model from an array returning a new model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 53,
                                    "char": 115
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 53,
                                "char": 115
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 53,
                        "char": 115
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 53,
                    "last-line": 61,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "cloneResultMap",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "base",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 62,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 62,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "columnMap",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 62,
                            "char": 75
                        },
                        {
                            "type": "parameter",
                            "name": "dirtyState",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 62,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 62,
                            "char": 95
                        },
                        {
                            "type": "parameter",
                            "name": "keepSnapshots",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 62,
                                "char": 122
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 62,
                            "char": 122
                        }
                    ],
                    "docblock": "**\n     * Assigns values to a model from an array returning a new model\n     *\n     * @param \\Phalcon\\Mvc\\Model base\n     * @param array columnMap\n     * @return \\Phalcon\\Mvc\\Model result\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 62,
                                    "char": 143
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 62,
                                "char": 143
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 62,
                        "char": 143
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 62,
                    "last-line": 68,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "cloneResultMapHydrate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 69,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "columnMap",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 69,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "hydrationMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 69,
                            "char": 95
                        }
                    ],
                    "docblock": "**\n     * Returns an hydrated result based on the data and the column map\n     *\n     * @param array columnMap\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 69,
                    "last-line": 76,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "count",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 77,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 77,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Allows to count how many records match the specified conditions\n     *\n     * @param array parameters\n     * @return int\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 77,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 77,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 77,
                    "last-line": 83,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "create",
                    "docblock": "**\n     * Inserts a model instance. If the instance already exists in the\n     * persistence it will throw an exception. Returning true on success or\n     * false otherwise.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 84,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 84,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 84,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "docblock": "**\n     * Deletes a model instance. Returning true on success or false otherwise.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 89,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 89,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 89,
                    "last-line": 93,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "find",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 94,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 94,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Allows to query a set of records that match the specified conditions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 94,
                                    "char": 79
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 94,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 94,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 94,
                    "last-line": 100,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "findFirst",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 101,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 101,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Allows to query the first record that match the specified conditions\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 101,
                                    "char": 77
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 101,
                                "char": 77
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 101,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 101,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 101,
                    "last-line": 106,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fireEvent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 107,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Fires an event, implicitly calls behaviors and listeners in the events\n     * manager are notified\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 107,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 107,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 107,
                    "last-line": 113,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fireEventCancel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 114,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Fires an event, implicitly calls behaviors and listeners in the events\n     * manager are notified. This method stops if one of the callbacks\/listeners\n     * returns bool false\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 114,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 114,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 114,
                    "last-line": 119,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDirtyState",
                    "docblock": "**\n     * Returns one of the DIRTY_STATE_* constants telling if the record exists\n     * in the database or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 120,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 120,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 120,
                    "last-line": 124,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "docblock": "**\n     * Returns array of validation messages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 125,
                                    "char": 58
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 125,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 125,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 125,
                    "last-line": 129,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModelsMetaData",
                    "docblock": "**\n     * Returns the models meta-data service related to the entity instance.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MetaDataInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 130,
                                    "char": 63
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 130,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 130,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 130,
                    "last-line": 135,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOperationMade",
                    "docblock": "**\n     * Returns the type of the latest operation performed by the ORM\n     * Returns one of the OP_* class constants\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 136,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 136,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 136,
                    "last-line": 140,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReadConnection",
                    "docblock": "**\n     * Gets internal database connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 141,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 141,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 141,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 141,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReadConnectionService",
                    "docblock": "**\n     * Returns DependencyInjection connection service used to read data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 146,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 146,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 146,
                    "last-line": 153,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRelated",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 154,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 154,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 154,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Returns related records based on defined relations\n     *\n     * @param array arguments\n     * @return \\Phalcon\\Mvc\\Model\\Resultset\\Simple|Phalcon\\Mvc\\Model\\Resultset\\Simple|false\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 154,
                    "last-line": 158,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSchema",
                    "docblock": "**\n     * Returns schema name where table mapped is located\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 159,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 159,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 159,
                    "last-line": 163,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSource",
                    "docblock": "**\n     * Returns table name mapped in the model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 164,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 164,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 164,
                    "last-line": 168,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getWriteConnection",
                    "docblock": "**\n     * Gets internal database connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 169,
                                    "char": 63
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 169,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 169,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 169,
                    "last-line": 173,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getWriteConnectionService",
                    "docblock": "**\n     * Returns DependencyInjection connection service used to write data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 174,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 174,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 174,
                    "last-line": 182,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "maximum",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 183,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 183,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Allows to get the maximum value of a column that match the specified\n     * conditions\n     *\n     * @param array parameters\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 183,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 183,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 183,
                    "last-line": 191,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "minimum",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 192,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 192,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Allows to get the minimum value of a column that match the specified\n     * conditions\n     *\n     * @param array parameters\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 192,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 192,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 192,
                    "last-line": 196,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "query",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 197,
                                "char": 56
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 197,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 197,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Create a criteria for a specific model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 197,
                                    "char": 88
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 197,
                                "char": 88
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 197,
                        "char": 88
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 197,
                    "last-line": 201,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "refresh",
                    "docblock": "**\n     * Refreshes the model attributes re-querying the record from the database\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 202,
                                    "char": 50
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 202,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 202,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 202,
                    "last-line": 207,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "save",
                    "docblock": "**\n     * Inserts or updates a model instance. Returning true on success or false\n     * otherwise.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 208,
                                "char": 35
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 208,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 208,
                    "last-line": 212,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setConnectionService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 213,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Sets both read\/write connection services\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 213,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 213,
                    "last-line": 218,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDirtyState",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "dirtyState",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 219,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets the dirty state of the object using one of the DIRTY_STATE_*\n     * constants\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 219,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 219,
                                "char": 71
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 219,
                                "char": 77
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 219,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 219,
                    "last-line": 223,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setReadConnectionService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 224,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjection connection service used to read data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 224,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 224,
                    "last-line": 231,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setSnapshotData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 232,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "columnMap",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 232,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 232,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Sets the record's snapshot data. This method is used internally to set\n     * snapshot data when the model was set up to keep snapshot data\n     *\n     * @param array columnMap\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 232,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 232,
                    "last-line": 236,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTransaction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "transaction",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "TransactionInterface",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 237,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 237,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Sets a transaction related to the Model instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                    "line": 237,
                                    "char": 91
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 237,
                                "char": 91
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 237,
                        "char": 91
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 237,
                    "last-line": 241,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setWriteConnectionService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 242,
                            "char": 71
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjection connection service used to write data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 242,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 242,
                    "last-line": 246,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "skipOperation",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "skip",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 247,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Skips the current operation forcing a success state\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 247,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 247,
                    "last-line": 254,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "sum",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 255,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                            "line": 255,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Allows to calculate a sum on a column that match the specified conditions\n     *\n     * @param array parameters\n     * @return double\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "double",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 255,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 255,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 255,
                    "last-line": 259,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "validationHasFailed",
                    "docblock": "**\n     * Check whether validation process has generated any messages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 260,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 260,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 260,
                    "last-line": 266,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "update",
                    "docblock": "**\n     * Updates a model instance. If the instance doesn't exist in the\n     * persistence it will throw an exception. Returning true on success or\n     * false otherwise.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                                "line": 267,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                        "line": 267,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
                    "line": 267,
                    "last-line": 268,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
            "line": 268,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/ModelInterface.zep",
        "line": 0,
        "char": 0
    }
]