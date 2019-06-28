[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                "line": 14,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\TransactionInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Transaction\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
        "line": 21,
        "char": 9
    },
    {
        "type": "interface",
        "name": "TransactionInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "begin",
                    "docblock": "**\n     * Starts the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 26,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 26,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "commit",
                    "docblock": "**\n     * Commits the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 31,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 31,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnection",
                    "docblock": "**\n     * Returns connection related to transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "\\Phalcon\\Db\\AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                    "line": 36,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 36,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 36,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "docblock": "**\n     * Returns validations messages from last save try\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 41,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 41,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isManaged",
                    "docblock": "**\n     * Checks whether transaction is managed by a transaction manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 46,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 46,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isValid",
                    "docblock": "**\n     * Checks whether internal connection is under an active transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 51,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 51,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 51,
                    "last-line": 55,
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
                            "name": "rollbackMessage",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 56,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                            "line": 56,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "rollbackRecord",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 56,
                                "char": 91
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 56,
                                "char": 99
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                            "line": 56,
                            "char": 99
                        }
                    ],
                    "docblock": "**\n     * Rollbacks the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 56,
                                "char": 108
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 56,
                        "char": 108
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setIsNewTransaction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "isNew",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                            "line": 61,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets if is a reused transaction or new once\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 61,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRollbackOnAbort",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "rollbackOnAbort",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                            "line": 66,
                            "char": 60
                        }
                    ],
                    "docblock": "**\n     * Sets flag to rollback on abort the HTTP connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 66,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 66,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRollbackedRecord",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 71,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                            "line": 71,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Sets object which generates rollback action\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 71,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 71,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTransactionManager",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "manager",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ManagerInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 76,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                            "line": 76,
                            "char": 69
                        }
                    ],
                    "docblock": "**\n     * Sets transaction manager related to the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 76,
                        "char": 78
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "throwRollbackException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "status",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                            "line": 81,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Enables throwing exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TransactionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                    "line": 81,
                                    "char": 82
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                                "line": 81,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                        "line": 81,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
                    "line": 81,
                    "last-line": 82,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
            "line": 82,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/TransactionInterface.zep",
        "line": 0,
        "char": 0
    }
]