[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Query",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\QueryInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                "line": 13,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Query\\BuilderInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Query\\Builder\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "BuilderInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addFrom",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 28,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 28,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 28,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Add a model to take part of the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 28,
                                    "char": 85
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 28,
                                "char": 85
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 28,
                        "char": 85
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 33,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 33,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 33,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 33,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 33,
                            "char": 92
                        }
                    ],
                    "docblock": "**\n     * Appends a condition to the current conditions using a AND operator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 33,
                                    "char": 115
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 33,
                                "char": 115
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 33,
                        "char": 115
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 33,
                    "last-line": 40,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 41,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "minimum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 41,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "maximum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 41,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "operator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 41,
                                    "char": 115
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "OPERATOR_AND",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 41,
                                    "char": 115
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 41,
                                "char": 115
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 41,
                            "char": 115
                        }
                    ],
                    "docblock": "**\n     * Appends a BETWEEN condition to the current conditions\n     *\n     * @param mixed minimum\n     * @param mixed maximum\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 41,
                                    "char": 138
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 41,
                                "char": 138
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 41,
                        "char": 138
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 41,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "columns",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "columns",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 48,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Sets the columns to be queried\n     *\n     * @param string|array columns\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 48,
                                    "char": 59
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 48,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 48,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 48,
                    "last-line": 57,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 58,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Sets SELECT DISTINCT \/ SELECT ALL flag\n     *\n     *```php\n     * $builder->distinct(\"status\");\n     * $builder->distinct(null);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 58,
                                    "char": 65
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 58,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 58,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 58,
                    "last-line": 66,
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
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 67,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets a FOR UPDATE clause\n     *\n     *```php\n     * $builder->forUpdate(true);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 67,
                                    "char": 68
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 67,
                                "char": 68
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 67,
                        "char": 68
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 67,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "from",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "models",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 74,
                            "char": 32
                        }
                    ],
                    "docblock": "**\n     * Sets the models who makes part of the query\n     *\n     * @param string|array models\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 74,
                                    "char": 55
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 74,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 74,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 74,
                    "last-line": 78,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 79,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 79,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 79,
                    "last-line": 83,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 84,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 84,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 84,
                    "last-line": 90,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumns",
                    "docblock": "**\n     * Return the columns to be queried\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 91,
                    "last-line": 95,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDistinct",
                    "docblock": "**\n     * Returns SELECT DISTINCT \/ SELECT ALL flag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 96,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 96,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 96,
                    "last-line": 102,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFrom",
                    "docblock": "**\n     * Return the models who makes part of the query\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 103,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getGroupBy",
                    "docblock": "**\n     * Returns the GROUP BY clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 108,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 108,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 108,
                    "last-line": 112,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHaving",
                    "docblock": "**\n     * Returns the HAVING condition clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 113,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 113,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 113,
                    "last-line": 117,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getJoins",
                    "docblock": "**\n     * Return join parts of the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 118,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 118,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 118,
                    "last-line": 124,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLimit",
                    "docblock": "**\n     * Returns the current LIMIT clause\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 125,
                    "last-line": 129,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOffset",
                    "docblock": "**\n     * Returns the current OFFSET clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 130,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 130,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 130,
                    "last-line": 136,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOrderBy",
                    "docblock": "**\n     * Return the set ORDER BY clause\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 137,
                    "last-line": 141,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPhql",
                    "docblock": "**\n     * Returns a PHQL statement built based on the builder parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 142,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 142,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 142,
                    "last-line": 146,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getQuery",
                    "docblock": "**\n     * Returns the query built\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 147,
                                    "char": 51
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 147,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 147,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 147,
                    "last-line": 153,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getWhere",
                    "docblock": "**\n     * Return the conditions for the query\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 154,
                    "last-line": 160,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 161,
                            "char": 38
                        }
                    ],
                    "docblock": "**\n     * Sets a GROUP BY clause\n     *\n     * @param string|array group\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 161,
                                    "char": 61
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 161,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 161,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 161,
                    "last-line": 165,
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
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 166,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Sets a HAVING condition clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 166,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 166,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 166,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 166,
                    "last-line": 170,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 171,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 171,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 171,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 171,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 171,
                            "char": 90
                        }
                    ],
                    "docblock": "**\n     * Adds an INNER join to the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 171,
                                    "char": 113
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 171,
                                "char": 113
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 171,
                        "char": 113
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 171,
                    "last-line": 175,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 176,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 176,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "operator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 176,
                                    "char": 107
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "OPERATOR_AND",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 176,
                                    "char": 107
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 176,
                                "char": 107
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 176,
                            "char": 107
                        }
                    ],
                    "docblock": "**\n     * Appends an IN condition to the current conditions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 176,
                                    "char": 130
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 176,
                                "char": 130
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 176,
                        "char": 130
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 176,
                    "last-line": 186,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "join",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 187,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 187,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 187,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 187,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 187,
                            "char": 85
                        }
                    ],
                    "docblock": "**\n     * Adds an :type: join (by default type - INNER) to the query\n     *\n     * @param string model\n     * @param string conditions\n     * @param string alias\n     * @param string type\n     * @return BuilderInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 187,
                                    "char": 108
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 187,
                                "char": 108
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 187,
                        "char": 108
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 187,
                    "last-line": 191,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 192,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 192,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 192,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 192,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 192,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Adds a LEFT join to the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 192,
                                    "char": 112
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 192,
                                "char": 112
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 192,
                        "char": 112
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 192,
                    "last-line": 198,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 199,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 199,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 199,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets a LIMIT clause\n     *\n     * @param int offset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 199,
                                    "char": 74
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 199,
                                "char": 74
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 199,
                        "char": 74
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 199,
                    "last-line": 203,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModels",
                    "docblock": "**\n     * Returns the models involved in the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 204,
                                "char": 43
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 204,
                                "char": 51
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 204,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 204,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 204,
                    "last-line": 211,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 212,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "minimum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 212,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "maximum",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 212,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "operator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 212,
                                    "char": 118
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "OPERATOR_AND",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 212,
                                    "char": 118
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 212,
                                "char": 118
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 212,
                            "char": 118
                        }
                    ],
                    "docblock": "**\n     * Appends a NOT BETWEEN condition to the current conditions\n     *\n     * @param mixed minimum\n     * @param mixed maximum\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 212,
                                    "char": 141
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 212,
                                "char": 141
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 212,
                        "char": 141
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 212,
                    "last-line": 216,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 217,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 217,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "operator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 217,
                                    "char": 110
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "OPERATOR_AND",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 217,
                                    "char": 110
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 217,
                                "char": 110
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 217,
                            "char": 110
                        }
                    ],
                    "docblock": "**\n     * Appends a NOT IN condition to the current conditions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 217,
                                    "char": 133
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 217,
                                "char": 133
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 217,
                        "char": 133
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 217,
                    "last-line": 221,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 222,
                            "char": 38
                        }
                    ],
                    "docblock": "**\n     * Sets an OFFSET clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 222,
                                    "char": 61
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 222,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 222,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 222,
                    "last-line": 226,
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
                            "name": "orderBy",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 227,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Sets an ORDER BY condition clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 227,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 227,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 227,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 227,
                    "last-line": 231,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 232,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 232,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 232,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 232,
                                "char": 91
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 232,
                            "char": 91
                        }
                    ],
                    "docblock": "**\n     * Appends a condition to the current conditions using an OR operator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 232,
                                    "char": 114
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 232,
                                "char": 114
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 232,
                        "char": 114
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 232,
                    "last-line": 236,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 237,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 237,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 237,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 237,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 237,
                            "char": 90
                        }
                    ],
                    "docblock": "**\n     * Adds a RIGHT join to the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 237,
                                    "char": 113
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 237,
                                "char": 113
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 237,
                        "char": 113
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 237,
                    "last-line": 241,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 242,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 242,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 242,
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
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 242,
                                    "char": 95
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 242,
                                "char": 95
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 242,
                        "char": 95
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 242,
                    "last-line": 246,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 247,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 247,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 247,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Set default bind types\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 247,
                                    "char": 93
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 247,
                                "char": 93
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 247,
                        "char": 93
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 247,
                    "last-line": 251,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 252,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 252,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 252,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 252,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                            "line": 252,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Sets conditions for the query\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                    "line": 252,
                                    "char": 112
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                                "line": 252,
                                "char": 112
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 252,
                        "char": 112
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 252,
                    "last-line": 253,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "OPERATOR_AND",
                    "default": {
                        "type": "string",
                        "value": "and",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 22,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 23,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "OPERATOR_OR",
                    "default": {
                        "type": "string",
                        "value": "or",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                        "line": 23,
                        "char": 27
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
                    "line": 27,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
            "line": 253,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/BuilderInterface.zep",
        "line": 0,
        "char": 0
    }
]