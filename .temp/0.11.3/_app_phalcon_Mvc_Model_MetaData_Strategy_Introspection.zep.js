[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData\\Strategy",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Column",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 15,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 16,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 18,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 19,
                "char": 49
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaData\\Strategy\\Introspection\n *\n * Queries the table meta-data in order to introspect the model's metadata\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Introspection",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "StrategyInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                "line": 27,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnMaps",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 31,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 31,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 31,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 31,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "orderedColumnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 33,
                                    "char": 29
                                },
                                {
                                    "variable": "userColumnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 33,
                                    "char": 44
                                },
                                {
                                    "variable": "reversedColumnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 33,
                                    "char": 63
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 33,
                                    "char": 69
                                },
                                {
                                    "variable": "userName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 33,
                                    "char": 79
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 35,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "orderedColumnMap",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 35,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 35,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 36,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reversedColumnMap",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 36,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 36,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 41,
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
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 41,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 41,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "columnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 41,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 41,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 41,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "userColumnMap",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 42,
                                                    "char": 39
                                                },
                                                "name": "columnMap",
                                                "call-type": 3,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 42,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 42,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 44,
                                    "char": 14
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
                                                    "value": "userColumnMap",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 44,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 44,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 44,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 44,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 44,
                                        "char": 55
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
                                                            "value": "columnMap() not returned an array",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 45,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 45,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 45,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 46,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 48,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reversedColumnMap",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 48,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 48,
                                            "char": 39
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "orderedColumnMap",
                                            "expr": {
                                                "type": "variable",
                                                "value": "userColumnMap",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 49,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 49,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 51,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "userColumnMap",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 51,
                                        "char": 49
                                    },
                                    "key": "name",
                                    "value": "userName",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "reversedColumnMap",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "userName",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 52,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 52,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 52,
                                                    "char": 55
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 53,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 54,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 59,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "orderedColumnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 59,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 59,
                                        "char": 33
                                    },
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "reversedColumnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 59,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 59,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 59,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 60,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Read the model's column map, this can't be inferred\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 32,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                        "line": 32,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                    "line": 31,
                    "last-line": 64,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getMetaData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 65,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 65,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 65,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 65,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "schema",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 67,
                                    "char": 19
                                },
                                {
                                    "variable": "table",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 67,
                                    "char": 26
                                },
                                {
                                    "variable": "readConnection",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 67,
                                    "char": 42
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 67,
                                    "char": 51
                                },
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 67,
                                    "char": 63
                                },
                                {
                                    "variable": "primaryKeys",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 67,
                                    "char": 76
                                },
                                {
                                    "variable": "nonPrimaryKeys",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 68,
                                    "char": 27
                                },
                                {
                                    "variable": "numericTyped",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 68,
                                    "char": 41
                                },
                                {
                                    "variable": "notNull",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 68,
                                    "char": 50
                                },
                                {
                                    "variable": "fieldTypes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 68,
                                    "char": 62
                                },
                                {
                                    "variable": "automaticDefault",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 68,
                                    "char": 80
                                },
                                {
                                    "variable": "identityField",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 69,
                                    "char": 26
                                },
                                {
                                    "variable": "fieldBindTypes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 69,
                                    "char": 42
                                },
                                {
                                    "variable": "defaultValues",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 69,
                                    "char": 57
                                },
                                {
                                    "variable": "column",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 69,
                                    "char": 65
                                },
                                {
                                    "variable": "fieldName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 69,
                                    "char": 76
                                },
                                {
                                    "variable": "defaultValue",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 70,
                                    "char": 25
                                },
                                {
                                    "variable": "emptyStringValues",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 70,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 71,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "completeTable",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 71,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 73,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "schema",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 73,
                                            "char": 28
                                        },
                                        "name": "getSchema",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 73,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 73,
                                    "char": 40
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "table",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 74,
                                            "char": 28
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 74,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 74,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 79,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "readConnection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 79,
                                            "char": 36
                                        },
                                        "name": "getReadConnection",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 79,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 79,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 81,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "readConnection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 81,
                                            "char": 37
                                        },
                                        "name": "tableExists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 81,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 81,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schema",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 81,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 81,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 81,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 81,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 81,
                                "char": 65
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "schema",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 82,
                                        "char": 23
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeTable",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "schema",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 83,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "'.'",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 83,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 83,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "table",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 83,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 83,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 83,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 84,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeTable",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 85,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 85,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 86,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 91,
                                    "char": 17
                                },
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "Table '",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 92,
                                                                "char": 25
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "completeTable",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 92,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 92,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "' doesn't exist in database when dumping meta-data for ",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 92,
                                                            "char": 99
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 92,
                                                        "char": 99
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "get_class",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "model",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                    "line": 92,
                                                                    "char": 116
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 92,
                                                                "char": 116
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 93,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 93,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 93,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 93,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 94,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 99,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columns",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "readConnection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 99,
                                            "char": 38
                                        },
                                        "name": "describeColumns",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 99,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 99,
                                                "char": 60
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schema",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 99,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 99,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 99,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 99,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 101,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "columns",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 101,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 101,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 101,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 101,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 101,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "schema",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 102,
                                        "char": 23
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeTable",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "schema",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 103,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "'.'",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 103,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 103,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "table",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 103,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 103,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 103,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 104,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "completeTable",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 105,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 105,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 106,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 111,
                                    "char": 17
                                },
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "Cannot obtain table columns for the mapped source '",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 112,
                                                                "char": 69
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "completeTable",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 112,
                                                                "char": 85
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 112,
                                                            "char": 85
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "' used in model ",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 112,
                                                            "char": 104
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 112,
                                                        "char": 104
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "get_class",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "model",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                    "line": 112,
                                                                    "char": 121
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 112,
                                                                "char": 121
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 113,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 113,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 113,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 113,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 119,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "attributes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 119,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 119,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 120,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "primaryKeys",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 120,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 120,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 121,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "nonPrimaryKeys",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 121,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 121,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 122,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "numericTyped",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 122,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 122,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 123,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "notNull",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 123,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 123,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 124,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fieldTypes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 124,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 124,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 125,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fieldBindTypes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 125,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 125,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 126,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "automaticDefault",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 126,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 126,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 127,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "identityField",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 127,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 127,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 128,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "defaultValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 128,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 128,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 129,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "emptyStringValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 129,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 129,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 131,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "columns",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 131,
                                "char": 31
                            },
                            "value": "column",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fieldName",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 132,
                                                    "char": 36
                                                },
                                                "name": "getName",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 132,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 132,
                                            "char": 46
                                        },
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "attributes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "fieldName",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 133,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 133,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 138,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 138,
                                            "char": 23
                                        },
                                        "name": "isPrimary",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 138,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "primaryKeys",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "fieldName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 139,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 139,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 140,
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
                                                    "variable": "nonPrimaryKeys",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "fieldName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 141,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 141,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 142,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 147,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 147,
                                            "char": 23
                                        },
                                        "name": "isNumeric",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 147,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "numericTyped",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "fieldName",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 148,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 148,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 148,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 149,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 154,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 154,
                                            "char": 23
                                        },
                                        "name": "isNotNull",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 154,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "notNull",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "fieldName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 155,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 155,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 156,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 161,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 161,
                                            "char": 23
                                        },
                                        "name": "isAutoIncrement",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 161,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "identityField",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "fieldName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 162,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 162,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 163,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 168,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "fieldTypes",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "fieldName",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 168,
                                                    "char": 37
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 168,
                                                    "char": 48
                                                },
                                                "name": "getType",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 168,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 168,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 173,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "fieldBindTypes",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "fieldName",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 173,
                                                    "char": 41
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 173,
                                                    "char": 52
                                                },
                                                "name": "getBindType",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 173,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 173,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 178,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "defaultValue",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 178,
                                                    "char": 39
                                                },
                                                "name": "getDefault",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 178,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 178,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 180,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "defaultValue",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 180,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 180,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 180,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 180,
                                                    "char": 49
                                                },
                                                "name": "isNotNull",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 180,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 180,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 180,
                                        "char": 62
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                        "line": 181,
                                                        "char": 28
                                                    },
                                                    "name": "isAutoIncrement",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 181,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 181,
                                                "char": 47
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "defaultValues",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "fieldName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                    "line": 182,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "defaultValue",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                                "line": 182,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                            "line": 182,
                                                            "char": 64
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                    "line": 183,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 184,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                    "line": 185,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 190,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 191,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_ATTRIBUTES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 191,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 191,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 191,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 191,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 192,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_PRIMARY_KEY",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 192,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 192,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "primaryKeys",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 192,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 192,
                                        "char": 68
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 193,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_NON_PRIMARY_KEY",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 193,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 193,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "nonPrimaryKeys",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 193,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 193,
                                        "char": 71
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 194,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_NOT_NULL",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 194,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 194,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "notNull",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 194,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 194,
                                        "char": 64
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 195,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DATA_TYPES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 195,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 195,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "fieldTypes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 195,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 195,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 196,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DATA_TYPES_NUMERIC",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 196,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 196,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "numericTyped",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 196,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 196,
                                        "char": 69
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 197,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_IDENTITY_COLUMN",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 197,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 197,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "identityField",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 197,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 197,
                                        "char": 70
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 198,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DATA_TYPES_BIND",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 198,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 198,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "fieldBindTypes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 198,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 198,
                                        "char": 71
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 199,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_AUTOMATIC_DEFAULT_INSERT",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 199,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 199,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "automaticDefault",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 199,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 199,
                                        "char": 73
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 200,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_AUTOMATIC_DEFAULT_UPDATE",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 200,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 200,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "automaticDefault",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 200,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 200,
                                        "char": 73
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 201,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DEFAULT_VALUES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 201,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 201,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "defaultValues",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 201,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 201,
                                        "char": 70
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 202,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_EMPTY_STRING_VALUES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                                "line": 202,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 202,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "emptyStringValues",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                            "line": 203,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                        "line": 203,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 203,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                            "line": 204,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * The meta-data is obtained by reading the column descriptions from the database information schema\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                                "line": 66,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                        "line": 66,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
                    "line": 65,
                    "last-line": 205,
                    "char": 25
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
            "line": 26,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Introspection.zep",
        "line": 26,
        "char": 5
    }
]