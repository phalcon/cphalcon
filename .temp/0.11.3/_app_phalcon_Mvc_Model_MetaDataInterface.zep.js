[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                "line": 14,
                "char": 49
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaDataInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\MetaData\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
        "line": 21,
        "char": 9
    },
    {
        "type": "interface",
        "name": "MetaDataInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 26,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 26,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Returns table attributes names (fields)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 26,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 26,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAutomaticCreateAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 31,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 31,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Returns attributes that must be ignored from the INSERT SQL generation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 31,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 31,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAutomaticUpdateAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 36,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 36,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Returns attributes that must be ignored from the UPDATE SQL generation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 36,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 36,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBindTypes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 41,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 41,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Returns attributes and their bind data types\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 41,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 41,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnMap",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 46,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 46,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Returns the column map if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 46,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 46,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultValues",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 51,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 51,
                            "char": 60
                        }
                    ],
                    "docblock": "**\n     * Returns attributes (which have default values) and their default values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 51,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 51,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDataTypes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 56,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 56,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Returns attributes and their data types\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 56,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 56,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDataTypesNumeric",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 61,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 61,
                            "char": 63
                        }
                    ],
                    "docblock": "**\n     * Returns attributes which types are numerical\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 61,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 61,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEmptyStringAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 66,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 66,
                            "char": 68
                        }
                    ],
                    "docblock": "**\n     * Returns attributes allow empty strings\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 66,
                                "char": 78
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 66,
                        "char": 78
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 66,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIdentityField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 71,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 71,
                            "char": 60
                        }
                    ],
                    "docblock": "**\n     * Returns the name of identity field (if one is present)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 71,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 71,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 71,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNonPrimaryKeyAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 76,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 76,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Returns an array of fields which are not part of the primary key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 76,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 76,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNotNullAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 81,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 81,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Returns an array of not null attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 81,
                                "char": 74
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 81,
                        "char": 74
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 81,
                    "last-line": 85,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrimaryKeyAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 86,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 86,
                            "char": 67
                        }
                    ],
                    "docblock": "**\n     * Returns an array of fields which are part of the primary key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 86,
                                "char": 77
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 86,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 86,
                    "last-line": 90,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReverseColumnMap",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 91,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 91,
                            "char": 63
                        }
                    ],
                    "docblock": "**\n     * Returns the reverse column map if any\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 91,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 91,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 91,
                    "last-line": 95,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStrategy",
                    "docblock": "**\n     * Return the strategy to obtain the meta-data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "StrategyInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                    "line": 96,
                                    "char": 57
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 96,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 96,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 96,
                    "last-line": 100,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 101,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 101,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 101,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Check if a model has certain attribute\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 101,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 101,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 101,
                    "last-line": 105,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isEmpty",
                    "docblock": "**\n     * Checks if the internal meta-data container is empty\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 106,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 106,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 106,
                    "last-line": 110,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "read",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 111,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Reads meta-data from the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 111,
                                "char": 47
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 111,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 111,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 111,
                    "last-line": 115,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "readColumnMap",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 116,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 116,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Reads the ordered\/reversed column map for certain model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 116,
                                "char": 68
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 116,
                                "char": 74
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 116,
                        "char": 74
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 116,
                    "last-line": 120,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "readColumnMapIndex",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 121,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 121,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 121,
                            "char": 73
                        }
                    ],
                    "docblock": "**\n     * Reads column-map information for certain model using a MODEL_* constant\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 121,
                    "last-line": 125,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "readMetaData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 126,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 126,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Reads meta-data for certain model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 126,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 126,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 126,
                    "last-line": 130,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "readMetaDataIndex",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 131,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 131,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 131,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Reads meta-data for certain model using a MODEL_* constant\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 131,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 131,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 131,
                    "last-line": 135,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "docblock": "**\n     * Resets internal meta-data in order to regenerate it\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 136,
                    "last-line": 140,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAutomaticCreateAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 141,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 141,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 141,
                            "char": 90
                        }
                    ],
                    "docblock": "**\n     * Set the attributes that must be ignored from the INSERT SQL generation\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 141,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAutomaticUpdateAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 146,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 146,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 146,
                            "char": 90
                        }
                    ],
                    "docblock": "**\n     * Set the attributes that must be ignored from the UPDATE SQL generation\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 146,
                    "last-line": 150,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEmptyStringAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 151,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 151,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 151,
                            "char": 86
                        }
                    ],
                    "docblock": "**\n     * Set the attributes that allow empty string values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 151,
                        "char": 95
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 151,
                    "last-line": 155,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "writeMetaDataIndex",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 156,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 156,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 156,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 156,
                            "char": 83
                        }
                    ],
                    "docblock": "**\n     * Writes meta-data for certain model using a MODEL_* constant\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 156,
                    "last-line": 160,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStrategy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "strategy",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "StrategyInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                                "line": 161,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 161,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Set the meta-data extraction strategy\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 161,
                    "last-line": 165,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "write",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 166,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                            "line": 166,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Writes meta-data to the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                        "line": 166,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
                    "line": 166,
                    "last-line": 167,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
            "line": 167,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaDataInterface.zep",
        "line": 0,
        "char": 0
    }
]