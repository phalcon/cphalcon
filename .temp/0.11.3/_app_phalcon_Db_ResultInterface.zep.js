[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Db\\Result objects\n *",
        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ResultInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dataSeek",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "number",
                            "const": 0,
                            "data-type": "long",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                            "line": 22,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Moves internal resultset cursor to another position letting us to fetch a\n     * certain row\n     *",
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 22,
                    "last-line": 28,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "execute",
                    "docblock": "**\n     * Allows to executes the statement again. Some database systems don't\n     * support scrollable cursors. So, as cursors are forward only, we need to\n     * execute the cursor again to fetch rows from the begining\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                "line": 29,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                        "line": 29,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 29,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetch",
                    "docblock": "**\n     * Fetches an array\/object of strings that corresponds to the fetched row,\n     * or FALSE if there are no more rows. This method is affected by the active\n     * fetch flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                "line": 36,
                                "char": 35
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                        "line": 36,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 36,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetchAll",
                    "docblock": "**\n     * Returns an array of arrays containing all the records in the result. This\n     * method is affected by the active fetch flag set using\n     * `Phalcon\\Db\\Result\\Pdo::setFetchMode()`\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                "line": 43,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                        "line": 43,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 43,
                    "last-line": 49,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetchArray",
                    "docblock": "**\n     * Returns an array of strings that corresponds to the fetched row, or FALSE\n     * if there are no more rows. This method is affected by the active fetch\n     * flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                "line": 50,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                        "line": 50,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 50,
                    "last-line": 54,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getInternalResult",
                    "docblock": "**\n     * Gets the internal PDO result object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "\\PDOStatement",
                                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                    "line": 55,
                                    "char": 59
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                "line": 55,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                        "line": 55,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 55,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "numRows",
                    "docblock": "**\n     * Gets number of rows returned by a resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                "line": 60,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                        "line": 60,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 60,
                    "last-line": 64,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFetchMode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fetchMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                            "line": 65,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Changes the fetching mode affecting Phalcon\\Db\\Result\\Pdo::fetch()\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                                "line": 65,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                        "line": 65,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
                    "line": 65,
                    "last-line": 66,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
            "line": 66,
            "char": 1
        },
        "file": "\/app\/phalcon\/Db\/ResultInterface.zep",
        "line": 0,
        "char": 0
    }
]