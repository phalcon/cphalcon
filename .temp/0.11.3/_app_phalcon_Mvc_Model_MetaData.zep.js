[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 15,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 16,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData\\Strategy\\Introspection",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 17,
                "char": 54
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 18,
                "char": 49
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "alias": "CacheAdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 19,
                "char": 68
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 40,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaData\n *\n * Because Phalcon\\Mvc\\Model requires meta-data like field names, data types,\n * primary keys, etc. This component collect them and store for further\n * querying by Phalcon\\Mvc\\Model. Phalcon\\Mvc\\Model\\MetaData can also use\n * adapters to store temporarily or permanently the meta-data.\n *\n * A standard Phalcon\\Mvc\\Model\\MetaData can be used to query model attributes:\n *\n * ```php\n * $metaData = new \\Phalcon\\Mvc\\Model\\MetaData\\Memory();\n *\n * $attributes = $metaData->getAttributes(\n *     new Robots()\n * );\n *\n * print_r($attributes);\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 41,
        "char": 8
    },
    {
        "type": "class",
        "name": "MetaData",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 41,
                "char": 59
            },
            {
                "type": "variable",
                "value": "MetaDataInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                "line": 42,
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
                    "name": "adapter",
                    "docblock": "**\n     * @var CacheAdapterInterface\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 65,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "columnMap",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 67,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 69,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "metaData",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 69,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 71,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "strategy",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 83,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 84,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 84,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 86,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 88,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 88,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 88,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 88,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 88,
                                                        "char": 74
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_ATTRIBUTES",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 88,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 88,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 88,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 88,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 88,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 90,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 90,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 90,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 90,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 90,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 90,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 91,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 91,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 91,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 92,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 94,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 94,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns table attributes names (fields)\n     *\n     *```php\n     * print_r(\n     *     $metaData->getAttributes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 85,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 85,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 84,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAutomaticCreateAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 108,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 108,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 110,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 112,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 112,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 113,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 113,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 115,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_AUTOMATIC_DEFAULT_INSERT",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 115,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 115,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 115,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 115,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 115,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 117,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 117,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 117,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 117,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 117,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 117,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 118,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 118,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 118,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 119,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 121,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 121,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 122,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns attributes that must be ignored from the INSERT SQL generation\n     *\n     *```php\n     * print_r(\n     *     $metaData->getAutomaticCreateAttributes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 108,
                    "last-line": 134,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAutomaticUpdateAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 135,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 135,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 137,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 139,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 139,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 140,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 140,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 142,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_AUTOMATIC_DEFAULT_UPDATE",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 142,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 142,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 142,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 142,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 142,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 144,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 144,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 144,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 144,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 144,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 144,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 145,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 145,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 145,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 146,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 148,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 148,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 149,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns attributes that must be ignored from the UPDATE SQL generation\n     *\n     *```php\n     * print_r(\n     *     $metaData->getAutomaticUpdateAttributes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 136,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 136,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 135,
                    "last-line": 161,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBindTypes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 162,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 162,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 164,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 166,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 166,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 167,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 167,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 169,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_DATA_TYPES_BIND",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 169,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 169,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 169,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 169,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 169,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 171,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 171,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 171,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 171,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 171,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 171,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 172,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 172,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 172,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 173,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 175,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 175,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 176,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns attributes and their bind data types\n     *\n     *```php\n     * print_r(\n     *     $metaData->getBindTypes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 163,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 162,
                    "last-line": 188,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnMap",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 189,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 189,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 191,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 193,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 193,
                                            "char": 25
                                        },
                                        "name": "readColumnMapIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 193,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 193,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 193,
                                                        "char": 75
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_COLUMN_MAP",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 193,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 193,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 193,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 193,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 193,
                                    "char": 76
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 195,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 195,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 195,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 195,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 195,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 195,
                                                "char": 52
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 195,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 195,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 195,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 195,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 195,
                                "char": 61
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 196,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 196,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 196,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 197,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 199,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 199,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 200,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the column map if any\n     *\n     *```php\n     * print_r(\n     *     $metaData->getColumnMap(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 190,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 190,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 189,
                    "last-line": 212,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultValues",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 213,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 213,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 215,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 217,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 217,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 217,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 217,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 217,
                                                        "char": 78
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_DEFAULT_VALUES",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 217,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 217,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 217,
                                                "char": 78
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 217,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 217,
                                    "char": 79
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 219,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 219,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 219,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 219,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 219,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 219,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 220,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 220,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 220,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 221,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 223,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 223,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 224,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns attributes (which have default values) and their default values\n     *\n     *```php\n     * print_r(\n     *     $metaData->getDefaultValues(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 214,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 214,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 213,
                    "last-line": 236,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDataTypes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 237,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 237,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 239,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 241,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 241,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 241,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 241,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 241,
                                                        "char": 74
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_DATA_TYPES",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 241,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 241,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 241,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 241,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 241,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 243,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 243,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 243,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 243,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 243,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 244,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 244,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 244,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 245,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 247,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 247,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 248,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns attributes and their data types\n     *\n     *```php\n     * print_r(\n     *     $metaData->getDataTypes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 238,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 238,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 237,
                    "last-line": 260,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDataTypesNumeric",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 261,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 261,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 263,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 265,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 265,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 266,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 266,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 268,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_DATA_TYPES_NUMERIC",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 268,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 268,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 268,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 268,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 268,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 270,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 270,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 270,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 270,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 270,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 270,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 271,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 271,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 271,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 272,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 274,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 274,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 275,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns attributes which types are numerical\n     *\n     *```php\n     * print_r(\n     *     $metaData->getDataTypesNumeric(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 262,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 262,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 261,
                    "last-line": 279,
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 282,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 282,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 282,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 283,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 281,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 281,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 281,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 280,
                    "last-line": 295,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEmptyStringAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 296,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 296,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 298,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 300,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 300,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 301,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 301,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 303,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_EMPTY_STRING_VALUES",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 303,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 303,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 303,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 303,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 303,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 305,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 305,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 305,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 305,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 305,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 306,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 306,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 306,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 307,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 309,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 309,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 310,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns attributes allow empty strings\n     *\n     *```php\n     * print_r(\n     *     $metaData->getEmptyStringAttributes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 297,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 297,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 296,
                    "last-line": 325,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getIdentityField",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 326,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 326,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 328,
                                    "char": 21
                                },
                                "name": "readMetaDataIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 328,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 328,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 328,
                                                "char": 75
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_IDENTITY_COLUMN",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 328,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 328,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 328,
                                        "char": 75
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 328,
                                "char": 76
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 329,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the name of identity field (if one is present)\n     *\n     *```php\n     * print_r(\n     *     $metaData->getIdentityField(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *\n     * @param  Phalcon\\Mvc\\ModelInterface model\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 327,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 327,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 326,
                    "last-line": 341,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNonPrimaryKeyAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 342,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 342,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 344,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 346,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 346,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 346,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 346,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 346,
                                                        "char": 79
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_NON_PRIMARY_KEY",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 346,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 346,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 346,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 346,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 346,
                                    "char": 80
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 348,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 348,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 348,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 348,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 348,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 348,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 349,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 349,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 349,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 350,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 352,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 352,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 353,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of fields which are not part of the primary key\n     *\n     *```php\n     * print_r(\n     *     $metaData->getNonPrimaryKeyAttributes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 343,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 343,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 342,
                    "last-line": 365,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNotNullAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 366,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 366,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 368,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 370,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 370,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 370,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 370,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 370,
                                                        "char": 72
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_NOT_NULL",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 370,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 370,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 370,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 370,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 370,
                                    "char": 73
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 372,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 372,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 372,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 372,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 372,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 372,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 373,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 373,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 373,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 374,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 376,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 376,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 377,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of not null attributes\n     *\n     *```php\n     * print_r(\n     *     $metaData->getNotNullAttributes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 367,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 367,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 366,
                    "last-line": 389,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrimaryKeyAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 390,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 390,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 392,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 394,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 394,
                                            "char": 25
                                        },
                                        "name": "readMetaDataIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 394,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 394,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 394,
                                                        "char": 75
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_PRIMARY_KEY",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 394,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 394,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 394,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 394,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 394,
                                    "char": 76
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 396,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 396,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 396,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 396,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 396,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 396,
                                "char": 42
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 397,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 397,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 397,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 398,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 400,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 400,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 401,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of fields which are part of the primary key\n     *\n     *```php\n     * print_r(\n     *     $metaData->getPrimaryKeyAttributes(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 391,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 391,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 390,
                    "last-line": 413,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReverseColumnMap",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 414,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 414,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 416,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 418,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 418,
                                            "char": 25
                                        },
                                        "name": "readColumnMapIndex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 419,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 419,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 421,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "MODELS_REVERSE_COLUMN_MAP",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 421,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 421,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 421,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 421,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 421,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 423,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 423,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 423,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 423,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 423,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 423,
                                                "char": 52
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 423,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 423,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 423,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 423,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 423,
                                "char": 61
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
                                                    "value": "The meta-data is invalid or is corrupt",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 424,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 424,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 424,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 425,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 427,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 427,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 428,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the reverse column map if any\n     *\n     *```php\n     * print_r(\n     *     $metaData->getReverseColumnMap(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 415,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 415,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 414,
                    "last-line": 432,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStrategy",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 435,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "strategy",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 435,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 435,
                                    "char": 29
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 435,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 435,
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
                                            "property": "strategy",
                                            "expr": {
                                                "type": "new",
                                                "class": "Introspection",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 436,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 436,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 437,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 439,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 439,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "strategy",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 439,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 439,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 440,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the strategy to obtain the meta-data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "StrategyInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 434,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 434,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 434,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 433,
                    "last-line": 453,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasAttribute",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 454,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 454,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 454,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 456,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 458,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 458,
                                            "char": 30
                                        },
                                        "name": "getReverseColumnMap",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 458,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 458,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 458,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 458,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 460,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "columnMap",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 460,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 460,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 460,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 460,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "columnMap",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 461,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "attribute",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 461,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 461,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 461,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 462,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 464,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 464,
                                                "char": 27
                                            },
                                            "name": "readMetaData",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "model",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 464,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 464,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 464,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 464,
                                                "char": 71
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DATA_TYPES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 464,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 464,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 464,
                                        "char": 72
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "attribute",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 464,
                                        "char": 82
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 464,
                                    "char": 83
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 464,
                                "char": 83
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 465,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a model has certain attribute\n     *\n     *```php\n     * var_dump(\n     *     $metaData->hasAttribute(\n     *         new Robots(),\n     *         \"name\"\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 455,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 455,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 454,
                    "last-line": 475,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isEmpty",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 478,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "metaData",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 478,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 478,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 478,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 478,
                                    "char": 39
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 478,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 478,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 479,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if the internal meta-data container is empty\n     *\n     *```php\n     * var_dump(\n     *     $metaData->isEmpty()\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 477,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 477,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 476,
                    "last-line": 483,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "read",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 484,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 486,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 486,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 486,
                                    "char": 30
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 486,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 486,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 486,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 487,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads metadata from the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 484,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 485,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 485,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 484,
                    "last-line": 499,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "readColumnMap",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 500,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 500,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "keyName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 502,
                                    "char": 20
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 502,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 504,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "globals_get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "orm.column_renaming",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 504,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 504,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 504,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 504,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 505,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 506,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 508,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "keyName",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class_lower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 508,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 508,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 508,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 508,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 510,
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
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 510,
                                        "char": 50
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 510,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "columnMap",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 510,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 510,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "keyName",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 510,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 510,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 510,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 510,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 511,
                                            "char": 18
                                        },
                                        "name": "initialize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 511,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 511,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 511,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 511,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 511,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 511,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 511,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 511,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 511,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 513,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 513,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "columnMap",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 513,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 513,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "keyName",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 513,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 513,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 513,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 514,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 516,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 516,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 517,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads the ordered\/reversed column map for certain model\n     *\n     *```php\n     * print_r(\n     *     $metaData->readColumnMap(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 500,
                                "char": 74
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 501,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 501,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 500,
                    "last-line": 530,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "readColumnMapIndex",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 531,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 531,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 531,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "keyName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 533,
                                    "char": 20
                                },
                                {
                                    "variable": "columnMapModel",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 533,
                                    "char": 36
                                },
                                {
                                    "variable": "map",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 533,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 535,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "globals_get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "orm.column_renaming",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 535,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 535,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 535,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 535,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 536,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 537,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 539,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "keyName",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class_lower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 539,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 539,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 539,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 539,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 541,
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
                                        "value": "columnMapModel",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 541,
                                        "char": 60
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 541,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "columnMap",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 541,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 541,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "keyName",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 541,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 541,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 541,
                                    "char": 60
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 541,
                                "char": 60
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 542,
                                            "char": 18
                                        },
                                        "name": "initialize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 542,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 542,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 542,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 542,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 542,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 542,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 542,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 542,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 542,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 544,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnMapModel",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 544,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "columnMap",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 544,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 544,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "keyName",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 544,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 544,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 544,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 545,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 547,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "map",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 547,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "columnMapModel",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 547,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 547,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 547,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 547,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 549,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "map",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 549,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 550,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads column-map information for certain model using a MODEL_* constant\n     *\n     *```php\n     * print_r(\n     *     $metaData->readColumnMapIndex(\n     *         new Robots(),\n     *         MetaData::MODELS_REVERSE_COLUMN_MAP\n     *     )\n     * );\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 531,
                    "last-line": 562,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "readMetaData",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 563,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 563,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 565,
                                    "char": 19
                                },
                                {
                                    "variable": "schema",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 565,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 566,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 566,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 568,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 568,
                                            "char": 28
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 568,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 568,
                                    "char": 40
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "schema",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 569,
                                            "char": 28
                                        },
                                        "name": "getSchema",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 569,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 569,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 574,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "get_class_lower",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "model",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 574,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 574,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 574,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "-",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 574,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 574,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "schema",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 574,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 574,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "source",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 574,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 574,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 574,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 576,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 576,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "metaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 576,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 576,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 576,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 576,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 576,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 576,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 577,
                                            "char": 18
                                        },
                                        "name": "initialize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 577,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 577,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 577,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 577,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 577,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 577,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schema",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 577,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 577,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 577,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 578,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 580,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 580,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "metaData",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 580,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 580,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 580,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 580,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 581,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads the complete meta-data for certain model\n     *\n     *```php\n     * print_r(\n     *     $metaData->readMetaData(\n     *         new Robots()\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 564,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 564,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 563,
                    "last-line": 594,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "readMetaDataIndex",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 595,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 595,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 595,
                            "char": 78
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 597,
                                    "char": 19
                                },
                                {
                                    "variable": "schema",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 597,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 598,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 598,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 600,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 600,
                                            "char": 28
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 600,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 600,
                                    "char": 40
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "schema",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 601,
                                            "char": 28
                                        },
                                        "name": "getSchema",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 601,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 601,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 606,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "get_class_lower",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "model",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 606,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 606,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 606,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "-",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 606,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 606,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "schema",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 606,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 606,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "source",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 606,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 606,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 606,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 608,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 608,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "metaData",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 608,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 608,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 608,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 608,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 608,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 608,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 608,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 608,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 609,
                                            "char": 18
                                        },
                                        "name": "initialize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 609,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 609,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 609,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 609,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 609,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 609,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schema",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 609,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 609,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 609,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 610,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 612,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 612,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "metaData",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 612,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 612,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 612,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 612,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "index",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 612,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 612,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 613,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads meta-data for certain model\n     *\n     *```php\n     * print_r(\n     *     $metaData->readMetaDataIndex(\n     *         new Robots(),\n     *         0\n     *     )\n     * );\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 595,
                    "last-line": 621,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "metaData",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 624,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 624,
                                    "char": 32
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "columnMap",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 625,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 625,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 626,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets internal meta-data in order to regenerate it\n     *\n     *```php\n     * $metaData->reset();\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 623,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 622,
                    "last-line": 639,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAutomaticCreateAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 640,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 640,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 640,
                            "char": 90
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 642,
                                    "char": 14
                                },
                                "name": "writeMetaDataIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 643,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 643,
                                        "char": 18
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 644,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_AUTOMATIC_DEFAULT_INSERT",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 644,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 644,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 644,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 646,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 646,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 646,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 647,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the attributes that must be ignored from the INSERT SQL generation\n     *\n     *```php\n     * $metaData->setAutomaticCreateAttributes(\n     *     new Robots(),\n     *     [\n     *         \"created_at\" => true,\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 641,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 640,
                    "last-line": 660,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAutomaticUpdateAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 661,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 661,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 661,
                            "char": 90
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 663,
                                    "char": 14
                                },
                                "name": "writeMetaDataIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 664,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 664,
                                        "char": 18
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 665,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_AUTOMATIC_DEFAULT_UPDATE",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 665,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 665,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 665,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 667,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 667,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 667,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 668,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the attributes that must be ignored from the UPDATE SQL generation\n     *\n     *```php\n     * $metaData->setAutomaticUpdateAttributes(\n     *     new Robots(),\n     *     [\n     *         \"modified_at\" => true,\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 662,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 661,
                    "last-line": 681,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEmptyStringAttributes",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 682,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 682,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 682,
                            "char": 86
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
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 684,
                                    "char": 14
                                },
                                "name": "writeMetaDataIndex",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 685,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 685,
                                        "char": 18
                                    },
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 686,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_EMPTY_STRING_VALUES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 686,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 686,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 686,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 688,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 688,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 688,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 689,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the attributes that allow empty string values\n     *\n     *```php\n     * $metaData->setEmptyStringAttributes(\n     *     new Robots(),\n     *     [\n     *         \"name\" => true,\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 683,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 682,
                    "last-line": 693,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 694,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 694,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 696,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 696,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 697,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 695,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 694,
                    "last-line": 701,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStrategy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "strategy",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "StrategyInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 702,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 702,
                            "char": 61
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
                                    "property": "strategy",
                                    "expr": {
                                        "type": "variable",
                                        "value": "strategy",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 704,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 704,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 705,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the meta-data extraction strategy\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 703,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 702,
                    "last-line": 709,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "write",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 710,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 710,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 712,
                                    "char": 19
                                },
                                {
                                    "variable": "option",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 712,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 714,
                            "char": 11
                        },
                        {
                            "type": "try-catch",
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "option",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "globals_get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "orm.exception_on_failed_metadata_save",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 715,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 715,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 715,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 715,
                                            "char": 76
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 716,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "adapter",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 716,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 716,
                                                    "char": 40
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 716,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 716,
                                                        "char": 48
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 716,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 716,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 716,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 716,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 718,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 718,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "result",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 718,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 718,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 719,
                                                    "char": 22
                                                },
                                                "name": "throwWriteException",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "option",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 719,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 719,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 719,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 720,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 721,
                                    "char": 9
                                }
                            ],
                            "catches": [
                                {
                                    "classes": [
                                        {
                                            "type": "variable",
                                            "value": "\\Exception",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 721,
                                            "char": 28
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 722,
                                                    "char": 18
                                                },
                                                "name": "throwWriteException",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "option",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 722,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 722,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 722,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 723,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 724,
                                    "char": 5
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 724,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes the metadata to adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 711,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 710,
                    "last-line": 740,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "writeMetaDataIndex",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 741,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 741,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 741,
                            "char": 79
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 741,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 743,
                                    "char": 19
                                },
                                {
                                    "variable": "schema",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 743,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 744,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 744,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 746,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "and",
                                            "left": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 746,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 746,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 746,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 746,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 746,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 746,
                                                    "char": 59
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 746,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 746,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 746,
                                            "char": 69
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 746,
                                                    "char": 84
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 746,
                                                "char": 84
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "boolean",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 746,
                                                "char": 93
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 746,
                                            "char": 93
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 746,
                                        "char": 93
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 746,
                                    "char": 95
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 746,
                                "char": 95
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
                                                    "value": "Invalid data for index",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 747,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 747,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 747,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 748,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 750,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 750,
                                            "char": 28
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 750,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 750,
                                    "char": 40
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "schema",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 751,
                                            "char": 28
                                        },
                                        "name": "getSchema",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 751,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 751,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 756,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "get_class_lower",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "model",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 756,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 756,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 756,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "-",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 756,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 756,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "schema",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 756,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 756,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "source",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 756,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 756,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 756,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 758,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 758,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "metaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 758,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 758,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 758,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 758,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 758,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 758,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 759,
                                            "char": 18
                                        },
                                        "name": "initialize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 759,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 759,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 759,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 759,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 759,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 759,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schema",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 759,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 759,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 759,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 760,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 762,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "metaData",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 762,
                                            "char": 31
                                        },
                                        {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 762,
                                            "char": 38
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 762,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 762,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 763,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes meta-data for certain model using a MODEL_* constant\n     *\n     *```php\n     * print_r(\n     *     $metaData->writeColumnMapIndex(\n     *         new Robots(),\n     *         MetaData::MODELS_REVERSE_COLUMN_MAP,\n     *         [\n     *             \"leName\" => \"name\",\n     *         ]\n     *     )\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 742,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 741,
                    "last-line": 767,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "protected"
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 768,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 768,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 768,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 768,
                            "char": 83
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 768,
                            "char": 95
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "strategy",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 770,
                                    "char": 21
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 770,
                                    "char": 32
                                },
                                {
                                    "variable": "metaData",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 770,
                                    "char": 42
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 770,
                                    "char": 48
                                },
                                {
                                    "variable": "modelMetadata",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 770,
                                    "char": 63
                                },
                                {
                                    "variable": "modelColumnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 770,
                                    "char": 79
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 771,
                                    "char": 22
                                },
                                {
                                    "variable": "keyName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 771,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 772,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "prefixKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 772,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 774,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "strategy",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 774,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 774,
                                    "char": 28
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 775,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 775,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 775,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 775,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 777,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 777,
                                    "char": 18
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 777,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 777,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "metaData",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 778,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "metaData",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 778,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 778,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 778,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 780,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "metaData",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 780,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 780,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 780,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 780,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 780,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "prefixKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "meta-",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 784,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 784,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 784,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 784,
                                                    "char": 44
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "data",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 785,
                                                            "char": 33
                                                        },
                                                        "name": "read",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "prefixKey",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 785,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 785,
                                                                "char": 50
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 785,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 785,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 787,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 787,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 787,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 787,
                                                "char": 34
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-array-index",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "metaData",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 788,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "data",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 788,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 788,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 789,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
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
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 793,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 793,
                                                                "char": 43
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "metaData",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 793,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 793,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 793,
                                                        "char": 55
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "modelMetadata",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "model",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                            "line": 794,
                                                                            "char": 51
                                                                        },
                                                                        "name": "metaData",
                                                                        "call-type": 3,
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                        "line": 794,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 794,
                                                                    "char": 64
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 796,
                                                            "char": 26
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
                                                                            "value": "modelMetadata",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                            "line": 796,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                        "line": 796,
                                                                        "char": 59
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "array",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                        "line": 796,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 796,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 796,
                                                                "char": 67
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
                                                                                        "type": "string",
                                                                                        "value": "Invalid meta-data for model ",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                        "line": 798,
                                                                                        "char": 62
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "className",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                        "line": 799,
                                                                                        "char": 29
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                    "line": 799,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                "line": 799,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                        "line": 799,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 800,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 801,
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
                                                                    "variable": "container",
                                                                    "expr": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                            "line": 805,
                                                                            "char": 46
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "container",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                            "line": 805,
                                                                            "char": 56
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                        "line": 805,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 805,
                                                                    "char": 56
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "strategy",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                            "line": 806,
                                                                            "char": 45
                                                                        },
                                                                        "name": "getStrategy",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                        "line": 806,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 806,
                                                                    "char": 59
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "modelMetadata",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "strategy",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                            "line": 807,
                                                                            "char": 54
                                                                        },
                                                                        "name": "getMetaData",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "model",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                    "line": 808,
                                                                                    "char": 38
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                "line": 808,
                                                                                "char": 38
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "container",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                    "line": 810,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                                "line": 810,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                        "line": 810,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 810,
                                                                    "char": 30
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 811,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 816,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-array-index",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "metaData",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 816,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "modelMetadata",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 816,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 816,
                                                            "char": 60
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 821,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                            "line": 821,
                                                            "char": 26
                                                        },
                                                        "name": "write",
                                                        "call-type": 3,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "prefixKey",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 821,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 821,
                                                                "char": 44
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "modelMetadata",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                    "line": 821,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                                "line": 821,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                        "line": 821,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 822,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 823,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 824,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 829,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "globals_get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "orm.column_renaming",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 829,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 829,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 829,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 829,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 830,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 831,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 833,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "keyName",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 833,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 833,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 833,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 833,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 835,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 835,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "columnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 835,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 835,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "keyName",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 835,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 835,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 835,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 836,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 837,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 843,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefixKey",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "map-",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 843,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "keyName",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 843,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 843,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 843,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 844,
                                            "char": 25
                                        },
                                        "name": "read",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prefixKey",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 844,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 844,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 844,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 844,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 846,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 846,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 846,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 846,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "columnMap",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "keyName",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 847,
                                                    "char": 40
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 847,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 847,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 849,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 849,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 850,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 855,
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
                                        "value": "strategy",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 855,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 855,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 855,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 855,
                                "char": 38
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 856,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 856,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 856,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 856,
                                            "char": 44
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "strategy",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 857,
                                                    "char": 33
                                                },
                                                "name": "getStrategy",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 857,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 857,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 858,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 864,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "modelColumnMap",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "strategy",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 864,
                                            "char": 39
                                        },
                                        "name": "getColumnMaps",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 864,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 864,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 864,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 864,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 864,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 864,
                                    "char": 71
                                },
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "columnMap",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "keyName",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 865,
                                            "char": 36
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "modelColumnMap",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 865,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 865,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 870,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 870,
                                    "char": 14
                                },
                                "name": "write",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "prefixKey",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 870,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 870,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "modelColumnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                            "line": 870,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 870,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 870,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 871,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Initialize the metadata for certain table\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 768,
                    "last-line": 875,
                    "char": 28
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "throwWriteException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 876,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 878,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 880,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "message",
                                    "expr": {
                                        "type": "string",
                                        "value": "Failed to store metaData to the cache adapter",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 880,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 880,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 882,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "option",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                "line": 882,
                                "char": 19
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
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 883,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 883,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 883,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 884,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "trigger_error",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                    "line": 885,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                                "line": 885,
                                                "char": 34
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                        "line": 885,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                                    "line": 886,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                            "line": 887,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Throws an exception when the metadata cannot be written\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 877,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 876,
                    "last-line": 888,
                    "char": 20
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "MODELS_ATTRIBUTES",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 43,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 44,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_AUTOMATIC_DEFAULT_INSERT",
                    "default": {
                        "type": "int",
                        "value": "10",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 44,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 45,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_AUTOMATIC_DEFAULT_UPDATE",
                    "default": {
                        "type": "int",
                        "value": "11",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 45,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 46,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_COLUMN_MAP",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 46,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 47,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_DATE_AT",
                    "default": {
                        "type": "int",
                        "value": "6",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 47,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 48,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_DATE_IN",
                    "default": {
                        "type": "int",
                        "value": "7",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 48,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 49,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_DATA_TYPES",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 49,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 50,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_DATA_TYPES_BIND",
                    "default": {
                        "type": "int",
                        "value": "9",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 50,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 51,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_DATA_TYPES_NUMERIC",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 51,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 52,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_DEFAULT_VALUES",
                    "default": {
                        "type": "int",
                        "value": "12",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 52,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 53,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_EMPTY_STRING_VALUES",
                    "default": {
                        "type": "int",
                        "value": "13",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 53,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 54,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_IDENTITY_COLUMN",
                    "default": {
                        "type": "int",
                        "value": "8",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 54,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 55,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_NON_PRIMARY_KEY",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 55,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 56,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_NOT_NULL",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 56,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 57,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_PRIMARY_KEY",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 57,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 58,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "MODELS_REVERSE_COLUMN_MAP",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                        "line": 58,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
                    "line": 62,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
            "line": 41,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData.zep",
        "line": 41,
        "char": 14
    }
]