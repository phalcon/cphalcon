[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Query",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Query\\StatusInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Query\\Status\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
        "line": 21,
        "char": 9
    },
    {
        "type": "interface",
        "name": "StatusInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "docblock": "**\n     * Returns the messages produced by an operation failed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                                    "line": 26,
                                    "char": 58
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                                "line": 26,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                        "line": 26,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModel",
                    "docblock": "**\n     * Returns the model which executed the action\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                                    "line": 31,
                                    "char": 51
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                                "line": 31,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                        "line": 31,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "success",
                    "docblock": "**\n     * Allows to check if the executed operation was successful\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                                "line": 36,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                        "line": 36,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
                    "line": 36,
                    "last-line": 37,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
            "line": 37,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/StatusInterface.zep",
        "line": 0,
        "char": 0
    }
]