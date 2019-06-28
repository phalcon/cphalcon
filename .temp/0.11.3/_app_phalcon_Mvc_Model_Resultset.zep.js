[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 14,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Countable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 15,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Iterator",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 16,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "JsonSerializable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 17,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 18,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 19,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 20,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 21,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 22,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\ResultsetInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 23,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 24,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 25,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 25,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 26,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "SeekableIterator",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 26,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 27,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Serializable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 27,
                "char": 17
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 69,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Resultset\n *\n * This component allows to Phalcon\\Mvc\\Model returns large resultsets with the minimum memory consumption\n * Resultsets can be traversed using a standard foreach or a while statement. If a resultset is serialized\n * it will dump all the rows into a big array. Then unserialize will retrieve the rows as they were before\n * serializing.\n *\n * ```php\n *\n * \/\/ Using a standard foreach\n * $robots = Robots::find(\n *     [\n *         \"type = 'virtual'\",\n *         \"order\" => \"name\",\n *     ]\n * );\n *\n * foreach ($robots as robot) {\n *     echo robot->name, \"\\n\";\n * }\n *\n * \/\/ Using a while\n * $robots = Robots::find(\n *     [\n *         \"type = 'virtual'\",\n *         \"order\" => \"name\",\n *     ]\n * );\n *\n * $robots->rewind();\n *\n * while ($robots->valid()) {\n *     $robot = $robots->current();\n *\n *     echo $robot->name, \"\\n\";\n *\n *     $robots->next();\n * }\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 70,
        "char": 8
    },
    {
        "type": "class",
        "name": "Resultset",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ResultsetInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 71,
                "char": 34
            },
            {
                "type": "variable",
                "value": "Iterator",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 71,
                "char": 44
            },
            {
                "type": "variable",
                "value": "SeekableIterator",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 71,
                "char": 62
            },
            {
                "type": "variable",
                "value": "Countable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 71,
                "char": 73
            },
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 71,
                "char": 86
            },
            {
                "type": "variable",
                "value": "Serializable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 71,
                "char": 100
            },
            {
                "type": "variable",
                "value": "JsonSerializable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                "line": 72,
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
                    "name": "activeRow",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 79,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 81,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "cache",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 83,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "count",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 85,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "errorMessages",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 87,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "hydrateMode",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 87,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 89,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "isFresh",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 89,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 91,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "pointer",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 91,
                        "char": 26
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 93,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "row",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 93,
                        "char": 25
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 95,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "rows",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 95,
                        "char": 26
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 99,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "result",
                    "docblock": "**\n     * Phalcon\\Db\\ResultInterface or false for empty resultset\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 106,
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
                            "name": "result",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 107,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "cache",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 107,
                                "char": 64
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 107,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 107,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "prefetchRecords",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 109,
                                    "char": 28
                                },
                                {
                                    "variable": "rowCount",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 109,
                                    "char": 38
                                },
                                {
                                    "variable": "rows",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 109,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 114,
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
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 114,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 114,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 114,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 114,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "count",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 115,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 115,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 116,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "rows",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 116,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 116,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 118,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 119,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 124,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "result",
                                    "expr": {
                                        "type": "variable",
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 124,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 124,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 129,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "cache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 129,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 129,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 129,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "cache",
                                            "expr": {
                                                "type": "variable",
                                                "value": "cache",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 130,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 130,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 131,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 136,
                            "char": 14
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 136,
                                    "char": 16
                                },
                                "name": "setFetchMode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Db",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 136,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "FETCH_ASSOC",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 136,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 136,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 136,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 136,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 141,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "rowCount",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "result",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 141,
                                            "char": 34
                                        },
                                        "name": "numRows",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 141,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 141,
                                    "char": 44
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "count",
                                    "expr": {
                                        "type": "variable",
                                        "value": "rowCount",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 142,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 142,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 147,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "rowCount",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 147,
                                    "char": 22
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 147,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 147,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "rows",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 148,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 148,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 150,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 151,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 156,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefetchRecords",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "fcall",
                                            "name": "globals_get",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "orm.resultset_prefetch_records",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 156,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 156,
                                                    "char": 79
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 156,
                                            "char": 80
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 156,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 156,
                                    "char": 80
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 157,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "prefetchRecords",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 157,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 157,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 157,
                                    "char": 33
                                },
                                "right": {
                                    "type": "less-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "rowCount",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 157,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "prefetchRecords",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 157,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 157,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 157,
                                "char": 62
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "rows",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "result",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 161,
                                                    "char": 31
                                                },
                                                "name": "fetchAll",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 161,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 161,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 163,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "rows",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 163,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 163,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 163,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 163,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "rows",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "rows",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 164,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 164,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 165,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "rows",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 166,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 166,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 167,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 168,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 169,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Resultset constructor\n     *\n     * @param \\Phalcon\\Db\\ResultInterface|false result\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 108,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 107,
                    "last-line": 173,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "count",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 176,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "count",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 176,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 176,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 177,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Counts how many rows are in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 175,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 174,
                    "last-line": 181,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "conditionCallback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Closure",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 182,
                                "char": 54
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 182,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 182,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 184,
                                    "char": 20
                                },
                                {
                                    "variable": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 184,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 185,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "record",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 185,
                                    "char": 19
                                },
                                {
                                    "variable": "connection",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 185,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 185,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 187,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 187,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 187,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 188,
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
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 188,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 188,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 190,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 190,
                                    "char": 14
                                },
                                "name": "rewind",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 190,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 192,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 192,
                                    "char": 20
                                },
                                "name": "valid",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 192,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "record",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 193,
                                                    "char": 31
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 193,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 193,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 195,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "transaction",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 195,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 195,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 195,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "method_exists",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "record",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                    "line": 199,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 199,
                                                                "char": 50
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "getWriteConnection",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                    "line": 199,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 199,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 199,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 199,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 199,
                                                "char": 72
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
                                                                    "type": "string",
                                                                    "value": "The returned record is not valid",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                    "line": 200,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 200,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 200,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 201,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 203,
                                            "char": 19
                                        },
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
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 203,
                                                            "char": 41
                                                        },
                                                        "name": "getWriteConnection",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 203,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 203,
                                                    "char": 62
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "transaction",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 204,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 204,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 206,
                                            "char": 26
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 206,
                                                    "char": 28
                                                },
                                                "name": "begin",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 206,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 207,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 212,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "conditionCallback",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 212,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 212,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 212,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 212,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "call_user_func_array",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "conditionCallback",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 213,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 213,
                                                            "char": 58
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "record",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                            "line": 213,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                        "line": 213,
                                                                        "char": 67
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 213,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 213,
                                                            "char": 68
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 213,
                                                    "char": 72
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 213,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 213,
                                                "char": 80
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 214,
                                                            "char": 26
                                                        },
                                                        "name": "next",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 214,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 216,
                                                    "char": 28
                                                },
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 217,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 218,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 223,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "record",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 223,
                                                "char": 24
                                            },
                                            "name": "delete",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 223,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 223,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "errorMessages",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 227,
                                                            "char": 50
                                                        },
                                                        "name": "getMessages",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 227,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 227,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 232,
                                            "char": 26
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 232,
                                                    "char": 28
                                                },
                                                "name": "rollback",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 232,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 234,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "result",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 234,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 234,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 235,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "transaction",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 235,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 235,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 237,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 238,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 240,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 240,
                                            "char": 18
                                        },
                                        "name": "next",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 240,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 241,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 246,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 246,
                                    "char": 26
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 246,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 246,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 247,
                                            "char": 24
                                        },
                                        "name": "commit",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 247,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 248,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 250,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 250,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 251,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Deletes every record in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 183,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 183,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 182,
                    "last-line": 265,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "filter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 266,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "record",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 268,
                                    "char": 19
                                },
                                {
                                    "variable": "processedRecord",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 268,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 269,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "records",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 269,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 271,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "records",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 271,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 271,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 273,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 273,
                                    "char": 14
                                },
                                "name": "rewind",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 273,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 275,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 275,
                                    "char": 20
                                },
                                "name": "valid",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 275,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "record",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 276,
                                                    "char": 31
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 276,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 276,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 278,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "processedRecord",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "call_user_func_array",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filter",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 279,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 279,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "record",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                        "line": 282,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                    "line": 282,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 283,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 283,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 283,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 283,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 288,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "processedRecord",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 288,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 288,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 288,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 288,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "processedRecord",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 288,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 288,
                                                "char": 76
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 288,
                                                "char": 84
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 288,
                                            "char": 84
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 288,
                                        "char": 84
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 289,
                                                    "char": 22
                                                },
                                                "name": "next",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 289,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 291,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 292,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 294,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "records",
                                            "expr": {
                                                "type": "variable",
                                                "value": "processedRecord",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 294,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 294,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 296,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 296,
                                            "char": 18
                                        },
                                        "name": "next",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 296,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 297,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 299,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "records",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 299,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 300,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Filters a resultset returning only those the developer requires\n     *\n     *```php\n     * $filtered = $robots->filter(\n     *     function ($robot) {\n     *         if ($robot->id < 3) {\n     *             return $robot;\n     *         }\n     *     }\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 267,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 267,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 267,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 266,
                    "last-line": 304,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCache",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 307,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "cache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 307,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 307,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 308,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the associated cache for the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 306,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 306,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 306,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 305,
                    "last-line": 312,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFirst",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 315,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "count",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 315,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 315,
                                    "char": 25
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 315,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 315,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 316,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 317,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 319,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 319,
                                    "char": 14
                                },
                                "name": "seek",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 319,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 319,
                                        "char": 21
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 319,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 321,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 321,
                                    "char": 21
                                },
                                "name": "current",
                                "call-type": 3,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 321,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 322,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get first row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 313,
                                    "char": 52
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 313,
                                "char": 52
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 314,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 314,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 313,
                    "last-line": 326,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHydrateMode",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 329,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "hydrateMode",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 329,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 329,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 330,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current hydration mode\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 328,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 328,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 327,
                    "last-line": 334,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLast",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "count",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 337,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 339,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "count",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 339,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "count",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 339,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 339,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 339,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 341,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "count",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 341,
                                    "char": 19
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 341,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 341,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 342,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 343,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 345,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 345,
                                    "char": 14
                                },
                                "name": "seek",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "sub",
                                            "left": {
                                                "type": "variable",
                                                "value": "count",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 345,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 345,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 345,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 345,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 345,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 347,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 347,
                                    "char": 21
                                },
                                "name": "current",
                                "call-type": 3,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 347,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 348,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get last row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 335,
                                    "char": 51
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 335,
                                "char": 51
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 336,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 336,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 335,
                    "last-line": 352,
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
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 355,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "errorMessages",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 355,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 355,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 356,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the error messages produced by a batch operation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 354,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 354,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 354,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 353,
                    "last-line": 360,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "ternary",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 363,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "rows",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 363,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 363,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 363,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 363,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 363,
                                    "char": 43
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 363,
                                        "char": 68
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "TYPE_RESULT_FULL",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 363,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 363,
                                    "char": 68
                                },
                                "extra": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 363,
                                        "char": 95
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "TYPE_RESULT_PARTIAL",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 363,
                                        "char": 95
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 363,
                                    "char": 95
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 363,
                                "char": 95
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 364,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal type of data retrieval that the resultset is using\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 362,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 362,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 361,
                    "last-line": 368,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isFresh",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 371,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "isFresh",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 371,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 371,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 372,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Tell if the resultset if fresh or an old one cached\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 370,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 370,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 369,
                    "last-line": 383,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "jsonSerialize",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "current",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 386,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 387,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "records",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 387,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 389,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "records",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 389,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 389,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 391,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 391,
                                    "char": 14
                                },
                                "name": "rewind",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 391,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 393,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 393,
                                    "char": 20
                                },
                                "name": "valid",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 393,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "current",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 394,
                                                    "char": 32
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 394,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 394,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 396,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "current",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 396,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 396,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 396,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 396,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "method_exists",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "current",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 396,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 396,
                                                    "char": 65
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "jsonSerialize",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 396,
                                                        "char": 80
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 396,
                                                    "char": 80
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 396,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 396,
                                        "char": 82
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "records",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "current",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 397,
                                                            "char": 41
                                                        },
                                                        "name": "jsonSerialize",
                                                        "call-type": 3,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 397,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 397,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 398,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "records",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "current",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 399,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 399,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 400,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 402,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 402,
                                            "char": 18
                                        },
                                        "name": "next",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 402,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 403,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 405,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "records",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 405,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 406,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns serialised model objects as array for json_encode.\n     * Calls jsonSerialize on each object if present\n     *\n     *```php\n     * $robots = Robots::find();\n     *\n     * echo json_encode($robots);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 385,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 385,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 384,
                    "last-line": 410,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "key",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 413,
                                        "char": 18
                                    },
                                    "name": "valid",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 413,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 413,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 414,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 415,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 417,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 417,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "pointer",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 417,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 417,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 418,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets pointer number of active row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 411,
                                "char": 34
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 412,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 412,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 411,
                    "last-line": 422,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "next",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 426,
                                    "char": 14
                                },
                                "name": "seek",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "add",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 427,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "pointer",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 427,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 427,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 428,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 428,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 428,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 428,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 429,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Moves cursor to next row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 424,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 423,
                    "last-line": 433,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 434,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "greater-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 436,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 436,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "count",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 436,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 436,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 436,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 436,
                                "char": 41
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
                                                    "type": "string",
                                                    "value": "The index does not exist in the cursor",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 437,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 437,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 437,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 438,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 443,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 443,
                                    "char": 14
                                },
                                "name": "seek",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 443,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 443,
                                        "char": 25
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 443,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 445,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 445,
                                    "char": 21
                                },
                                "name": "current",
                                "call-type": 3,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 445,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 446,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets row in a specific position of the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 434,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 434,
                                "char": 62
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 435,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 435,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 434,
                    "last-line": 450,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 451,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "index",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 453,
                                    "char": 22
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 453,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "count",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 453,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 453,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 453,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 454,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether offset exists in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 452,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 452,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 451,
                    "last-line": 461,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetSet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 462,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 462,
                            "char": 51
                        }
                    ],
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
                                            "type": "string",
                                            "value": "Cursor is an immutable ArrayAccess object",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 464,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 464,
                                        "char": 70
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 464,
                                "char": 71
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 465,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface\n     *\n     * @param int index\n     * @param \\Phalcon\\Mvc\\ModelInterface value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 463,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 462,
                    "last-line": 469,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetUnset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 470,
                            "char": 43
                        }
                    ],
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
                                            "type": "string",
                                            "value": "Cursor is an immutable ArrayAccess object",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 472,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 472,
                                        "char": 70
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 472,
                                "char": 71
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 473,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 471,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 470,
                    "last-line": 477,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "rewind",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 480,
                                    "char": 14
                                },
                                "name": "seek",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 480,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 480,
                                        "char": 21
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 480,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 481,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rewinds resultset to its beginning\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 479,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 478,
                    "last-line": 486,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "seek",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 487,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 489,
                                    "char": 19
                                },
                                {
                                    "variable": "row",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 489,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 491,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 491,
                                            "char": 17
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "pointer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 491,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 491,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "position",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 491,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 491,
                                    "char": 39
                                },
                                "right": {
                                    "type": "identical",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 491,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "row",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 491,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 491,
                                        "char": 53
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 491,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 491,
                                    "char": 60
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 491,
                                "char": 60
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 492,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "rows",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 492,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 492,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 492,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 492,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 492,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "row",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 496,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 496,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "rows",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 496,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 496,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "position",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 496,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 496,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 496,
                                                "char": 52
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "row",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "row",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 497,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 497,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 498,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 500,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "pointer",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "position",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 500,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 500,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 501,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "activeRow",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 501,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 501,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 503,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 504,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 509,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 509,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "result",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 509,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 509,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 509,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 511,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 511,
                                                    "char": 21
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "row",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 511,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 511,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 511,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 511,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 511,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "pointer",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 511,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 511,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 511,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 511,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 511,
                                        "char": 58
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "row",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "result",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 517,
                                                            "char": 40
                                                        },
                                                        "name": "fetch",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 517,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 517,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 518,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 520,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 520,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "pointer",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 520,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 520,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 520,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 520,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "result",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 526,
                                                    "char": 24
                                                },
                                                "name": "dataSeek",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "position",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 526,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 526,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 526,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 528,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "row",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "result",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 528,
                                                            "char": 40
                                                        },
                                                        "name": "fetch",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 528,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 528,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 529,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "pointer",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "position",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 529,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 529,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 530,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 532,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 532,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "pointer",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 532,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 532,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 532,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 532,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "row",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "result",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 538,
                                                            "char": 40
                                                        },
                                                        "name": "fetch",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 538,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 538,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 539,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-incr",
                                                    "variable": "this",
                                                    "property": "pointer",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 539,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 540,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 542,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "pointer",
                                            "expr": {
                                                "type": "variable",
                                                "value": "position",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 542,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 542,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 543,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeRow",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 543,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 543,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 544,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 545,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Changes the internal pointer to a specific position in the resultset.\n     * Set the new position if required, and then set this->row\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 488,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 487,
                    "last-line": 549,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHydrateMode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "hydrateMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 550,
                            "char": 51
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
                                    "property": "hydrateMode",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hydrateMode",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 552,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 552,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 554,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 554,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 555,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the hydration mode in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 551,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 551,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 551,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 550,
                    "last-line": 559,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setIsFresh",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "isFresh",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 560,
                            "char": 44
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
                                    "property": "isFresh",
                                    "expr": {
                                        "type": "variable",
                                        "value": "isFresh",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 562,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 562,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 564,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 564,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 565,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set if the resultset is fresh or an old one cached\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 561,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 561,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 561,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 560,
                    "last-line": 571,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "update",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 572,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "conditionCallback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Closure",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 572,
                                "char": 64
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 572,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 572,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 574,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 575,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "record",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 575,
                                    "char": 19
                                },
                                {
                                    "variable": "connection",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 575,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 575,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 577,
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
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 577,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 577,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 579,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 579,
                                    "char": 14
                                },
                                "name": "rewind",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 579,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 581,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 581,
                                    "char": 20
                                },
                                "name": "valid",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 581,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "record",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 582,
                                                    "char": 31
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 582,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 582,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 584,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "transaction",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 584,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 584,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 584,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "method_exists",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "record",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                    "line": 588,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 588,
                                                                "char": 50
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "getWriteConnection",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                    "line": 588,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 588,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 588,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 588,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 588,
                                                "char": 72
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
                                                                    "type": "string",
                                                                    "value": "The returned record is not valid",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                    "line": 589,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 589,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 589,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 590,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 592,
                                            "char": 19
                                        },
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
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 592,
                                                            "char": 41
                                                        },
                                                        "name": "getWriteConnection",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 592,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 592,
                                                    "char": 62
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "transaction",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 593,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 593,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 595,
                                            "char": 26
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 595,
                                                    "char": 28
                                                },
                                                "name": "begin",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 595,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 596,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 601,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "conditionCallback",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 601,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 601,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 601,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 601,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "call_user_func_array",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "conditionCallback",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 602,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 602,
                                                            "char": 58
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "variable",
                                                                            "value": "record",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                            "line": 602,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                        "line": 602,
                                                                        "char": 67
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                                "line": 602,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 602,
                                                            "char": 68
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 602,
                                                    "char": 72
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 602,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 602,
                                                "char": 80
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 603,
                                                            "char": 26
                                                        },
                                                        "name": "next",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 603,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 605,
                                                    "char": 28
                                                },
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 606,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 607,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 609,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "record",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 609,
                                            "char": 20
                                        },
                                        "name": "assign",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 609,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 609,
                                                "char": 32
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 609,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 614,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "record",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 614,
                                                "char": 24
                                            },
                                            "name": "save",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 614,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 614,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "errorMessages",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "record",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                            "line": 618,
                                                            "char": 50
                                                        },
                                                        "name": "getMessages",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 618,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 618,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 623,
                                            "char": 26
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 623,
                                                    "char": 28
                                                },
                                                "name": "rollback",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                "line": 623,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 625,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "transaction",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                        "line": 625,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                                    "line": 625,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 627,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 628,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 630,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 630,
                                            "char": 18
                                        },
                                        "name": "next",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 630,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 631,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 636,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "transaction",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 636,
                                    "char": 26
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 636,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 636,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                            "line": 637,
                                            "char": 24
                                        },
                                        "name": "commit",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 637,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 638,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 640,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 640,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 641,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Updates every record in the resultset\n     *\n     * @param array data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 573,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 573,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 572,
                    "last-line": 645,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "valid",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 648,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "pointer",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 648,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 648,
                                    "char": 30
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 648,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "count",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                        "line": 648,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                    "line": 648,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 648,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                            "line": 649,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether internal resource has rows to fetch\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                                "line": 647,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 647,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 646,
                    "last-line": 650,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "HYDRATE_ARRAYS",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 73,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 74,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HYDRATE_OBJECTS",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 74,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 75,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HYDRATE_RECORDS",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 75,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 76,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "TYPE_RESULT_FULL",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 76,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 77,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "TYPE_RESULT_PARTIAL",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                        "line": 77,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
                    "line": 79,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
            "line": 70,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset.zep",
        "line": 70,
        "char": 14
    }
]