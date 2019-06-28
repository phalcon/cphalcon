[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Adapter",
        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Formatter\\FormatterInterface",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                "line": 13,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\AdapterInterface\n *\n * Interface for Phalcon\\Logger adapters\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
        "line": 21,
        "char": 9
    },
    {
        "type": "interface",
        "name": "AdapterInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "add",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "item",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Item",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 26,
                                "char": 35
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                            "line": 26,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Adds a message in the queue\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 26,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "begin",
                    "docblock": "**\n     * Starts a transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                    "line": 31,
                                    "char": 50
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 31,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 31,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "close",
                    "docblock": "**\n     * Closes the logger\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 36,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 36,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "commit",
                    "docblock": "**\n     * Commits the internal transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                    "line": 41,
                                    "char": 51
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 41,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 41,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFormatter",
                    "docblock": "**\n     * Returns the internal formatter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FormatterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                    "line": 46,
                                    "char": 59
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 46,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 46,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "process",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "item",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Item",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 51,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                            "line": 51,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Processes the message in the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 51,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
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
                    "docblock": "**\n     * Rollbacks the internal transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                    "line": 56,
                                    "char": 53
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 56,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 56,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFormatter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "formatter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "FormatterInterface",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 61,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                            "line": 61,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Sets the message formatter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                    "line": 61,
                                    "char": 87
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                                "line": 61,
                                "char": 87
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                        "line": 61,
                        "char": 87
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
                    "line": 61,
                    "last-line": 62,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
            "line": 62,
            "char": 1
        },
        "file": "\/app\/phalcon\/Logger\/Adapter\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]