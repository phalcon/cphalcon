[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\CriteriaInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Criteria\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "CriteriaInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "andWhere",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 28,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 28,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 28,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 28,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 28,
                            "char": 85
                        }
                    ],
                    "docblock": "**\n     * Appends a condition to the current conditions using an AND operator\n     *\n     * @param array bindParams\n     * @param array bindTypes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 28,
                                    "char": 109
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 28,
                                "char": 109
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 28,
                        "char": 109
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 28,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "betweenWhere",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expr",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 40,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "minimum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 40,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "maximum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 40,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Appends a BETWEEN condition to the current conditions\n     *\n     *```php\n     * $criteria->betweenWhere(\"price\", 100.25, 200.50);\n     *```\n     *\n     * @param mixed minimum\n     * @param mixed maximum\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 40,
                                    "char": 88
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 40,
                                "char": 88
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 40,
                        "char": 88
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 40,
                    "last-line": 45,
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
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 46,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Sets the bound parameters in the criteria\n     * This method replaces all previously set bound parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 46,
                                    "char": 67
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 46,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 46,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 46,
                    "last-line": 51,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "bindTypes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 52,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Sets the bind types in the criteria\n     * This method replaces all previously set bound parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 52,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 52,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 52,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 52,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "cache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cache",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 58,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Sets the cache options in the criteria\n     * This method replaces all previously set cache options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 58,
                                    "char": 63
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 58,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 58,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 58,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "conditions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 63,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Adds the conditions parameter to the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 63,
                                    "char": 74
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 63,
                                "char": 74
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 63,
                        "char": 74
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 63,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "distinct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "distinct",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 68,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Sets SELECT DISTINCT \/ SELECT ALL flag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 68,
                                    "char": 67
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 68,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 68,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 68,
                    "last-line": 72,
                    "char": 20
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "execute",
                    "docblock": "**\n     * Executes a find using the parameters built with the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 73,
                                    "char": 54
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 73,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 73,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 73,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "forUpdate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "forUpdate",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 78,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 78,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Sets the \"for_update\" parameter to the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 78,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 78,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 78,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 78,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumns",
                    "docblock": "**\n     * Returns the columns to be queried\n     *\n     * @return string|array|null\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 85,
                                "char": 44
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 85,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 85,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 85,
                    "last-line": 89,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConditions",
                    "docblock": "**\n     * Returns the conditions parameter in the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 90,
                                "char": 47
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 90,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 90,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 90,
                    "last-line": 94,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getGroupBy",
                    "docblock": "**\n     * Returns the group clause in the criteria\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 95,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHaving",
                    "docblock": "**\n     * Returns the having clause in the criteria\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 100,
                    "last-line": 106,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLimit",
                    "docblock": "**\n     * Returns the limit parameter in the criteria, which will be an integer if\n     * limit was set without an offset, an array with 'number' and 'offset' keys\n     * if an offset was set with the limit, or null if limit has not been set.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 107,
                                "char": 42
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 107,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 107,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 107,
                    "last-line": 111,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModelName",
                    "docblock": "**\n     * Returns an internal model name on which the criteria will be applied\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 112,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 112,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 112,
                    "last-line": 116,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOrderBy",
                    "docblock": "**\n     * Returns the order parameter in the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 117,
                                "char": 44
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 117,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 117,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 117,
                    "last-line": 121,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParams",
                    "docblock": "**\n     * Returns all the parameters defined in the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 122,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 122,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 122,
                    "last-line": 126,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getWhere",
                    "docblock": "**\n     * Returns the conditions parameter in the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 127,
                                "char": 42
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 127,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 127,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 127,
                    "last-line": 131,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "groupBy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "group",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 132,
                            "char": 38
                        }
                    ],
                    "docblock": "**\n     * Adds the group-by clause to the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 132,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 132,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 132,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 132,
                    "last-line": 136,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "having",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "having",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 137,
                            "char": 38
                        }
                    ],
                    "docblock": "**\n     * Adds the having clause to the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 137,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 137,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 137,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 137,
                    "last-line": 158,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "innerJoin",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 159,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 159,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 159,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 159,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 159,
                            "char": 85
                        }
                    ],
                    "docblock": "**\n     * Adds an INNER join to the query\n     *\n     *```php\n     * $criteria->innerJoin(\n     *     Robots::class\n     * );\n     *\n     * $criteria->innerJoin(\n     *     Robots::class,\n     *     \"r.id = RobotsParts.robots_id\"\n     * );\n     *\n     * $criteria->innerJoin(\n     *     Robots::class,\n     *     \"r.id = RobotsParts.robots_id\",\n     *     \"r\"\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 159,
                                    "char": 109
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 159,
                                "char": 109
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 159,
                        "char": 109
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 159,
                    "last-line": 167,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "inWhere",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expr",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 168,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 168,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Appends an IN condition to the current conditions\n     *\n     *```php\n     * $criteria->inWhere(\"id\", [1, 2, 3]);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 168,
                                    "char": 80
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 168,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 168,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 168,
                    "last-line": 180,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "leftJoin",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 181,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 181,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 181,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 181,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 181,
                            "char": 84
                        }
                    ],
                    "docblock": "**\n     * Adds a LEFT join to the query\n     *\n     *```php\n     * $criteria->leftJoin(\n     *     Robots::class,\n     *     \"r.id = RobotsParts.robots_id\",\n     *     \"r\"\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 181,
                                    "char": 108
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 181,
                                "char": 108
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 181,
                        "char": 108
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 181,
                    "last-line": 185,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "limit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "limit",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 186,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 186,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 186,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Sets the limit parameter to the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 186,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 186,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 186,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 186,
                    "last-line": 197,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notBetweenWhere",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expr",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 198,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "minimum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 198,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "maximum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 198,
                            "char": 67
                        }
                    ],
                    "docblock": "**\n     * Appends a NOT BETWEEN condition to the current conditions\n     *\n     *```php\n     * $criteria->notBetweenWhere(\"price\", 100.25, 200.50);\n     *```\n     *\n     * @param mixed minimum\n     * @param mixed maximum\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 198,
                                    "char": 91
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 198,
                                "char": 91
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 198,
                        "char": 91
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 198,
                    "last-line": 206,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notInWhere",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expr",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 207,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 207,
                            "char": 59
                        }
                    ],
                    "docblock": "**\n     * Appends a NOT IN condition to the current conditions\n     *\n     *```php\n     * $criteria->notInWhere(\"id\", [1, 2, 3]);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 207,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 207,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 207,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 207,
                    "last-line": 211,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "orderBy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "orderColumns",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 212,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Adds the order-by parameter to the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 212,
                                    "char": 73
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 212,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 212,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 212,
                    "last-line": 219,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "orWhere",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 220,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 220,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 220,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 220,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 220,
                            "char": 84
                        }
                    ],
                    "docblock": "**\n     * Appends a condition to the current conditions using an OR operator\n     *\n     * @param array bindParams\n     * @param array bindTypes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 220,
                                    "char": 108
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 220,
                                "char": 108
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 220,
                        "char": 108
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 220,
                    "last-line": 232,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rightJoin",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 233,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 233,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 233,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 233,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 233,
                            "char": 77
                        }
                    ],
                    "docblock": "**\n     * Adds a RIGHT join to the query\n     *\n     *```php\n     * $criteria->rightJoin(\n     *     Robots::class,\n     *     \"r.id = RobotsParts.robots_id\",\n     *     \"r\"\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 233,
                                    "char": 101
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 233,
                                "char": 101
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 233,
                        "char": 101
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 233,
                    "last-line": 237,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setModelName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 238,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Set a model on which the query will be executed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 238,
                                    "char": 75
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 238,
                                "char": 75
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 238,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 238,
                    "last-line": 242,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sharedLock",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sharedLock",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 243,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 243,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Sets the \"shared_lock\" parameter to the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 243,
                                    "char": 78
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 243,
                                "char": 78
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 243,
                        "char": 78
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 243,
                    "last-line": 247,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "where",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                            "line": 248,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets the conditions parameter in the criteria\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CriteriaInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                    "line": 248,
                                    "char": 69
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                                "line": 248,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                        "line": 248,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
                    "line": 248,
                    "last-line": 249,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
            "line": 249,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/CriteriaInterface.zep",
        "line": 0,
        "char": 0
    }
]