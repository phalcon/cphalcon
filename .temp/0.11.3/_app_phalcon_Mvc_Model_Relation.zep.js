[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\RelationInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                "line": 13,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Relation\n *\n * This class represents a relationship between two models\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Relation",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "RelationInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                "line": 21,
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
                    "name": "fields",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 32,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "intermediateFields",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 33,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "intermediateModel",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 34,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "intermediateReferencedFields",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 35,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 36,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "referencedFields",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 37,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "referencedModel",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 38,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
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
                            "name": "type",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 46,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "referencedModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 46,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 46,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "referencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 46,
                            "char": 100
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 46,
                                "char": 120
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 46,
                            "char": 120
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
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 48,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 48,
                                    "char": 30
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "referencedModel",
                                    "expr": {
                                        "type": "variable",
                                        "value": "referencedModel",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 49,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 49,
                                    "char": 52
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "fields",
                                    "expr": {
                                        "type": "variable",
                                        "value": "fields",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 50,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 50,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "referencedFields",
                                    "expr": {
                                        "type": "variable",
                                        "value": "referencedFields",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 51,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 51,
                                    "char": 54
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 52,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 52,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 53,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Relation constructor\n     *\n     * @param string|array fields\n     * @param string|array referencedFields\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 47,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 46,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFields",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 62,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "fields",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 62,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 62,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 63,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the fields\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 60,
                    "last-line": 69,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getForeignKey",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 72,
                                    "char": 20
                                },
                                {
                                    "variable": "foreignKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 72,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 74,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 74,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 74,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 74,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 74,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 76,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "foreignKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 76,
                                    "char": 50
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 76,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "foreignKey",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 76,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 76,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 76,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "foreignKey",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 77,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "foreignKey",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                                "line": 78,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 79,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 82,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 82,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the foreign key configuration\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 70,
                    "last-line": 89,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIntermediateFields",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 92,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "intermediateFields",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 92,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 92,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 93,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the intermediate fields for has-*-through relations\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 90,
                    "last-line": 97,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIntermediateModel",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 100,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "intermediateModel",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 100,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 100,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 101,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the intermediate model for has-*-through relations\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 99,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 99,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 98,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIntermediateReferencedFields",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 110,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "intermediateReferencedFields",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 110,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 110,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the intermediate referenced fields for has-*-through relations\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 108,
                    "last-line": 116,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 117,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "option",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 119,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 121,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "option",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 121,
                                        "char": 47
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                                "line": 121,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                                "line": 121,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 121,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 121,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 121,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 121,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 121,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 122,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 123,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 125,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "option",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 125,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 126,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an option by the specified name\n     * If the option doesn't exist null is returned\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 117,
                    "last-line": 130,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 133,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 133,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 133,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 134,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 132,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 132,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 131,
                    "last-line": 140,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParams",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 143,
                                    "char": 20
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 143,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 145,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 145,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 145,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 145,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 145,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 147,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 147,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 147,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 147,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 147,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 147,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 148,
                                        "char": 23
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                                "line": 149,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 150,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 151,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 153,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 153,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 154,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns parameters that must be always used when the related records are obtained\n     *\n     * @return array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 141,
                    "last-line": 158,
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
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 161,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "type",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 161,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 161,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 162,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the relation type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 160,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 160,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 159,
                    "last-line": 168,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReferencedFields",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 171,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "referencedFields",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 171,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 171,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 172,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the referenced fields\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 169,
                    "last-line": 176,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReferencedModel",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 179,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "referencedModel",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 179,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 179,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 180,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the referenced model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 178,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 178,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 177,
                    "last-line": 184,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isForeignKey",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "foreignKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 187,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 189,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "foreignKey",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 189,
                                        "char": 57
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                                "line": 189,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                                "line": 189,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 189,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "foreignKey",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 189,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 189,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 189,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 189,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 190,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 191,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 193,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "bool",
                                "right": {
                                    "type": "variable",
                                    "value": "foreignKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 193,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 193,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 194,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the relation act as a foreign key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 186,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 186,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 185,
                    "last-line": 198,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isThrough",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 201,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 203,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "type",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 203,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 203,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 203,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 203,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 205,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 205,
                                        "char": 22
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 205,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HAS_ONE_THROUGH",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 205,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 205,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 205,
                                    "char": 47
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 205,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 205,
                                            "char": 79
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HAS_MANY_THROUGH",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 205,
                                            "char": 79
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 205,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 205,
                                    "char": 79
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 205,
                                "char": 79
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 206,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the relation is a 'many-to-many' relation or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 200,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 200,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 199,
                    "last-line": 210,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isReusable",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 213,
                                    "char": 20
                                },
                                {
                                    "variable": "reusable",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 213,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 215,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 215,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 215,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 215,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 215,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 217,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "reusable",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 217,
                                        "char": 47
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 217,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "reusable",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                            "line": 217,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 217,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 217,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 217,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 218,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 219,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 221,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "reusable",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 221,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 222,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if records returned by getting belongs-to\/has-many are implicitly cached during the current request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                "line": 212,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 212,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 211,
                    "last-line": 229,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setIntermediateRelation",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "intermediateFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 230,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "intermediateModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 230,
                            "char": 94
                        },
                        {
                            "type": "parameter",
                            "name": "intermediateReferencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 230,
                            "char": 128
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
                                    "property": "intermediateFields",
                                    "expr": {
                                        "type": "variable",
                                        "value": "intermediateFields",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 232,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 232,
                                    "char": 58
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "intermediateModel",
                                    "expr": {
                                        "type": "variable",
                                        "value": "intermediateModel",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 233,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 233,
                                    "char": 56
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "intermediateReferencedFields",
                                    "expr": {
                                        "type": "variable",
                                        "value": "intermediateReferencedFields",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                        "line": 234,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                                    "line": 234,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                            "line": 235,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the intermediate model data for has-*-through relations\n     *\n     * @param string|array intermediateFields\n     * @param string       intermediateReferencedFields\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 230,
                    "last-line": 236,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "ACTION_CASCADE",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 22,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 23,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "ACTION_RESTRICT",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 23,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 24,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "BELONGS_TO",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 24,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 25,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HAS_MANY",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 25,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 26,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HAS_MANY_THROUGH",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 26,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 27,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HAS_ONE",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 27,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 28,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HAS_ONE_THROUGH",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 28,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 29,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NO_ACTION",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                        "line": 29,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
                    "line": 31,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Relation.zep",
        "line": 20,
        "char": 5
    }
]