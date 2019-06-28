[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db\\Profiler",
        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class identifies each profile in a Phalcon\\Db\\Profiler\n *",
        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Item",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "finalTime",
                    "docblock": "**\n     * Timestamp when the profile ended\n     *\n     * @var double\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 23,
                            "char": 30
                        },
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 23,
                            "char": 36
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                    "line": 29,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "initialTime",
                    "docblock": "**\n     * Timestamp when the profile started\n     *\n     * @var double\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 30,
                            "char": 32
                        },
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 30,
                            "char": 38
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                    "line": 36,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sqlBindTypes",
                    "docblock": "**\n     * SQL bind types related to the profile\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 37,
                            "char": 33
                        },
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 37,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                    "line": 43,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sqlStatement",
                    "docblock": "**\n     * SQL statement related to the profile\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 44,
                            "char": 33
                        },
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 44,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sqlVariables",
                    "docblock": "**\n     * SQL variables related to the profile\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 51,
                            "char": 33
                        },
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 51,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                    "line": 55,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTotalElapsedSeconds",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "sub",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                        "line": 58,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "finalTime",
                                        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                        "line": 58,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                    "line": 58,
                                    "char": 32
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                        "line": 58,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "initialTime",
                                        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                        "line": 58,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                    "line": 58,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                "line": 58,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the total time in seconds spent by the profile\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "double",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                                "line": 57,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Profiler\/Item.zep",
        "line": 16,
        "char": 5
    }
]