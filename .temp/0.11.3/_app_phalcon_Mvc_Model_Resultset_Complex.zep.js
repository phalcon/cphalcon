[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Resultset",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 13,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Row",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 14,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ResultInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 15,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Resultset",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 16,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\ResultsetInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 19,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 20,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 21,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 22,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "stdClass",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 23,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 30,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Resultset\\Complex\n *\n * Complex resultsets may include complete objects and scalar values.\n * This class builds every complex row as it is required\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 31,
        "char": 5
    },
    {
        "type": "class",
        "name": "Complex",
        "abstract": 0,
        "final": 0,
        "extends": "Resultset",
        "implements": [
            {
                "type": "variable",
                "value": "ResultsetInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                "line": 32,
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
                    "name": "columnTypes",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                    "line": 38,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "disableHydration",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                        "line": 39,
                        "char": 39
                    },
                    "docblock": "**\n     * Unserialised result-set hydrated all rows already. unserialise() sets\n     * disableHydration to true\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                    "line": 45,
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
                            "name": "columnTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 47,
                            "char": 24
                        },
                        {
                            "type": "parameter",
                            "name": "result",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ResultInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 48,
                                "char": 32
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 48,
                                "char": 40
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 48,
                            "char": 40
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 49,
                                "char": 32
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 50,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 50,
                            "char": 5
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
                                    "property": "columnTypes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "columnTypes",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 55,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 55,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 57,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "result",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 57,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 57,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 57,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 57,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 57,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 58,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Resultset\\Complex constructor\n     *\n     * @param array columnTypes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                        "line": 51,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                    "line": 46,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "current",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "row",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 16
                                },
                                {
                                    "variable": "hydrateMode",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 29
                                },
                                {
                                    "variable": "eager",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 36
                                },
                                {
                                    "variable": "dirtyState",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 48
                                },
                                {
                                    "variable": "alias",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 55
                                },
                                {
                                    "variable": "activeRow",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 66
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 72
                                },
                                {
                                    "variable": "column",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 65,
                                    "char": 80
                                },
                                {
                                    "variable": "columnValue",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 66,
                                    "char": 24
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 66,
                                    "char": 31
                                },
                                {
                                    "variable": "attribute",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 66,
                                    "char": 42
                                },
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 66,
                                    "char": 50
                                },
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 66,
                                    "char": 62
                                },
                                {
                                    "variable": "columnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 66,
                                    "char": 73
                                },
                                {
                                    "variable": "rowModel",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 67,
                                    "char": 21
                                },
                                {
                                    "variable": "keepSnapshots",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 67,
                                    "char": 36
                                },
                                {
                                    "variable": "sqlAlias",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 67,
                                    "char": 46
                                },
                                {
                                    "variable": "modelName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 67,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 69,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "activeRow",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 69,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRow",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 69,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 69,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 69,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 71,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "activeRow",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 71,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 71,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 71,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "activeRow",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 72,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 78,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "row",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 78,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "row",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 78,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 78,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 78,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 83,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 83,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "disableHydration",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 83,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 83,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeRow",
                                            "expr": {
                                                "type": "variable",
                                                "value": "row",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 84,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 84,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 86,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "row",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 86,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 87,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 92,
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
                                        "value": "row",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 92,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 92,
                                    "char": 24
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 92,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 92,
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
                                            "property": "activeRow",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 93,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 93,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 95,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 95,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 96,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 101,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hydrateMode",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 101,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "hydrateMode",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 101,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 101,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 101,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 106,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "hydrateMode",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 106,
                                "char": 28
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 107,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HYDRATE_RECORDS",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 107,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 107,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "activeRow",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "Row",
                                                        "dynamic": 0,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 108,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 108,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 109,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 111,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 111,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 111,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HYDRATE_ARRAYS",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 111,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 111,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "activeRow",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 112,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 112,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 113,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 115,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 115,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 115,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HYDRATE_OBJECTS",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 115,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 115,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 116,
                                    "char": 19
                                },
                                {
                                    "type": "default",
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "activeRow",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "stdClass",
                                                        "dynamic": 0,
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 117,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 117,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 118,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 119,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 119,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 124,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dirtyState",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 124,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 124,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 129,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 129,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "columnTypes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 129,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 129,
                                "char": 48
                            },
                            "key": "alias",
                            "value": "column",
                            "reverse": 0,
                            "statements": [
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
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 130,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 130,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 130,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 130,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 130,
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
                                                            "type": "string",
                                                            "value": "Column type is corrupt",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 131,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 131,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 131,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 132,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 134,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "type",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 134,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 134,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 134,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 134,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 136,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 136,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 136,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 136,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "source",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 140,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 140,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 140,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 140,
                                                    "char": 44
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "attributes",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 141,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "attributes",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 141,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 141,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 141,
                                                    "char": 52
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columnMap",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 142,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "columnMap",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 142,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 142,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 142,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 147,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "rowModel",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 147,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 147,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 149,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 149,
                                                "char": 45
                                            },
                                            "value": "attribute",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "columnValue",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "row",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 153,
                                                                    "char": 42
                                                                },
                                                                "right": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "_",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 153,
                                                                                "char": 45
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "source",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 153,
                                                                                "char": 54
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 153,
                                                                            "char": 54
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "_",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 153,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 153,
                                                                        "char": 57
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "attribute",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 153,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 153,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 153,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 153,
                                                            "char": 69
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "rowModel",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "attribute",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 154,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "columnValue",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 154,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 154,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 155,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 160,
                                            "char": 22
                                        },
                                        {
                                            "type": "switch",
                                            "expr": {
                                                "type": "variable",
                                                "value": "hydrateMode",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 160,
                                                "char": 36
                                            },
                                            "clauses": [
                                                {
                                                    "type": "case",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Resultset",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 162,
                                                            "char": 52
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "HYDRATE_RECORDS",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 162,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 162,
                                                        "char": 52
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "not",
                                                                "left": {
                                                                    "type": "fetch",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "keepSnapshots",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 164,
                                                                        "char": 72
                                                                    },
                                                                    "right": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "column",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 164,
                                                                            "char": 56
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "keepSnapshots",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 164,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 164,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 164,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 164,
                                                                "char": 72
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "keepSnapshots",
                                                                            "expr": {
                                                                                "type": "bool",
                                                                                "value": "false",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 165,
                                                                                "char": 54
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 165,
                                                                            "char": 54
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 166,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 168,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "globals_get",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "orm.late_state_binding",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 168,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 168,
                                                                        "char": 62
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 168,
                                                                "char": 64
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "instanceof",
                                                                        "left": {
                                                                            "type": "array-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "column",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 170,
                                                                                "char": 38
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "instance",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 170,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 170,
                                                                            "char": 58
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "Model",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 170,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 170,
                                                                        "char": 66
                                                                    },
                                                                    "statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "modelName",
                                                                                    "expr": {
                                                                                        "type": "fcall",
                                                                                        "name": "get_class",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "array-access",
                                                                                                    "left": {
                                                                                                        "type": "variable",
                                                                                                        "value": "column",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                        "line": 171,
                                                                                                        "char": 65
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "string",
                                                                                                        "value": "instance",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                        "line": 171,
                                                                                                        "char": 74
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                    "line": 171,
                                                                                                    "char": 75
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                "line": 171,
                                                                                                "char": 75
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 171,
                                                                                        "char": 76
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                    "line": 171,
                                                                                    "char": 76
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 172,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "else_statements": [
                                                                        {
                                                                            "type": "let",
                                                                            "assignments": [
                                                                                {
                                                                                    "assign-type": "variable",
                                                                                    "operator": "assign",
                                                                                    "variable": "modelName",
                                                                                    "expr": {
                                                                                        "type": "string",
                                                                                        "value": "Phalcon\\\\Mvc\\\\Model",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 173,
                                                                                        "char": 68
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                    "line": 173,
                                                                                    "char": 68
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 174,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 176,
                                                                    "char": 31
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "value",
                                                                            "expr": {
                                                                                "type": "scall",
                                                                                "dynamic-class": 1,
                                                                                "class": "modelName",
                                                                                "dynamic": 0,
                                                                                "name": "cloneResultMap",
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "array-access",
                                                                                            "left": {
                                                                                                "type": "variable",
                                                                                                "value": "column",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                "line": 177,
                                                                                                "char": 39
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "string",
                                                                                                "value": "instance",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                "line": 177,
                                                                                                "char": 48
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 177,
                                                                                            "char": 49
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 177,
                                                                                        "char": 49
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "rowModel",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 178,
                                                                                            "char": 41
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 178,
                                                                                        "char": 41
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "columnMap",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 179,
                                                                                            "char": 42
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 179,
                                                                                        "char": 42
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "dirtyState",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 180,
                                                                                            "char": 43
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 180,
                                                                                        "char": 43
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "keepSnapshots",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 182,
                                                                                            "char": 29
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 182,
                                                                                        "char": 29
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 182,
                                                                                "char": 30
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 182,
                                                                            "char": 30
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 184,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "value",
                                                                            "expr": {
                                                                                "type": "scall",
                                                                                "dynamic-class": 0,
                                                                                "class": "Model",
                                                                                "dynamic": 0,
                                                                                "name": "cloneResultMap",
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "array-access",
                                                                                            "left": {
                                                                                                "type": "variable",
                                                                                                "value": "column",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                "line": 191,
                                                                                                "char": 39
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "string",
                                                                                                "value": "instance",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                                "line": 191,
                                                                                                "char": 48
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 191,
                                                                                            "char": 49
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 191,
                                                                                        "char": 49
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "rowModel",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 192,
                                                                                            "char": 41
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 192,
                                                                                        "char": 41
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "columnMap",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 193,
                                                                                            "char": 42
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 193,
                                                                                        "char": 42
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "dirtyState",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 194,
                                                                                            "char": 43
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 194,
                                                                                        "char": 43
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "keepSnapshots",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                            "line": 196,
                                                                                            "char": 29
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                        "line": 196,
                                                                                        "char": 29
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 196,
                                                                                "char": 30
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 196,
                                                                            "char": 30
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 197,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 199,
                                                            "char": 29
                                                        },
                                                        {
                                                            "type": "break",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 201,
                                                            "char": 27
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 201,
                                                    "char": 27
                                                },
                                                {
                                                    "type": "default",
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "value",
                                                                    "expr": {
                                                                        "type": "scall",
                                                                        "dynamic-class": 0,
                                                                        "class": "Model",
                                                                        "dynamic": 0,
                                                                        "name": "cloneResultMapHydrate",
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "rowModel",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                    "line": 204,
                                                                                    "char": 37
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 204,
                                                                                "char": 37
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "columnMap",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                    "line": 205,
                                                                                    "char": 38
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 205,
                                                                                "char": 38
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "hydrateMode",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                    "line": 207,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                                "line": 207,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 207,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 207,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 209,
                                                            "char": 29
                                                        },
                                                        {
                                                            "type": "break",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 210,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 210,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 215,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "attribute",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 215,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "balias",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 215,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 215,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 215,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 217,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "sqlAlias",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 222,
                                                    "char": 53
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 222,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "sqlAlias",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 222,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 222,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 222,
                                                "char": 53
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "value",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "row",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 223,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "sqlAlias",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 223,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 223,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 223,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 224,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "fetch",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 225,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "row",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 225,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "alias",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 225,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 225,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 225,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 226,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 231,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 231,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "balias",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 231,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 231,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 231,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "attribute",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "alias",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 232,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 232,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 233,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "attribute",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_replace",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "_",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 234,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 234,
                                                                        "char": 50
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 234,
                                                                            "char": 52
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 234,
                                                                        "char": 52
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "alias",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 234,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 234,
                                                                        "char": 59
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 234,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 234,
                                                            "char": 60
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 235,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 236,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 238,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "eager",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 238,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 238,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "eager",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 238,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 238,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 238,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 238,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "switch",
                                            "expr": {
                                                "type": "variable",
                                                "value": "hydrateMode",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 243,
                                                "char": 36
                                            },
                                            "clauses": [
                                                {
                                                    "type": "case",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Resultset",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 245,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "HYDRATE_ARRAYS",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 245,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 245,
                                                        "char": 51
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "activeRow",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "attribute",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                            "line": 246,
                                                                            "char": 48
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 246,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 246,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 247,
                                                            "char": 29
                                                        },
                                                        {
                                                            "type": "break",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 249,
                                                            "char": 27
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 249,
                                                    "char": 27
                                                },
                                                {
                                                    "type": "default",
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable-dynamic-object-property",
                                                                    "operator": "assign",
                                                                    "variable": "activeRow",
                                                                    "property": "attribute",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                        "line": 250,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                    "line": 250,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 251,
                                                            "char": 29
                                                        },
                                                        {
                                                            "type": "break",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 252,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 252,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 253,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 254,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 259,
                            "char": 11
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
                                        "type": "variable",
                                        "value": "activeRow",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 259,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 259,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 261,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "activeRow",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 261,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 262,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns current row in the resultset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 63,
                                    "char": 57
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 63,
                                "char": 57
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 64,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                    "line": 63,
                    "last-line": 267,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "current",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 270,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 271,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "records",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 271,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 273,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 273,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 273,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 275,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 275,
                                    "char": 14
                                },
                                "name": "rewind",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 275,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 277,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 277,
                                    "char": 20
                                },
                                "name": "valid",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 277,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 278,
                                                    "char": 32
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 278,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 278,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 279,
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
                                                "value": "current",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 279,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 279,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 281,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 281,
                                            "char": 18
                                        },
                                        "name": "next",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 281,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 282,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 284,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "records",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 284,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 285,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a complete resultset as an array, if the resultset has a big\n     * number of rows it could consume more memory than currently it does.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 269,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                        "line": 269,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                    "line": 268,
                    "last-line": 289,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "serialize",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "records",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 292,
                                    "char": 20
                                },
                                {
                                    "variable": "cache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 292,
                                    "char": 27
                                },
                                {
                                    "variable": "columnTypes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 292,
                                    "char": 40
                                },
                                {
                                    "variable": "hydrateMode",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 292,
                                    "char": 53
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 292,
                                    "char": 64
                                },
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 292,
                                    "char": 76
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 297,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 297,
                                            "char": 28
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 297,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 297,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 299,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cache",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 299,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 299,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 299,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 299,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columnTypes",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 300,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "columnTypes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 300,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 300,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 300,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hydrateMode",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 301,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "hydrateMode",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 301,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 301,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 301,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 303,
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
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Di",
                                        "dynamic": 0,
                                        "name": "getDefault",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 303,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 303,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 305,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 305,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 305,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 305,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 305,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 305,
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
                                                    "type": "string",
                                                    "value": "The dependency injector container is not valid",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 308,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 308,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 308,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 309,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 311,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 311,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 311,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 311,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 311,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "serializer",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "SerializerInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 312,
                                                    "char": 84
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 312,
                                                        "char": 62
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "serializer",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 312,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 312,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 312,
                                                    "char": 84
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 312,
                                                "char": 84
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 312,
                                            "char": 84
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 314,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 314,
                                            "char": 24
                                        },
                                        "name": "setData",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "cache",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 316,
                                                                "char": 33
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "cache",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 316,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 316,
                                                            "char": 40
                                                        },
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "rows",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 317,
                                                                "char": 33
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "records",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 317,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 317,
                                                            "char": 42
                                                        },
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "columnTypes",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 318,
                                                                "char": 33
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "columnTypes",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 318,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 318,
                                                            "char": 46
                                                        },
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "hydrateMode",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 319,
                                                                "char": 33
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "hydrateMode",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 320,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 320,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 321,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 321,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 321,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 323,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 323,
                                            "char": 31
                                        },
                                        "name": "serialize",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 323,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 324,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 326,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "serialize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "cache",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 328,
                                                        "char": 29
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "cache",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 328,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 328,
                                                    "char": 36
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "rows",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 329,
                                                        "char": 29
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "records",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 329,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 329,
                                                    "char": 38
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "columnTypes",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 330,
                                                        "char": 29
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "columnTypes",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 330,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 330,
                                                    "char": 42
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": "hydrateMode",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 331,
                                                        "char": 29
                                                    },
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "hydrateMode",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 332,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 332,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 333,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 333,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 333,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 334,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Serializing a resultset will dump all related rows into a big array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 291,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                        "line": 291,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                    "line": 290,
                    "last-line": 338,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "unserialize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 339,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "resultset",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 341,
                                    "char": 22
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 341,
                                    "char": 33
                                },
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 341,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 346,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "disableHydration",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 346,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 346,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 348,
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
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Di",
                                        "dynamic": 0,
                                        "name": "getDefault",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 348,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 348,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 350,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 350,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 350,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 350,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 350,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 350,
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
                                                    "type": "string",
                                                    "value": "The dependency injector container is not valid",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 353,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 353,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 353,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 354,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 356,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 356,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 356,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 356,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 356,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "serializer",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "SerializerInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 357,
                                                    "char": 84
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 357,
                                                        "char": 62
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "serializer",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                                "line": 357,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 357,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 357,
                                                    "char": 84
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 357,
                                                "char": 84
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 357,
                                            "char": 84
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 359,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "resultset",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "serializer",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 359,
                                                    "char": 40
                                                },
                                                "name": "unserialize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 359,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 359,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 359,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 359,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 360,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "resultset",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "unserialize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                            "line": 361,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 361,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 361,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 361,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 362,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 364,
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
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 364,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 364,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 364,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 364,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                "line": 364,
                                "char": 47
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
                                                    "value": "Invalid serialization data",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 365,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 365,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 365,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 366,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 368,
                            "char": 11
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
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 368,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "rows",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 368,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 368,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 368,
                                    "char": 48
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "count",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "resultset",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 369,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "rows",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                        "line": 369,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                    "line": 369,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                                "line": 369,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 369,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 369,
                                    "char": 55
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "cache",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 370,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 370,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 370,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 370,
                                    "char": 49
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "columnTypes",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 371,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "columnTypes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 371,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 371,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 371,
                                    "char": 55
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "hydrateMode",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 372,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "hydrateMode",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                            "line": 372,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                        "line": 372,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                                    "line": 372,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                            "line": 373,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Unserializing a resultset will allow to only works on the rows present in the saved state\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                        "line": 340,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
                    "line": 339,
                    "last-line": 374,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
            "line": 31,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Complex.zep",
        "line": 31,
        "char": 5
    }
]