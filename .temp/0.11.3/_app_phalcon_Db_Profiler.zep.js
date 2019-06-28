[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Profiler.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/Profiler.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Profiler\\Item",
                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Db\/Profiler.zep",
        "line": 65,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Instances of Phalcon\\Db can generate execution profiles\n * on SQL statements sent to the relational database. Profiled\n * information includes execution time in milliseconds.\n * This helps you to identify bottlenecks in your applications.\n *\n * ```php\n * use Phalcon\\Db\\Profiler;\n * use Phalcon\\Events\\Event;\n * use Phalcon\\Events\\Manager;\n *\n * $profiler = new Profiler();\n * $eventsManager = new Manager();\n *\n * $eventsManager->attach(\n *     \"db\",\n *     function (Event $event, $connection) use ($profiler) {\n *         if ($event->getType() === \"beforeQuery\") {\n *             $sql = $connection->getSQLStatement();\n *\n *             \/\/ Start a profile with the active connection\n *             $profiler->startProfile($sql);\n *         }\n *\n *         if ($event->getType() === \"afterQuery\") {\n *             \/\/ Stop the active profile\n *             $profiler->stopProfile();\n *         }\n *     }\n * );\n *\n * \/\/ Set the event manager on the connection\n * $connection->setEventsManager($eventsManager);\n *\n *\n * $sql = \"SELECT buyer_name, quantity, product_name\n * FROM buyers LEFT JOIN products ON\n * buyers.pid=products.id\";\n *\n * \/\/ Execute a SQL statement\n * $connection->query($sql);\n *\n * \/\/ Get the last profile in the profiler\n * $profile = $profiler->getLastProfile();\n *\n * echo \"SQL Statement: \", $profile->getSQLStatement(), \"\\n\";\n * echo \"Start Time: \", $profile->getInitialTime(), \"\\n\";\n * echo \"Final Time: \", $profile->getFinalTime(), \"\\n\";\n * echo \"Total Elapsed Time: \", $profile->getTotalElapsedSeconds(), \"\\n\";\n * ```\n *",
        "file": "\/app\/phalcon\/Db\/Profiler.zep",
        "line": 66,
        "char": 5
    },
    {
        "type": "class",
        "name": "Profiler",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeProfile",
                    "docblock": "**\n     * Active Phalcon\\Db\\Profiler\\Item\n     *\n     * @var Phalcon\\Db\\Profiler\\Item\n     *",
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 79,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "allProfiles",
                    "docblock": "**\n     * All the Phalcon\\Db\\Profiler\\Item in the active profile\n     *\n     * @var \\Phalcon\\Db\\Profiler\\Item[]\n     *",
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 86,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "totalSeconds",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 87,
                        "char": 31
                    },
                    "docblock": "**\n     * Total time spent by all profiles to complete\n     *\n     * @var float\n     *",
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 91,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastProfile",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 94,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "activeProfile",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 94,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 94,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the last profile executed in the profiler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Item",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 93,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 93,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 92,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNumberTotalStatements",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 102,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "allProfiles",
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 102,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 102,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 102,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 102,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the total number of SQL statements processed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 101,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 100,
                    "last-line": 107,
                    "char": 19
                },
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
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 110,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "totalSeconds",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 110,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 110,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the total time in seconds spent by the profiles\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "double",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 108,
                    "last-line": 115,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getProfiles",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 118,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "allProfiles",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 118,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 118,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 119,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns all the processed profiles\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Item",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 117,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 117,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 117,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 116,
                    "last-line": 123,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "allProfiles",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 126,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 126,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 128,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 128,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets the profiler, cleaning up all the profiles\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Profiler",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 125,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 125,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 125,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 124,
                    "last-line": 133,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "startProfile",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlStatement",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 134,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "sqlVariables",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 134,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 134,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "sqlBindTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 134,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 134,
                            "char": 103
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "activeProfile",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 136,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 138,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "activeProfile",
                                    "expr": {
                                        "type": "new",
                                        "class": "Item",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 138,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 138,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 140,
                            "char": 21
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "activeProfile",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 140,
                                    "char": 23
                                },
                                "name": "setSqlStatement",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sqlStatement",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 140,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 140,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 140,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 142,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "sqlVariables",
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 142,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 142,
                                    "char": 33
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 142,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 142,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "activeProfile",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 143,
                                            "char": 27
                                        },
                                        "name": "setSqlVariables",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sqlVariables",
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 143,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 143,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 143,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 144,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 146,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "sqlBindTypes",
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 146,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 146,
                                    "char": 33
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 146,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 146,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "activeProfile",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 147,
                                            "char": 27
                                        },
                                        "name": "setSqlBindTypes",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sqlBindTypes",
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 147,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 147,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 147,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 148,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 150,
                            "char": 21
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "activeProfile",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 150,
                                    "char": 23
                                },
                                "name": "setInitialTime",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "microtime",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                        "line": 150,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 150,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 150,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 150,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 150,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 152,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 152,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 152,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "beforeStartProfile",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 152,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 152,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 152,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 153,
                                            "char": 18
                                        },
                                        "name": "beforeStartProfile",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "activeProfile",
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 153,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 153,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 153,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 154,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 156,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeProfile",
                                    "expr": {
                                        "type": "variable",
                                        "value": "activeProfile",
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 156,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 156,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 158,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 158,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 159,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Starts the profile of a SQL sentence\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Profiler",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 135,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 134,
                    "last-line": 163,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "stopProfile",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "finalTime",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 166,
                                    "char": 22
                                },
                                {
                                    "variable": "initialTime",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 166,
                                    "char": 35
                                },
                                {
                                    "variable": "activeProfile",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 166,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 168,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "finalTime",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "microtime",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 168,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 168,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 168,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 168,
                                    "char": 40
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "activeProfile",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "Item",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 169,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 169,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "activeProfile",
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 169,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 169,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 169,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 169,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 171,
                            "char": 21
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "activeProfile",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 171,
                                    "char": 23
                                },
                                "name": "setFinalTime",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "finalTime",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 171,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 171,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 171,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 173,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "initialTime",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "activeProfile",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 173,
                                            "char": 41
                                        },
                                        "name": "getInitialTime",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 173,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 173,
                                    "char": 58
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "totalSeconds",
                                    "expr": {
                                        "type": "add",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 174,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "totalSeconds",
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 174,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 174,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "list",
                                            "left": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "finalTime",
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 174,
                                                    "char": 66
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "initialTime",
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 174,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 174,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 174,
                                            "char": 80
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 174,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 174,
                                    "char": 80
                                },
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "allProfiles",
                                    "expr": {
                                        "type": "variable",
                                        "value": "activeProfile",
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 175,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 175,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 177,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 177,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 177,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "afterEndProfile",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 177,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 177,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 177,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                            "line": 178,
                                            "char": 18
                                        },
                                        "name": "afterEndProfile",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "activeProfile",
                                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                    "line": 178,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                                "line": 178,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                        "line": 178,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 179,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 181,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 181,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Profiler.zep",
                            "line": 182,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stops the active profile\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Profiler",
                                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                    "line": 165,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Profiler.zep",
                                "line": 165,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Profiler.zep",
                        "line": 165,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Profiler.zep",
                    "line": 164,
                    "last-line": 183,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/Profiler.zep",
            "line": 66,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Profiler.zep",
        "line": 66,
        "char": 5
    }
]