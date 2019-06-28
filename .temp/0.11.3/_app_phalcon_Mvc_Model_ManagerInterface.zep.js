[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                "line": 13,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\BehaviorInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                "line": 15,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\RelationInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                "line": 16,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Query\\BuilderInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                "line": 17,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\QueryInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                "line": 18,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\ManagerInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Manager\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 25,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ManagerInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addBehavior",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 30,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 30,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "behavior",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "BehaviorInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 30,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 30,
                            "char": 85
                        }
                    ],
                    "docblock": "**\n     * Binds a behavior to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 30,
                        "char": 94
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 30,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addBelongsTo",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 39,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 39,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 39,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "referencedModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 39,
                            "char": 89
                        },
                        {
                            "type": "parameter",
                            "name": "referencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 39,
                            "char": 107
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 39,
                                "char": 123
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 39,
                            "char": 123
                        }
                    ],
                    "docblock": "**\n     * Setup a relation reverse 1-1  between two models\n     *\n     * @param    mixed  fields\n     * @param    mixed  referencedFields\n     * @param    array  options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 39,
                                    "char": 147
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 39,
                                "char": 147
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 39,
                        "char": 147
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 39,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addHasMany",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 48,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 48,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 48,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "referencedModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 48,
                            "char": 87
                        },
                        {
                            "type": "parameter",
                            "name": "referencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 48,
                            "char": 105
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 48,
                                "char": 121
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 48,
                            "char": 121
                        }
                    ],
                    "docblock": "**\n     * Setup a relation 1-n between two models\n     *\n     * @param    mixed  fields\n     * @param    mixed  referencedFields\n     * @param    array  options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 48,
                                    "char": 145
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 48,
                                "char": 145
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 48,
                        "char": 145
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 48,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addHasOne",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 57,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 57,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 57,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "referencedModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 57,
                            "char": 86
                        },
                        {
                            "type": "parameter",
                            "name": "referencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 57,
                            "char": 104
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 57,
                                "char": 120
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 57,
                            "char": 120
                        }
                    ],
                    "docblock": "**\n     * Setup a 1-1 relation between two models\n     *\n     * @param    mixed  fields\n     * @param    mixed  referencedFields\n     * @param    array  options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 57,
                                    "char": 144
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 57,
                                "char": 144
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 57,
                        "char": 144
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 57,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addHasManyToMany",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 68,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 68,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 68,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "intermediateModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 68,
                            "char": 99
                        },
                        {
                            "type": "parameter",
                            "name": "intermediateFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 69,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "intermediateReferencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 69,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "referencedModel",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 69,
                            "char": 90
                        },
                        {
                            "type": "parameter",
                            "name": "referencedFields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 69,
                            "char": 112
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 69,
                                "char": 132
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 69,
                            "char": 132
                        }
                    ],
                    "docblock": "**\n     * Setups a relation n-m between two models\n     *\n     * @param    string fields\n     * @param    string intermediateFields\n     * @param    string intermediateReferencedFields\n     * @param    string referencedFields\n     * @param   array options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 69,
                                    "char": 156
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 69,
                                "char": 156
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 69,
                        "char": 156
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 68,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createBuilder",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 76,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 76,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Creates a Phalcon\\Mvc\\Model\\Query\\Builder\n     *\n     * @param string $params\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BuilderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 76,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 76,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 76,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createQuery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "phql",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 81,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Creates a Phalcon\\Mvc\\Model\\Query without execute it\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 81,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 81,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 81,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 81,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "executeQuery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "phql",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 88,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 88,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 88,
                            "char": 71
                        }
                    ],
                    "docblock": "**\n     * Creates a Phalcon\\Mvc\\Model\\Query and execute it\n     *\n     * @param array $placeholders\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 88,
                                    "char": 92
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 88,
                                "char": 92
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 88,
                        "char": 92
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 88,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "existsBelongsTo",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 93,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "modelRelation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 93,
                            "char": 77
                        }
                    ],
                    "docblock": "**\n     * Checks whether a model has a belongsTo relation with another model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 93,
                                "char": 86
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 93,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 93,
                    "last-line": 97,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "existsHasMany",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 98,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "modelRelation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 98,
                            "char": 75
                        }
                    ],
                    "docblock": "**\n     * Checks whether a model has a hasMany relation with another model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 98,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 98,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 98,
                    "last-line": 102,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "existsHasOne",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 103,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "modelRelation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 103,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Checks whether a model has a hasOne relation with another model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 103,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 103,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 103,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "existsHasManyToMany",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 108,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "modelRelation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 108,
                            "char": 81
                        }
                    ],
                    "docblock": "**\n     * Checks whether a model has a hasManyToMany relation with another model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 108,
                                "char": 90
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 108,
                        "char": 90
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 108,
                    "last-line": 112,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBelongsTo",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 113,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 113,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Gets belongsTo relations defined on a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 113,
                                    "char": 83
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 113,
                                "char": 83
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 113,
                                "char": 90
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 113,
                        "char": 90
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 113,
                    "last-line": 123,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBelongsToRecords",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 124,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "modelRelation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 124,
                            "char": 81
                        },
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 124,
                                "char": 105
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 124,
                            "char": 106
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 124,
                                "char": 125
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 124,
                            "char": 125
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 124,
                                "char": 147
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 124,
                            "char": 147
                        }
                    ],
                    "docblock": "**\n     * Gets belongsTo related records from a model\n     *\n     * @param string            $modelName\n     * @param string            $modelRelation\n     * @param array|string|null $parameters\n     * @param ModelInterface    $record\n     * @param string|null       $method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 124,
                                    "char": 173
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 124,
                                "char": 173
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 124,
                                "char": 179
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 124,
                        "char": 179
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 124,
                    "last-line": 128,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHasMany",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 129,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 129,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Gets hasMany relations defined on a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 129,
                                    "char": 81
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 129,
                                "char": 81
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 129,
                                "char": 88
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 129,
                        "char": 88
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 129,
                    "last-line": 139,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHasManyRecords",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 140,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "modelRelation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 140,
                            "char": 79
                        },
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 140,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 140,
                            "char": 104
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 140,
                                "char": 123
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 140,
                            "char": 123
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 140,
                                "char": 145
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 140,
                            "char": 145
                        }
                    ],
                    "docblock": "**\n     * Gets hasMany related records from a model\n     *\n     * @param string            $modelName\n     * @param string            $modelRelation\n     * @param array|string|null $parameters\n     * @param ModelInterface    $record\n     * @param string|null       $method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResultsetInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 140,
                                    "char": 171
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 140,
                                "char": 171
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 140,
                                "char": 177
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 140,
                        "char": 177
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 140,
                    "last-line": 144,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHasManyToMany",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 145,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 145,
                            "char": 60
                        }
                    ],
                    "docblock": "**\n     * Gets hasManyToMany relations defined on a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 145,
                                    "char": 87
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 145,
                                "char": 87
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 145,
                                "char": 94
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 145,
                        "char": 94
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 145,
                    "last-line": 149,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHasOne",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 150,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 150,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Gets hasOne relations defined on a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 150,
                                    "char": 80
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 150,
                                "char": 80
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 150,
                                "char": 87
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 150,
                        "char": 87
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 150,
                    "last-line": 154,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHasOneAndHasMany",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 155,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 155,
                            "char": 63
                        }
                    ],
                    "docblock": "**\n     * Gets hasOne relations defined on a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 155,
                                    "char": 89
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 155,
                                "char": 89
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 155,
                        "char": 89
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 155,
                    "last-line": 165,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHasOneRecords",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 166,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "modelRelation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 166,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 166,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 166,
                            "char": 103
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 166,
                                "char": 122
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 166,
                            "char": 122
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 166,
                                "char": 144
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 166,
                            "char": 144
                        }
                    ],
                    "docblock": "**\n     * Gets belongsTo related records from a model\n     *\n     * @param string            $modelName\n     * @param string            $modelRelation\n     * @param array|string|null $parameters\n     * @param ModelInterface    $record\n     * @param string|null       $method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 166,
                                    "char": 166
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 166,
                                "char": 166
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 166,
                                "char": 172
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 166,
                        "char": 172
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 166,
                    "last-line": 170,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastInitialized",
                    "docblock": "**\n     * Get last initialized model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 171,
                                    "char": 61
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 171,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 171,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 171,
                    "last-line": 175,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastQuery",
                    "docblock": "**\n     * Returns the last query created or executed in the models manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "QueryInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 176,
                                    "char": 55
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 176,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 176,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 176,
                    "last-line": 180,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModelSchema",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 181,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 181,
                            "char": 58
                        }
                    ],
                    "docblock": "**\n     * Returns the mapped schema for a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 181,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 181,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 181,
                    "last-line": 185,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModelSource",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 186,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 186,
                            "char": 58
                        }
                    ],
                    "docblock": "**\n     * Returns the mapped source for a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 186,
                                "char": 69
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 186,
                        "char": 69
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 186,
                    "last-line": 190,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReadConnection",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 191,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 191,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Returns the connection to read data related to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 191,
                                    "char": 84
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 191,
                                "char": 84
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 191,
                        "char": 84
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 191,
                    "last-line": 195,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReadConnectionService",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 196,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 196,
                            "char": 68
                        }
                    ],
                    "docblock": "**\n     * Returns the connection service name used to read data related to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 196,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 196,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 196,
                    "last-line": 200,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRelationByAlias",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 201,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 201,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Returns a relation by its alias\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Relation",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 201,
                                    "char": 88
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 201,
                                "char": 88
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 201,
                                "char": 94
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 201,
                        "char": 94
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 201,
                    "last-line": 207,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRelationRecords",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "relation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "RelationInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 208,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 208,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 208,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 208,
                            "char": 93
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 208,
                                "char": 116
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 208,
                            "char": 116
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 208,
                                "char": 138
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 208,
                            "char": 138
                        }
                    ],
                    "docblock": "**\n     * Helper method to query records based on a relation definition\n     *\n     * @return \\Phalcon\\Mvc\\Model\\Resultset\\Simple|Phalcon\\Mvc\\Model\\Resultset\\Simple|int|false\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 208,
                    "last-line": 212,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRelations",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 213,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Query all the relationships defined on a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 213,
                                    "char": 77
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 213,
                                "char": 77
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 213,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 213,
                    "last-line": 217,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRelationsBetween",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "first",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 218,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "second",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 218,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Query the relations between two models\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RelationInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 218,
                                    "char": 97
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 218,
                                "char": 97
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 218,
                                "char": 103
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 218,
                        "char": 103
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 218,
                    "last-line": 222,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getWriteConnection",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 223,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 223,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Returns the connection to write data related to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 223,
                                    "char": 85
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 223,
                                "char": 85
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 223,
                        "char": 85
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 223,
                    "last-line": 227,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getWriteConnectionService",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 228,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 228,
                            "char": 69
                        }
                    ],
                    "docblock": "**\n     * Returns the connection service name used to write data related to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 228,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 228,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 228,
                    "last-line": 232,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "load",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modelName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 233,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Loads a model throwing an exception if it doesn't exist\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                    "line": 233,
                                    "char": 63
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 233,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 233,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 233,
                    "last-line": 237,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "initialize",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 238,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 238,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Initializes a model in the model manager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 238,
                    "last-line": 242,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isInitialized",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 243,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Check of a model is already initialized\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 243,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 243,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 243,
                    "last-line": 247,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isKeepingSnapshots",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 248,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 248,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Checks if a model is keeping snapshots for the queried records\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 248,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 248,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 248,
                    "last-line": 252,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUsingDynamicUpdate",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 253,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 253,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Checks if a model is using dynamic update instead of all-field update\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 253,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 253,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 253,
                    "last-line": 264,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "isVisibleModelProperty",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 265,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 265,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "property",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 265,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Check whether a model property is declared as public.\n     *\n     * ```php\n     * $isPublic = $manager->isVisibleModelProperty(\n     *     new Robots(),\n     *     \"name\"\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 265,
                                "char": 98
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 265,
                        "char": 98
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 265,
                    "last-line": 269,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "keepSnapshots",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 270,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 270,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "keepSnapshots",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 270,
                            "char": 77
                        }
                    ],
                    "docblock": "**\n     * Sets if a model must keep snapshots\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 270,
                        "char": 86
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 270,
                    "last-line": 279,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "missingMethod",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 280,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 280,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 280,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 280,
                            "char": 82
                        }
                    ],
                    "docblock": "**\n     * Dispatch an event to the listeners and behaviors\n     * This method expects that the endpoint listeners\/behaviors returns true\n     * meaning that a least one is implemented\n     *\n     * @param array data\n     * @return bool\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 280,
                    "last-line": 285,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notifyEvent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 286,
                            "char": 50
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 286,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 286,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Receives events generated in the models and dispatches them to an events-manager if available\n     * Notify the behaviors that are listening in the model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 286,
                    "last-line": 290,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setConnectionService",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 291,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 291,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 291,
                            "char": 91
                        }
                    ],
                    "docblock": "**\n     * Sets both write and read connection service for a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 291,
                        "char": 100
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 291,
                    "last-line": 295,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setReadConnectionService",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 296,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 296,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 296,
                            "char": 95
                        }
                    ],
                    "docblock": "**\n     * Sets read connection service for a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 296,
                        "char": 104
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 296,
                    "last-line": 300,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setModelSchema",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 301,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 301,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 301,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Sets the mapped schema for a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 301,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 301,
                    "last-line": 305,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setModelSource",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 306,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 306,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "source",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 306,
                            "char": 74
                        }
                    ],
                    "docblock": "**\n     * Sets the mapped source for a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 306,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 306,
                    "last-line": 310,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setWriteConnectionService",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 311,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 311,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 311,
                            "char": 96
                        }
                    ],
                    "docblock": "**\n     * Sets write connection service for a model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 311,
                    "last-line": 315,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useDynamicUpdate",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                                "line": 316,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 316,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "dynamicUpdate",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                            "line": 316,
                            "char": 80
                        }
                    ],
                    "docblock": "**\n     * Sets if a model must use dynamic update instead of the all-field update\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                        "line": 316,
                        "char": 89
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
                    "line": 316,
                    "last-line": 317,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
            "line": 317,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/ManagerInterface.zep",
        "line": 0,
        "char": 0
    }
]