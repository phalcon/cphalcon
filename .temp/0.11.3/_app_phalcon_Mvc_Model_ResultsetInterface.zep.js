[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                "line": 14,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                "line": 15,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                "line": 16,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\ResultsetInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Resultset\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 23,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ResultsetInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "conditionCallback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Closure",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 28,
                                "char": 54
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 28,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                            "line": 28,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Deletes every record in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 28,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 28,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 28,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "filter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                            "line": 43,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Filters a resultset returning only those the developer requires\n     *\n     *```php\n     * $filtered = $robots->filter(\n     *     function ($robot) {\n     *         if ($robot->id < 3) {\n     *             return $robot;\n     *         }\n     *     }\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                    "line": 43,
                                    "char": 66
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 43,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 43,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCache",
                    "docblock": "**\n     * Returns the associated cache for the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                    "line": 48,
                                    "char": 53
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 48,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 48,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFirst",
                    "docblock": "**\n     * Get first row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                    "line": 53,
                                    "char": 52
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 53,
                                "char": 52
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 53,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 53,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHydrateMode",
                    "docblock": "**\n     * Returns the current hydration mode\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 58,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 58,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 58,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLast",
                    "docblock": "**\n     * Get last row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                    "line": 63,
                                    "char": 51
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 63,
                                "char": 51
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 63,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 63,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 63,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "docblock": "**\n     * Returns the error messages produced by a batch operation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                    "line": 68,
                                    "char": 58
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 68,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 68,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 68,
                    "last-line": 72,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "docblock": "**\n     * Returns the internal type of data retrieval that the resultset is using\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 73,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 73,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 73,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isFresh",
                    "docblock": "**\n     * Tell if the resultset if fresh or an old one cached\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 78,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 78,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 78,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHydrateMode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "hydrateMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                            "line": 83,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets the hydration mode in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                    "line": 83,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 83,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 83,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 83,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setIsFresh",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "isFresh",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                            "line": 88,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Set if the resultset is fresh or an old one cached\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                    "line": 88,
                                    "char": 69
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 88,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 88,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 88,
                    "last-line": 93,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "docblock": "**\n     * Returns a complete resultset as an array, if the resultset has a big number of rows\n     * it could consume more memory than currently it does.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 94,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 94,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 94,
                    "last-line": 100,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "update",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                            "line": 101,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "conditionCallback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Closure",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 101,
                                "char": 64
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 101,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                            "line": 101,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Updates every record in the resultset\n     *\n     * @param array data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                                "line": 101,
                                "char": 81
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                        "line": 101,
                        "char": 81
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
                    "line": 101,
                    "last-line": 102,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
            "line": 102,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultsetInterface.zep",
        "line": 0,
        "char": 0
    }
]