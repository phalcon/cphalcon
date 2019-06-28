[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Resultset",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                "line": 15,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                "line": 16,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Resultset",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                "line": 18,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                "line": 19,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 26,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Resultset\\Simple\n *\n * Simple resultsets only contains a complete objects\n * This class builds every complete object as it is required\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 27,
        "char": 5
    },
    {
        "type": "class",
        "name": "Simple",
        "abstract": 0,
        "final": 0,
        "extends": "Resultset",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "columnMap",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 30,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "model",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 33,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "keepSnapshots",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                        "line": 34,
                        "char": 36
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 41,
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
                            "name": "columnMap",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 43,
                            "char": 22
                        },
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 44,
                            "char": 18
                        },
                        {
                            "type": "parameter",
                            "name": "result",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 45,
                            "char": 15
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 46,
                                "char": 32
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 46,
                                "char": 40
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 46,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "keepSnapshots",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 48,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 48,
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
                                    "property": "model",
                                    "expr": {
                                        "type": "variable",
                                        "value": "model",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 49,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 49,
                                    "char": 32
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "columnMap",
                                    "expr": {
                                        "type": "variable",
                                        "value": "columnMap",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 50,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 50,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 54,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "keepSnapshots",
                                    "expr": {
                                        "type": "variable",
                                        "value": "keepSnapshots",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 54,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 54,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 56,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 56,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 56,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 56,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 56,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 56,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 57,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Resultset\\Simple constructor\n     *\n     * @param array                                             columnMap\n     * @param \\Phalcon\\Mvc\\ModelInterface|Phalcon\\Mvc\\Model\\Row model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                        "line": 48,
                        "char": 15
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 42,
                    "last-line": 61,
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 64,
                                    "char": 16
                                },
                                {
                                    "variable": "hydrateMode",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 64,
                                    "char": 29
                                },
                                {
                                    "variable": "columnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 64,
                                    "char": 40
                                },
                                {
                                    "variable": "activeRow",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 64,
                                    "char": 51
                                },
                                {
                                    "variable": "modelName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 64,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 66,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 66,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRow",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 66,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 66,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 66,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 68,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "activeRow",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 68,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 68,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 68,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "activeRow",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 69,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 70,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 75,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 75,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "row",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 75,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 75,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 75,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 80,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 80,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 80,
                                    "char": 24
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 80,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 80,
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
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 81,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 81,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 83,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 83,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 84,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 89,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 89,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "hydrateMode",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 89,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 89,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 89,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 94,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columnMap",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 94,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "columnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 94,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 94,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 94,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 99,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "hydrateMode",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 99,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 100,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HYDRATE_RECORDS",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 100,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 100,
                                        "char": 44
                                    },
                                    "statements": [
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
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 105,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 105,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 105,
                                                "char": 56
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "instanceof",
                                                        "left": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 106,
                                                                "char": 29
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "model",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 106,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 106,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "Model",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 106,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 106,
                                                        "char": 53
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
                                                                                    "type": "property-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                        "line": 107,
                                                                                        "char": 56
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "model",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                        "line": 107,
                                                                                        "char": 62
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                    "line": 107,
                                                                                    "char": 62
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 107,
                                                                                "char": 62
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 107,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 107,
                                                                    "char": 63
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 108,
                                                            "char": 21
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
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 109,
                                                                        "char": 60
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 109,
                                                                    "char": 60
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 110,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 112,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "activeRow",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 1,
                                                                "class": "modelName",
                                                                "dynamic": 0,
                                                                "name": "cloneResultMap",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 113,
                                                                                "char": 30
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "model",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 113,
                                                                                "char": 36
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 113,
                                                                            "char": 36
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 113,
                                                                        "char": 36
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "row",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 114,
                                                                            "char": 28
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 114,
                                                                        "char": 28
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "columnMap",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 115,
                                                                            "char": 34
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 115,
                                                                        "char": 34
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "static-constant-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "Model",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 116,
                                                                                "char": 54
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "DIRTY_STATE_PERSISTENT",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 116,
                                                                                "char": 54
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 116,
                                                                            "char": 54
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 116,
                                                                        "char": 54
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 117,
                                                                                "char": 30
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "keepSnapshots",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 118,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 118,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 118,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 118,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 118,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 119,
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
                                                            "variable": "activeRow",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Model",
                                                                "dynamic": 0,
                                                                "name": "cloneResultMap",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 121,
                                                                                "char": 30
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "model",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 121,
                                                                                "char": 36
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 121,
                                                                            "char": 36
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 121,
                                                                        "char": 36
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "row",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 122,
                                                                            "char": 28
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 122,
                                                                        "char": 28
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "columnMap",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 123,
                                                                            "char": 34
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 123,
                                                                        "char": 34
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "static-constant-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "Model",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 124,
                                                                                "char": 54
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "DIRTY_STATE_PERSISTENT",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 124,
                                                                                "char": 54
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 124,
                                                                            "char": 54
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 124,
                                                                        "char": 54
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 125,
                                                                                "char": 30
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "keepSnapshots",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 126,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 126,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 126,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 126,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 126,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 127,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 129,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 131,
                                            "char": 19
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 131,
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
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Model",
                                                        "dynamic": 0,
                                                        "name": "cloneResultMapHydrate",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "row",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 136,
                                                                    "char": 24
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 136,
                                                                "char": 24
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "columnMap",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 137,
                                                                    "char": 30
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 137,
                                                                "char": 30
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "hydrateMode",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 139,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 139,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 139,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 139,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 141,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 142,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 144,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 144,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 144,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 146,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "activeRow",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 146,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 147,
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 62,
                                    "char": 57
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 62,
                                "char": 57
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 63,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 62,
                    "last-line": 154,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "renameColumns",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 155,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 155,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 157,
                                    "char": 19
                                },
                                {
                                    "variable": "records",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 157,
                                    "char": 28
                                },
                                {
                                    "variable": "record",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 157,
                                    "char": 36
                                },
                                {
                                    "variable": "renamedKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 157,
                                    "char": 48
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 157,
                                    "char": 53
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 157,
                                    "char": 60
                                },
                                {
                                    "variable": "columnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 157,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 158,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "renamedRecords",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 158,
                                    "char": 29
                                },
                                {
                                    "variable": "renamed",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 158,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 164,
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
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 164,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rows",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 164,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 164,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 164,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 166,
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
                                        "value": "records",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 166,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 166,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 166,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 166,
                                "char": 36
                            },
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 167,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "result",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 167,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 167,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 167,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 169,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 169,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "row",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 169,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 169,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 169,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 169,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "result",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 171,
                                                    "char": 24
                                                },
                                                "name": "execute",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 171,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 172,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 174,
                                    "char": 15
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
                                                    "value": "result",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 174,
                                                    "char": 34
                                                },
                                                "name": "fetchAll",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 174,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 174,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 176,
                                    "char": 15
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
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 176,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 176,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 177,
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
                                                "type": "variable",
                                                "value": "records",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 177,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 177,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 178,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 183,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "renameColumns",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 183,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnMap",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 187,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "columnMap",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 187,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 187,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 187,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 189,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "columnMap",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 189,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 189,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 189,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 189,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "records",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 190,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 191,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 193,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "renamedRecords",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 193,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 193,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 195,
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
                                                "value": "records",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 195,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 195,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 195,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 195,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "records",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 196,
                                                "char": 39
                                            },
                                            "value": "record",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "renamed",
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 197,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 197,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 199,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "record",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 199,
                                                        "char": 46
                                                    },
                                                    "key": "key",
                                                    "value": "value",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "unlikely",
                                                                "left": {
                                                                    "type": "not",
                                                                    "left": {
                                                                        "type": "fetch",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "renamedKey",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 203,
                                                                            "char": 71
                                                                        },
                                                                        "right": {
                                                                            "type": "array-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "columnMap",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 203,
                                                                                "char": 65
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "key",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 203,
                                                                                "char": 69
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 203,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 203,
                                                                        "char": 71
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 203,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 203,
                                                                "char": 71
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
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "string",
                                                                                            "value": "Column '",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                            "line": 205,
                                                                                            "char": 42
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "key",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                            "line": 205,
                                                                                            "char": 48
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                        "line": 205,
                                                                                        "char": 48
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": "' is not part of the column map",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                        "line": 206,
                                                                                        "char": 29
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                    "line": 206,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 206,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 206,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 207,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 209,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "typeof",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "renamedKey",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 209,
                                                                        "char": 47
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 209,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "array",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 209,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 209,
                                                                "char": 55
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "if",
                                                                    "expr": {
                                                                        "type": "unlikely",
                                                                        "left": {
                                                                            "type": "not",
                                                                            "left": {
                                                                                "type": "fetch",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "renamedKey",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                    "line": 210,
                                                                                    "char": 74
                                                                                },
                                                                                "right": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "renamedKey",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                        "line": 210,
                                                                                        "char": 70
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "int",
                                                                                        "value": "0",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                        "line": 210,
                                                                                        "char": 72
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                    "line": 210,
                                                                                    "char": 74
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 210,
                                                                                "char": 74
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 210,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 210,
                                                                        "char": 74
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
                                                                                            "type": "concat",
                                                                                            "left": {
                                                                                                "type": "concat",
                                                                                                "left": {
                                                                                                    "type": "string",
                                                                                                    "value": "Column '",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                                    "line": 212,
                                                                                                    "char": 46
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "variable",
                                                                                                    "value": "key",
                                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                                    "line": 212,
                                                                                                    "char": 52
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                                "line": 212,
                                                                                                "char": 52
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "string",
                                                                                                "value": "' is not part of the column map",
                                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                                "line": 213,
                                                                                                "char": 33
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                            "line": 213,
                                                                                            "char": 33
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                        "line": 213,
                                                                                        "char": 33
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                                "line": 213,
                                                                                "char": 34
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 214,
                                                                            "char": 29
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 215,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 217,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "renamed",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "renamedKey",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                            "line": 217,
                                                                            "char": 47
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                        "line": 217,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                    "line": 217,
                                                                    "char": 56
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 218,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 223,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "renamedRecords",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "renamed",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 223,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 223,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 224,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 225,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 227,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "renamedRecords",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 227,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 228,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 230,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "records",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 230,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 231,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a complete resultset as an array, if the resultset has a big\n     * number of rows it could consume more memory than currently it does.\n     * Export the resultset to an array couldn't be faster with a large number\n     * of records\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 156,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                        "line": 156,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 155,
                    "last-line": 235,
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
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 238,
                                    "char": 22
                                },
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 238,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 239,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 239,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 241,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 241,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 241,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 243,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 243,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 243,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 243,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 243,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 243,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 246,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 246,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 246,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 247,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 249,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 250,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 250,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "model",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 250,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 250,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 250,
                                                "char": 40
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "cache",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 251,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 251,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "cache",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 251,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 251,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 251,
                                                "char": 40
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "rows",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 252,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 252,
                                                        "char": 34
                                                    },
                                                    "name": "toArray",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 252,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 252,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 252,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 252,
                                                "char": 49
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "columnMap",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 253,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 253,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "columnMap",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 253,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 253,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 253,
                                                "char": 44
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "hydrateMode",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 254,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 254,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "hydrateMode",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 254,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 254,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 254,
                                                "char": 46
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "keepSnapshots",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 255,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 255,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "keepSnapshots",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 256,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 256,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 256,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 256,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 256,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 258,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 258,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 258,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 258,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 258,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 259,
                                                    "char": 84
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 259,
                                                        "char": 62
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "serializer",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 259,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 259,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 259,
                                                    "char": 84
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 259,
                                                "char": 84
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 259,
                                            "char": 84
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 260,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 260,
                                            "char": 24
                                        },
                                        "name": "setData",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 260,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 260,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 260,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 262,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 262,
                                            "char": 31
                                        },
                                        "name": "serialize",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 262,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 263,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 268,
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
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 268,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 268,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 268,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 269,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 237,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                        "line": 237,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 236,
                    "last-line": 274,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 275,
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 277,
                                    "char": 22
                                },
                                {
                                    "variable": "keepSnapshots",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 277,
                                    "char": 37
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 277,
                                    "char": 48
                                },
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 277,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 279,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 279,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 279,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 281,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 281,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 281,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 281,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 281,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 281,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 284,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 284,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 284,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 285,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 287,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 287,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 287,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 287,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 287,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 288,
                                                    "char": 84
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 288,
                                                        "char": 62
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "serializer",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                                "line": 288,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 288,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 288,
                                                    "char": 84
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 288,
                                                "char": 84
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 288,
                                            "char": 84
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 289,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 289,
                                                    "char": 40
                                                },
                                                "name": "unserialize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 289,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 289,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 289,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 289,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 290,
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
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                            "line": 291,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 291,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 291,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 291,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 292,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 294,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 294,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 294,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 294,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 294,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 294,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 295,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 295,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 295,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 296,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 298,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "model",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 298,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 298,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 298,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 298,
                                    "char": 49
                                },
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 299,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "rows",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 299,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 299,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 299,
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
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 300,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "rows",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                        "line": 300,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                    "line": 300,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 300,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 300,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 300,
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 301,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 301,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 301,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 301,
                                    "char": 49
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "columnMap",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 302,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "columnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 302,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 302,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 302,
                                    "char": 53
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 303,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "hydrateMode",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 303,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 303,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 303,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 305,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "keepSnapshots",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 305,
                                    "char": 58
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "resultset",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 305,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "keepSnapshots",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                        "line": 305,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 305,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                "line": 305,
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
                                            "property": "keepSnapshots",
                                            "expr": {
                                                "type": "variable",
                                                "value": "keepSnapshots",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                                "line": 306,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                            "line": 306,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                                    "line": 307,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                            "line": 308,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Unserializing a resultset will allow to only works on the rows present in\n     * the saved state\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                        "line": 276,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
                    "line": 275,
                    "last-line": 309,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
            "line": 27,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Resultset\/Simple.zep",
        "line": 27,
        "char": 5
    }
]