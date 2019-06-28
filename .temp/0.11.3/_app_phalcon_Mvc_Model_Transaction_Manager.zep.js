[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Transaction",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 15,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 16,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Transaction\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 17,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Transaction",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 18,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\TransactionInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 19,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 67,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Transaction\\Manager\n *\n * A transaction acts on a single database connection. If you have multiple\n * class-specific databases, the transaction will not protect interaction among\n * them.\n *\n * This class manages the objects that compose a transaction.\n * A transaction produces a unique connection that is passed to every object\n * part of the transaction.\n *\n * ```php\n * use Phalcon\\Mvc\\Model\\Transaction\\Failed;\n * use Phalcon\\Mvc\\Model\\Transaction\\Manager;\n *\n * try {\n *    $transactionManager = new Manager();\n *\n *    $transaction = $transactionManager->get();\n *\n *    $robot = new Robots();\n *\n *    $robot->setTransaction($transaction);\n *\n *    $robot->name       = \"WALL\u00b7E\";\n *    $robot->created_at = date(\"Y-m-d\");\n *\n *    if ($robot->save() === false) {\n *        $transaction->rollback(\"Can't save robot\");\n *    }\n *\n *    $robotPart = new RobotParts();\n *\n *    $robotPart->setTransaction($transaction);\n *\n *    $robotPart->type = \"head\";\n *\n *    if ($robotPart->save() === false) {\n *        $transaction->rollback(\"Can't save robot part\");\n *    }\n *\n *    $transaction->commit();\n * } catch (Failed $e) {\n *    echo \"Failed, reason: \", $e->getMessage();\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 68,
        "char": 5
    },
    {
        "type": "class",
        "name": "Manager",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 68,
                "char": 42
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                "line": 69,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 72,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "initialized",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 72,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 74,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "number",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 74,
                        "char": 25
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 76,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "rollbackPendent",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 76,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 78,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "service",
                    "default": {
                        "type": "string",
                        "value": "db",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 78,
                        "char": 27
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 82,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "transactions",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 83,
                        "char": 32
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 87,
                    "char": 6
                }
            ],
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
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 88,
                                "char": 55
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 88,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 88,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 90,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 90,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "container",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Di",
                                                "dynamic": 0,
                                                "name": "getDefault",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 91,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 91,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 92,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 94,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 94,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 94,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 96,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 96,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 96,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 96,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 96,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 96,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Exception",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "the services related to the ORM",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                "line": 100,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                            "line": 100,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 101,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 101,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 101,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 102,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Transaction\\Manager constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 89,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 88,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "collectTransactions",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "transactions",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 110,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 112,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "transactions",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 112,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "transactions",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 112,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 112,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 112,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 114,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "transactions",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 114,
                                "char": 31
                            },
                            "value": "_",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-decr",
                                            "variable": "this",
                                            "property": "number",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 115,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 116,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 118,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "transactions",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 118,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 118,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 119,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Remove all the transactions from the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 108,
                    "last-line": 123,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "commit",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "transactions",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 126,
                                    "char": 25
                                },
                                {
                                    "variable": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 126,
                                    "char": 38
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 126,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 128,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "transactions",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 128,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "transactions",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 128,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 128,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 128,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 130,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "transactions",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 130,
                                "char": 41
                            },
                            "value": "transaction",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "connection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "transaction",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 131,
                                                    "char": 42
                                                },
                                                "name": "getConnection",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 131,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 131,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 133,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 133,
                                            "char": 27
                                        },
                                        "name": "isUnderTransaction",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 133,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 134,
                                                    "char": 28
                                                },
                                                "name": "commit",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 134,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 135,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 136,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 137,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Commits active transactions within the manager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 124,
                    "last-line": 142,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 143,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 143,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 145,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "initialized",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 145,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 145,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 145,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 146,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rollbackPendent",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 146,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 146,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "register_shutdown_function",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                        "line": 149,
                                                                        "char": 29
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                    "line": 149,
                                                                    "char": 29
                                                                },
                                                                {
                                                                    "value": {
                                                                        "type": "string",
                                                                        "value": "rollbackPendent",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                        "line": 151,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                    "line": 151,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                            "line": 152,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 152,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 152,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 153,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 155,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "initialized",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 155,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 155,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 156,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 158,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 158,
                                    "char": 21
                                },
                                "name": "getOrCreateTransaction",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "autoBegin",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 158,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 158,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 158,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 159,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a new \\Phalcon\\Mvc\\Model\\Transaction or an already created once\n     * This method registers a shutdown function to rollback active connections\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TransactionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 144,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 144,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 144,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 143,
                    "last-line": 163,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDbService",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 166,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "service",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 166,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 166,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 167,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the database service used to isolate the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 165,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 165,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 164,
                    "last-line": 171,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 174,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 174,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 174,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 175,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the dependency injection container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 173,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 173,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 173,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 172,
                    "last-line": 179,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOrCreateTransaction",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 180,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 180,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 182,
                                    "char": 22
                                },
                                {
                                    "variable": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 182,
                                    "char": 35
                                },
                                {
                                    "variable": "transactions",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 182,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 184,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "DiInterface",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 184,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 184,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 184,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 184,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 184,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 184,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 186,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 186,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 186,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 186,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 186,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 186,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Exception",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "the services related to the ORM",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                "line": 190,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                            "line": 190,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 191,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 191,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 191,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 192,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 194,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 194,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "number",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 194,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 194,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "transactions",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 195,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "transactions",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 195,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 195,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 195,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 197,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "transactions",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 197,
                                        "char": 53
                                    },
                                    "value": "transaction",
                                    "reverse": 1,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "transaction",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 198,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 198,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 198,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 198,
                                                "char": 49
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "transaction",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                            "line": 199,
                                                            "char": 33
                                                        },
                                                        "name": "setIsNewTransaction",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "bool",
                                                                    "value": "false",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                    "line": 199,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                                "line": 199,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 199,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 201,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "transaction",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 201,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 202,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 203,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 204,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 206,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "transaction",
                                    "expr": {
                                        "type": "new",
                                        "class": "Transaction",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 206,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 206,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "autoBegin",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 206,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 206,
                                                "char": 63
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 206,
                                                        "char": 70
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "service",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 206,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 206,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 206,
                                                "char": 78
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 206,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 206,
                                    "char": 79
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 207,
                            "char": 23
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 207,
                                    "char": 25
                                },
                                "name": "setTransactionManager",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 207,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 207,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 207,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 209,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "transactions",
                                    "expr": {
                                        "type": "variable",
                                        "value": "transaction",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 209,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 209,
                                    "char": 47
                                },
                                {
                                    "assign-type": "object-property-incr",
                                    "variable": "this",
                                    "property": "number",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 209,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 211,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "transaction",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 211,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 212,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create\/Returns a new transaction or an existing one\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TransactionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 181,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 181,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 181,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 180,
                    "last-line": 217,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRollbackPendent",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 220,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "rollbackPendent",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 220,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 220,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 221,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the transaction manager is registering a shutdown function to\n     * clean up pendent transactions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 219,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 219,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 218,
                    "last-line": 225,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 228,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "number",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 228,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 228,
                                    "char": 29
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 228,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 228,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 229,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether the manager has an active transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 227,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 227,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 226,
                    "last-line": 233,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 234,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 234,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 236,
                                    "char": 14
                                },
                                "name": "collectTransaction",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "transaction",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 236,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 236,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 236,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 237,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Notifies the manager about a committed transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 235,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 234,
                    "last-line": 241,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 242,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 242,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 244,
                                    "char": 14
                                },
                                "name": "collectTransaction",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "transaction",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 244,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 244,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 244,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 245,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Notifies the manager about a rollbacked transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 243,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 242,
                    "last-line": 250,
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
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 251,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 251,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "transactions",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 253,
                                    "char": 25
                                },
                                {
                                    "variable": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 253,
                                    "char": 38
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 253,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 255,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "transactions",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 255,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "transactions",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 255,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 255,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 255,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 257,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "transactions",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 257,
                                "char": 41
                            },
                            "value": "transaction",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "connection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "transaction",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 258,
                                                    "char": 42
                                                },
                                                "name": "getConnection",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 258,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 258,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 260,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 260,
                                            "char": 27
                                        },
                                        "name": "isUnderTransaction",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 260,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 261,
                                                    "char": 28
                                                },
                                                "name": "rollback",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 261,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 262,
                                            "char": 26
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 262,
                                                    "char": 28
                                                },
                                                "name": "close",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 262,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 263,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 265,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "collect",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 265,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 266,
                                                    "char": 22
                                                },
                                                "name": "collectTransaction",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "transaction",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                            "line": 266,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 266,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                "line": 266,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 267,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 268,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 269,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rollbacks active transactions within the manager\n     * Collect will remove the transaction from the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 252,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 251,
                    "last-line": 273,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rollbackPendent",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 276,
                                    "char": 14
                                },
                                "name": "rollback",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 276,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 277,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rollbacks active transactions within the manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 275,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 274,
                    "last-line": 281,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 282,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "service",
                                    "expr": {
                                        "type": "variable",
                                        "value": "service",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 284,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 284,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 286,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 286,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 287,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 283,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 283,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 283,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 282,
                    "last-line": 291,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDI",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 292,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 292,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 294,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 294,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 295,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injection container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 293,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 292,
                    "last-line": 300,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 301,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "rollbackPendent",
                                    "expr": {
                                        "type": "variable",
                                        "value": "rollbackPendent",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 303,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 303,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 305,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 305,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 306,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set if the transaction manager must register a shutdown function to clean\n     * up pendent transactions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 302,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 302,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 302,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 301,
                    "last-line": 310,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "collectTransaction",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 311,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 311,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "managedTransaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 313,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 314,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "newTransactions",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 314,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 316,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newTransactions",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 316,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 316,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 318,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 318,
                                    "char": 40
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "transactions",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 318,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                "line": 318,
                                "char": 54
                            },
                            "value": "managedTransaction",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "managedTransaction",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 319,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "transaction",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 319,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 319,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "newTransactions",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "transaction",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                        "line": 320,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 320,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 321,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-decr",
                                                    "variable": "this",
                                                    "property": "number",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                                    "line": 322,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                            "line": 323,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 324,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 326,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "transactions",
                                    "expr": {
                                        "type": "variable",
                                        "value": "newTransactions",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                        "line": 326,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                                    "line": 326,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                            "line": 327,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes transactions from the TransactionManager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                        "line": 312,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
                    "line": 311,
                    "last-line": 328,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
            "line": 68,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Manager.zep",
        "line": 68,
        "char": 5
    }
]