[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Config\\Adapter",
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Exception",
                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\Exception",
                "alias": "FactoryException",
                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                "line": 15,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\ConfigFactory",
                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 68,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Reads multiple files (or arrays) and merges them all together.\n *\n * See `Phalcon\\Config\\Factory::load` To load Config Adapter class using 'adapter' option.\n *\n * ```php\n * use Phalcon\\Config\\Adapter\\Grouped;\n *\n * $config = new Grouped(\n *     [\n *         \"path\/to\/config.php\",\n *         \"path\/to\/config.dist.php\",\n *     ]\n * );\n * ```\n *\n * ```php\n * use Phalcon\\Config\\Adapter\\Grouped;\n *\n * $config = new Grouped(\n *     [\n *         \"path\/to\/config.json\",\n *         \"path\/to\/config.dist.json\",\n *     ],\n *     \"json\"\n * );\n * ```\n *\n * ```php\n * use Phalcon\\Config\\Adapter\\Grouped;\n *\n * $config = new Grouped(\n *     [\n *         [\n *             \"filePath\" => \"path\/to\/config.php\",\n *             \"adapter\"  => \"php\",\n *         ],\n *         [\n *             \"filePath\" => \"path\/to\/config.json\",\n *             \"adapter\"  => \"json\",\n *         ],\n *         [\n *             \"adapter\"  => \"array\",\n *             \"config\"   => [\n *                 \"property\" => \"value\",\n *             ],\n *         ],\n *     ],\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 69,
        "char": 5
    },
    {
        "type": "class",
        "name": "Grouped",
        "abstract": 0,
        "final": 0,
        "extends": "Config",
        "definition": {
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
                            "name": "arrayConfig",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                            "line": 74,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "defaultAdapter",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "php",
                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                "line": 74,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                            "line": 74,
                            "char": 81
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "configArray",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                    "line": 76,
                                    "char": 24
                                },
                                {
                                    "variable": "configInstance",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                    "line": 76,
                                    "char": 40
                                },
                                {
                                    "variable": "configName",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                    "line": 76,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                            "line": 78,
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
                                            "type": "empty-array",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 78,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                        "line": 78,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                "line": 78,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                            "line": 80,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "arrayConfig",
                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                "line": 80,
                                "char": 39
                            },
                            "value": "configName",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "configInstance",
                                            "expr": {
                                                "type": "variable",
                                                "value": "configName",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 81,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 81,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                    "line": 84,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "configName",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 84,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 84,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 84,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                        "line": 84,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 85,
                                                    "char": 23
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultAdapter",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 85,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 85,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 86,
                                                            "char": 26
                                                        },
                                                        "name": "merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "list",
                                                                        "left": {
                                                                            "type": "new",
                                                                            "class": "ConfigFactory",
                                                                            "dynamic": 0,
                                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                            "line": 87,
                                                                            "char": 45
                                                                        },
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                        "line": 87,
                                                                        "char": 47
                                                                    },
                                                                    "name": "load",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "configName",
                                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                                "line": 87,
                                                                                "char": 63
                                                                            },
                                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                            "line": 87,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 88,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 88,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 88,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 90,
                                                    "char": 28
                                                },
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 91,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 93,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "configInstance",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "filePath",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 94,
                                                                    "char": 30
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "configName",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 94,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 94,
                                                                "char": 42
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "adapter",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 95,
                                                                    "char": 30
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "defaultAdapter",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 96,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 96,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 96,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 96,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 97,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
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
                                                            "value": "configInstance",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 97,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "adapter",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 97,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 97,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 97,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 97,
                                                "char": 53
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "configInstance",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "adapter",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 98,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "defaultAdapter",
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 98,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 98,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 99,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 101,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                    "line": 101,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 101,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "configInstance",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 101,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "adapter",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 101,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 101,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                        "line": 101,
                                        "char": 50
                                    },
                                    "statements": [
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
                                                            "value": "configInstance",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 102,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "config",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 102,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 102,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 102,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 102,
                                                "char": 50
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
                                                                        "value": "To use 'array' adapter you have to specify ",
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                        "line": 104,
                                                                        "char": 69
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "the 'config' as an array.",
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                        "line": 106,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 106,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 106,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 106,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 107,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 109,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "configArray",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "configInstance",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 109,
                                                            "char": 52
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "config",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 109,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 109,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 109,
                                                    "char": 60
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "configInstance",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "Config",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "configArray",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 110,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 110,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 110,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 110,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 111,
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
                                                    "variable": "configInstance",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "list",
                                                            "left": {
                                                                "type": "new",
                                                                "class": "ConfigFactory",
                                                                "dynamic": 0,
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 112,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                            "line": 112,
                                                            "char": 60
                                                        },
                                                        "name": "load",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "configInstance",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                    "line": 112,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                                "line": 112,
                                                                "char": 80
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                        "line": 112,
                                                        "char": 81
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 112,
                                                    "char": 81
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 113,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                    "line": 115,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                            "line": 115,
                                            "char": 18
                                        },
                                        "name": "merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "configInstance",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                    "line": 115,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                                "line": 115,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                        "line": 115,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                                    "line": 116,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                            "line": 117,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Config\\Adapter\\Grouped constructor\n     *",
                    "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
                    "line": 74,
                    "last-line": 118,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
            "line": 69,
            "char": 5
        },
        "file": "\/app\/phalcon\/Config\/Adapter\/Grouped.zep",
        "line": 69,
        "char": 5
    }
]