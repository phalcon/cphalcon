[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\RelationInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Relation\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "RelationInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFields",
                    "docblock": "**\n     * Returns the fields\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 25,
                    "last-line": 31,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getForeignKey",
                    "docblock": "**\n     * Returns the foreign key configuration\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 32,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIntermediateFields",
                    "docblock": "**\n     * Gets the intermediate fields for has-*-through relations\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 39,
                    "last-line": 43,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIntermediateModel",
                    "docblock": "**\n     * Gets the intermediate model for has-*-through relations\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                                "line": 44,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                        "line": 44,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 44,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIntermediateReferencedFields",
                    "docblock": "**\n     * Gets the intermediate referenced fields for has-*-through relations\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 51,
                    "last-line": 56,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                            "line": 57,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Returns an option by the specified name\n     * If the option doesn't exist null is returned\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 57,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "docblock": "**\n     * Returns the options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                                "line": 62,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                        "line": 62,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 62,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParams",
                    "docblock": "**\n     * Returns parameters that must be always used when the related records are obtained\n     *\n     * @return array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 69,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReferencedFields",
                    "docblock": "**\n     * Returns the referenced fields\n     *\n     * @return string|array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReferencedModel",
                    "docblock": "**\n     * Returns the referenced model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                                "line": 81,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                        "line": 81,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 81,
                    "last-line": 85,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "docblock": "**\n     * Returns the relations type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                                "line": 86,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                        "line": 86,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 86,
                    "last-line": 90,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isForeignKey",
                    "docblock": "**\n     * Check whether the relation act as a foreign key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                                "line": 91,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                        "line": 91,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 91,
                    "last-line": 95,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isReusable",
                    "docblock": "**\n     * Check if records returned by getting belongs-to\/has-many are implicitly cached during the current request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                                "line": 96,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                        "line": 96,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 96,
                    "last-line": 100,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isThrough",
                    "docblock": "**\n     * Check whether the relation is a 'many-to-many' relation or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                                "line": 101,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                        "line": 101,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 101,
                    "last-line": 108,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                            "line": 109,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "intermediateModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                            "line": 109,
                            "char": 94
                        },
                        {
                            "type": "parameter",
                            "name": "intermediateReferencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                            "line": 109,
                            "char": 128
                        }
                    ],
                    "docblock": "**\n     * Sets the intermediate model dat for has-*-through relations\n     *\n     * @param string|array intermediateFields\n     * @param string|array intermediateReferencedFields\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
                    "line": 109,
                    "last-line": 110,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
            "line": 110,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/RelationInterface.zep",
        "line": 0,
        "char": 0
    }
]