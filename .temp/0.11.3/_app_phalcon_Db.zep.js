[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Db.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "\\PDO",
                "alias": "Pdo",
                "file": "\/app\/phalcon\/Db.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Db.zep",
        "line": 57,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Db and its related classes provide a simple SQL database interface\n * for Phalcon Framework. The Phalcon\\Db is the basic class you use to connect\n * your PHP application to an RDBMS. There is a different adapter class for each\n * brand of RDBMS.\n *\n * This component is intended to lower level database operations. If you want to\n * interact with databases using higher level of abstraction use\n * Phalcon\\Mvc\\Model.\n *\n * Phalcon\\Db is an abstract class. You only can use it with a database adapter\n * like Phalcon\\Db\\Adapter\\Pdo\n *\n *```php\n * use Phalcon\\Db;\n * use Phalcon\\Db\\Exception;\n * use Phalcon\\Db\\Adapter\\Pdo\\Mysql as MysqlConnection;\n *\n * try {\n *     $connection = new MysqlConnection(\n *         [\n *             \"host\"     => \"192.168.0.11\",\n *             \"username\" => \"sigma\",\n *             \"password\" => \"secret\",\n *             \"dbname\"   => \"blog\",\n *             \"port\"     => \"3306\",\n *         ]\n *     );\n *\n *     $result = $connection->query(\n *         \"SELECT * FROM robots LIMIT 5\"\n *     );\n *\n *     $result->setFetchMode(Db::FETCH_NUM);\n *\n *     while ($robot = $result->fetch()) {\n *         print_r($robot);\n *     }\n * } catch (Exception $e) {\n *     echo $e->getMessage(), PHP_EOL;\n * }\n * ```\n *",
        "file": "\/app\/phalcon\/Db.zep",
        "line": 58,
        "char": 8
    },
    {
        "type": "class",
        "name": "Db",
        "abstract": 1,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setup",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 81,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "escapeIdentifiers",
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 83,
                                    "char": 30
                                },
                                {
                                    "variable": "forceCasting",
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 83,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 88,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "escapeIdentifiers",
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 88,
                                    "char": 67
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db.zep",
                                        "line": 88,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "escapeSqlIdentifiers",
                                        "file": "\/app\/phalcon\/Db.zep",
                                        "line": 88,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 88,
                                    "char": 67
                                },
                                "file": "\/app\/phalcon\/Db.zep",
                                "line": 88,
                                "char": 67
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "globals_set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "db.escape_identifiers",
                                                    "file": "\/app\/phalcon\/Db.zep",
                                                    "line": 89,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Db.zep",
                                                "line": 89,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeIdentifiers",
                                                    "file": "\/app\/phalcon\/Db.zep",
                                                    "line": 89,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Db.zep",
                                                "line": 89,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db.zep",
                                        "line": 89,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 95,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "forceCasting",
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 95,
                                    "char": 54
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Db.zep",
                                        "line": 95,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "forceCasting",
                                        "file": "\/app\/phalcon\/Db.zep",
                                        "line": 95,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 95,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Db.zep",
                                "line": 95,
                                "char": 54
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "globals_set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "db.force_casting",
                                                    "file": "\/app\/phalcon\/Db.zep",
                                                    "line": 96,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Db.zep",
                                                "line": 96,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "forceCasting",
                                                    "file": "\/app\/phalcon\/Db.zep",
                                                    "line": 96,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db.zep",
                                                "line": 96,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db.zep",
                                        "line": 96,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Db.zep",
                                    "line": 97,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 98,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Enables\/disables options in the Database component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 82,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 81,
                    "last-line": 99,
                    "char": 26
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "FETCH_ASSOC",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 60,
                            "char": 47
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_ASSOC",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 60,
                            "char": 47
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 60,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 61,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_BOTH",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 61,
                            "char": 46
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_BOTH",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 61,
                            "char": 46
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 61,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 62,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_BOUND",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 62,
                            "char": 47
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_BOUND",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 62,
                            "char": 47
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 62,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 63,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_CLASS",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 63,
                            "char": 47
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_CLASS",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 63,
                            "char": 47
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 63,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 64,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_CLASSTYPE",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 64,
                            "char": 51
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_CLASSTYPE",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 64,
                            "char": 51
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 64,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 65,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_COLUMN",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 65,
                            "char": 48
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_COLUMN",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 65,
                            "char": 48
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 65,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 66,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_FUNC",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 66,
                            "char": 46
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_FUNC",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 66,
                            "char": 46
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 66,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 67,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_GROUP",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 67,
                            "char": 47
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_GROUP",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 67,
                            "char": 47
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 67,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 68,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_INTO",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 68,
                            "char": 46
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_INTO",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 68,
                            "char": 46
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 68,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 69,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_KEY_PAIR",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 69,
                            "char": 50
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_KEY_PAIR",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 69,
                            "char": 50
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 69,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 70,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_LAZY",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 70,
                            "char": 46
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_LAZY",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 70,
                            "char": 46
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 70,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 71,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_NAMED",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 71,
                            "char": 47
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_NAMED",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 71,
                            "char": 47
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 71,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 72,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_NUM",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 72,
                            "char": 45
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_NUM",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 72,
                            "char": 45
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 72,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 73,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_OBJ",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 73,
                            "char": 45
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_OBJ",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 73,
                            "char": 45
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 73,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 74,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_PROPS_LATE",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 74,
                            "char": 52
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_PROPS_LATE",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 74,
                            "char": 52
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 74,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 75,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_SERIALIZE",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 75,
                            "char": 51
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_SERIALIZE",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 75,
                            "char": 51
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 75,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 76,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FETCH_UNIQUE",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "\\Pdo",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 76,
                            "char": 48
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_UNIQUE",
                            "file": "\/app\/phalcon\/Db.zep",
                            "line": 76,
                            "char": 48
                        },
                        "file": "\/app\/phalcon\/Db.zep",
                        "line": 76,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Db.zep",
                    "line": 80,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Db.zep",
            "line": 58,
            "char": 14
        },
        "file": "\/app\/phalcon\/Db.zep",
        "line": 58,
        "char": 14
    }
]