[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\QueryInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Query\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "QueryInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "cache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cacheOptions",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 25,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets the cache parameters of the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                    "line": 25,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 25,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 25,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 25,
                    "last-line": 31,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "execute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 32,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 32,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 32,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 32,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Executes a parsed PHQL statement\n     *\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 32,
                    "last-line": 36,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBindParams",
                    "docblock": "**\n     * Returns default bind params\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 37,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 37,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 37,
                    "last-line": 41,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCacheOptions",
                    "docblock": "**\n     * Returns the current cache options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 42,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 42,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 42,
                    "last-line": 46,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBindTypes",
                    "docblock": "**\n     * Returns default bind types\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 47,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 47,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 47,
                    "last-line": 51,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSql",
                    "docblock": "**\n     * Returns the SQL to be generated by the internal PHQL (only works in SELECT statements)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 52,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 52,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 52,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSingleResult",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 57,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 57,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 57,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 57,
                            "char": 80
                        }
                    ],
                    "docblock": "**\n     * Executes the query returning the first result\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                    "line": 57,
                                    "char": 101
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 57,
                                "char": 101
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 57,
                        "char": 101
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 57,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUniqueRow",
                    "docblock": "**\n     * Check if the query is programmed to get only the first row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 62,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 62,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 62,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "parse",
                    "docblock": "**\n     * Parses the intermediate code produced by Phalcon\\Mvc\\Model\\Query\\Lang generating another\n     * intermediate representation that could be executed by Phalcon\\Mvc\\Model\\Query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 68,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 68,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 68,
                    "last-line": 72,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBindParams",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 73,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 73,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 73,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Set default bind parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                    "line": 73,
                                    "char": 93
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 73,
                                "char": 93
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 73,
                        "char": 93
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 73,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBindTypes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 78,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 78,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 78,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Set default bind parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                    "line": 78,
                                    "char": 91
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 78,
                                "char": 91
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 78,
                        "char": 91
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 78,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setSharedLock",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sharedLock",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 83,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 83,
                            "char": 58
                        }
                    ],
                    "docblock": "**\n     * Set SHARED LOCK clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                    "line": 83,
                                    "char": 79
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 83,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 83,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 83,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setUniqueRow",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uniqueRow",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                            "line": 88,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Tells to the query if only the first row in the resultset must be returned\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                    "line": 88,
                                    "char": 69
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                                "line": 88,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                        "line": 88,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
                    "line": 88,
                    "last-line": 89,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
            "line": 89,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/QueryInterface.zep",
        "line": 0,
        "char": 0
    }
]