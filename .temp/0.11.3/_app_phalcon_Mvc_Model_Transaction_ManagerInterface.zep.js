[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Transaction",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\TransactionInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                "line": 13,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Transaction\\Manager\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ManagerInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "collectTransactions",
                    "docblock": "**\n     * Remove all the transactions from the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 25,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "commit",
                    "docblock": "**\n     * Commits active transactions within the manager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "autoBegin",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 35,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                            "line": 35,
                            "char": 46
                        }
                    ],
                    "docblock": "**\n     * Returns a new \\Phalcon\\Mvc\\Model\\Transaction or an already created once\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TransactionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                    "line": 35,
                                    "char": 73
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 35,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 35,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDbService",
                    "docblock": "**\n     * Returns the database service used to isolate the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 40,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 40,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 40,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRollbackPendent",
                    "docblock": "**\n     * Check if the transaction manager is registering a shutdown function to clean up pendent transactions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 45,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 45,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 45,
                    "last-line": 49,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "docblock": "**\n     * Checks whether manager has an active transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 50,
                                "char": 34
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 50,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 50,
                    "last-line": 54,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notifyCommit",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 55,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                            "line": 55,
                            "char": 68
                        }
                    ],
                    "docblock": "**\n     * Notifies the manager about a committed transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 55,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 55,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notifyRollback",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 60,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                            "line": 60,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Notifies the manager about a rollbacked transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 60,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 60,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rollback",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collect",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 66,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                            "line": 66,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Rollbacks active transactions within the manager\n     * Collect will remove transaction from the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 66,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 66,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rollbackPendent",
                    "docblock": "**\n     * Rollbacks active transactions within the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 71,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 71,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDbService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "service",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                            "line": 76,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets the database service used to run the isolated transactions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                    "line": 76,
                                    "char": 72
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 76,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 76,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRollbackPendent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "rollbackPendent",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                            "line": 81,
                            "char": 60
                        }
                    ],
                    "docblock": "**\n     * Set if the transaction manager must register a shutdown function to clean up pendent transactions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                    "line": 81,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                                "line": 81,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                        "line": 81,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
                    "line": 81,
                    "last-line": 82,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
            "line": 82,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/ManagerInterface.zep",
        "line": 0,
        "char": 0
    }
]