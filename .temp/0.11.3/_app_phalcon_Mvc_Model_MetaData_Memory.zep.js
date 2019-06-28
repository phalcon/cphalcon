[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaData\\Memory\n *\n * Stores model meta-data in memory. Data will be erased when the request finishes\n *\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
        "line": 22,
        "char": 5
    },
    {
        "type": "class",
        "name": "Memory",
        "abstract": 0,
        "final": 0,
        "extends": "MetaData",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                                "line": 29,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                            "line": 29,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\MetaData\\Memory constructor\n     *\n     * @param array options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                        "line": 30,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                    "line": 29,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "read",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                            "line": 36,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                                "line": 38,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                            "line": 39,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads the meta-data from temporal memory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                                "line": 36,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                                "line": 37,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                        "line": 37,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                    "line": 36,
                    "last-line": 43,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "write",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                            "line": 44,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                            "line": 44,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                            "line": 47,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes the meta-data to temporal memory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                        "line": 45,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
                    "line": 44,
                    "last-line": 48,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
            "line": 22,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Memory.zep",
        "line": 22,
        "char": 5
    }
]