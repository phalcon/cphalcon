[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "StrategyInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnMaps",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                                "line": 23,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                            "line": 23,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                                "line": 23,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                            "line": 23,
                            "char": 82
                        }
                    ],
                    "docblock": "**\n     * Read the model's column map, this can't be inferred\n     *\n     * @todo Not implemented\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                                "line": 23,
                                "char": 92
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                        "line": 23,
                        "char": 92
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMetaData",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                                "line": 28,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                            "line": 28,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                                "line": 28,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                            "line": 28,
                            "char": 80
                        }
                    ],
                    "docblock": "**\n     * The meta-data is obtained by reading the column descriptions from the database information schema\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                                "line": 28,
                                "char": 90
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                        "line": 28,
                        "char": 90
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
                    "line": 28,
                    "last-line": 29,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
            "line": 29,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/StrategyInterface.zep",
        "line": 0,
        "char": 0
    }
]