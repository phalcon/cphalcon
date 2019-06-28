[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Query",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Query\\StatusInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                "line": 15,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
        "line": 43,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Query\\Status\n *\n * This class represents the status returned by a PHQL\n * statement like INSERT, UPDATE or DELETE. It offers context\n * information and the related messages produced by the\n * model which finally executes the operations when it fails\n *\n *```php\n * $phql = \"UPDATE Robots SET name = :name:, type = :type:, year = :year: WHERE id = :id:\";\n *\n * $status = $app->modelsManager->executeQuery(\n *     $phql,\n *     [\n *         \"id\"   => 100,\n *         \"name\" => \"Astroy Boy\",\n *         \"type\" => \"mechanical\",\n *         \"year\" => 1959,\n *     ]\n * );\n *\n * \/\/ Check if the update was successful\n * if ($status->success()) {\n *     echo \"OK\";\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
        "line": 44,
        "char": 5
    },
    {
        "type": "class",
        "name": "Status",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "StatusInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                "line": 45,
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
                    "name": "model",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                    "line": 48,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "success",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                    "line": 52,
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
                            "name": "success",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 53,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 53,
                                "char": 68
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 53,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 53,
                            "char": 76
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
                                    "property": "success",
                                    "expr": {
                                        "type": "variable",
                                        "value": "success",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                        "line": 55,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 55,
                                    "char": 36
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "model",
                                    "expr": {
                                        "type": "variable",
                                        "value": "model",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                        "line": 56,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 56,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 57,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Query\\Status\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                        "line": 54,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                    "line": 53,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "model",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 64,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 66,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "model",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                            "line": 66,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                            "line": 66,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                        "line": 66,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 66,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 68,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "model",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                        "line": 68,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 68,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 68,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 68,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                        "line": 69,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 70,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 72,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "model",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 72,
                                    "char": 22
                                },
                                "name": "getMessages",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 72,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the messages produced because of a failed operation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 63,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 63,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                    "line": 62,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModel",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 80,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "model",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 80,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 80,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 81,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the model that executed the action\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 79,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                    "line": 78,
                    "last-line": 85,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "success",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 88,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "success",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                    "line": 88,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 88,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                            "line": 89,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to check if the executed operation was successful\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                                "line": 87,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                        "line": 87,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
                    "line": 86,
                    "last-line": 90,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
            "line": 44,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Status.zep",
        "line": 44,
        "char": 5
    }
]