[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Config\/Config.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Config",
        "file": "\/app\/phalcon\/Config\/Config.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Config\/Config.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Config\/Config.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Exception",
                "file": "\/app\/phalcon\/Config\/Config.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Config\/Config.zep",
        "line": 40,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * `Phalcon\\Config` is designed to simplify the access to, and the use of,\n * configuration data within applications. It provides a nested object property\n * based user interface for accessing this configuration data within application\n * code.\n *\n *```php\n * $config = new \\Phalcon\\Config(\n *     [\n *         \"database\" => [\n *             \"adapter\"  => \"Mysql\",\n *             \"host\"     => \"localhost\",\n *             \"username\" => \"scott\",\n *             \"password\" => \"cheetah\",\n *             \"dbname\"   => \"test_db\",\n *         ],\n *         \"phalcon\" => [\n *             \"controllersDir\" => \"..\/app\/controllers\/\",\n *             \"modelsDir\"      => \"..\/app\/models\/\",\n *             \"viewsDir\"       => \"..\/app\/views\/\",\n *         ],\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Config\/Config.zep",
        "line": 41,
        "char": 5
    },
    {
        "type": "class",
        "name": "Config",
        "abstract": 0,
        "final": 0,
        "extends": "Collection",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "pathDelimiter",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 48,
                        "char": 35
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 54,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPathDelimiter",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 57,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "pathDelimiter",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 57,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 57,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 57,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 57,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "pathDelimiter",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 58,
                                                    "char": 67
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "DEFAULT_PATH_DELIMITER",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 58,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 58,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 58,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 59,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 61,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 61,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "pathDelimiter",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 61,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 61,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 62,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the default path delimiter\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 56,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 56,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 55,
                    "last-line": 78,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "merge",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "toMerge",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 79,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "config",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 81,
                                    "char": 19
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 81,
                                    "char": 27
                                },
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 81,
                                    "char": 35
                                },
                                {
                                    "variable": "target",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 81,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 83,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "toMerge",
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 83,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 83,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 83,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 83,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "config",
                                            "expr": {
                                                "type": "new",
                                                "class": "Config",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "toMerge",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 84,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 84,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 84,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 84,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 85,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "toMerge",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 85,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 85,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 85,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 85,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "toMerge",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 85,
                                                "char": 64
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "Config",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 85,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 85,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 85,
                                        "char": 73
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "config",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "toMerge",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 86,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 86,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 87,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 87,
                                    "char": 14
                                }
                            ],
                            "else_statements": [
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
                                                    "value": "Invalid data type for merge.",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 88,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 88,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 88,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 89,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 91,
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
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 91,
                                            "char": 27
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 91,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 91,
                                    "char": 37
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "target",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 92,
                                            "char": 29
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 92,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 92,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 93,
                                            "char": 27
                                        },
                                        "name": "internalMerge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 93,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 93,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "target",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 93,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 93,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 93,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 93,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 95,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 95,
                                    "char": 14
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 95,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 96,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 96,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "result",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 96,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 96,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 96,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 98,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Merges a configuration into the current one\n     *\n     *```php\n     * $appConfig = new \\Phalcon\\Config(\n     *     [\n     *         \"database\" => [\n     *             \"host\" => \"localhost\",\n     *         ],\n     *     ]\n     * );\n     *\n     * $globalConfig->merge($appConfig);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Config",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 80,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 80,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 80,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 79,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "path",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 108,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 108,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 108,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 108,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 108,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "config",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 110,
                                    "char": 19
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 110,
                                    "char": 24
                                },
                                {
                                    "variable": "keys",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 110,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 112,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 112,
                                    "char": 17
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 112,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 112,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 112,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 113,
                                            "char": 25
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 113,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 113,
                                                "char": 34
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 113,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 116,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "list",
                                        "left": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 116,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 116,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 116,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 116,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "delimiter",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 117,
                                                    "char": 34
                                                },
                                                "name": "getPathDelimiter",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 117,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 117,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 118,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 120,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "config",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 120,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 120,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 120,
                                    "char": 32
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "keys",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "delimiter",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 121,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 121,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 121,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 121,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 121,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 121,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 123,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "empty",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "variable",
                                                "value": "keys",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 123,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 123,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 123,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 123,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 123,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "key",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_shift",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "keys",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 124,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 124,
                                                        "char": 39
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 124,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 124,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 126,
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
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 126,
                                                "char": 24
                                            },
                                            "name": "has",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 126,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 126,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 126,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 126,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 128,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 130,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "variable",
                                                "value": "keys",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 130,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 130,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 130,
                                        "char": 28
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 131,
                                                    "char": 31
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 131,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 131,
                                                        "char": 39
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 131,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 132,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 134,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "config",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 134,
                                                    "char": 33
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 134,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 134,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 134,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 134,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 135,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "variable",
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 135,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 135,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 135,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 137,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 138,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 140,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "defaultValue",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 140,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 141,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a value from current config using a dot separated path.\n     *\n     *```php\n     * echo $config->path(\"unknown.path\", \"default\", \".\");\n     *```\n     *",
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 108,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPathDelimiter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 146,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 146,
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
                                    "property": "pathDelimiter",
                                    "expr": {
                                        "type": "variable",
                                        "value": "delimiter",
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 148,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 148,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 150,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 150,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 151,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default path delimiter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Config",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 147,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 147,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 147,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 146,
                    "last-line": 161,
                    "char": 19
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
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 164,
                                    "char": 17
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 164,
                                    "char": 22
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 164,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 165,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "results",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 165,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 167,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "results",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 167,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 167,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "parent",
                                        "dynamic": 0,
                                        "name": "toArray",
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 168,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 168,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 170,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 170,
                                "char": 32
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 171,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 171,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 171,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 171,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "method_exists",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 171,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 171,
                                                    "char": 62
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "toArray",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 171,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 171,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 171,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 171,
                                        "char": 73
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
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 172,
                                                            "char": 35
                                                        },
                                                        "name": "toArray",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 172,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 172,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 173,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 175,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "results",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 175,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 175,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 175,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 176,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 178,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "results",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 178,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 179,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Converts recursively the object to an array\n     *\n     *```php\n     * print_r(\n     *     $config->toArray()\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 163,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 162,
                    "last-line": 183,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "internalMerge",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "source",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 184,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "target",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 184,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 186,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 186,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 188,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "target",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 188,
                                "char": 34
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "and",
                                            "left": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 189,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 189,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 189,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 189,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "source",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 189,
                                                        "char": 54
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 189,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 189,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 189,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 189,
                                            "char": 62
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "source",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 189,
                                                        "char": 77
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 189,
                                                        "char": 81
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 189,
                                                    "char": 85
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 189,
                                                "char": 85
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 189,
                                                "char": 93
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 189,
                                            "char": 93
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 189,
                                        "char": 93
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "source",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 190,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 190,
                                                            "char": 40
                                                        },
                                                        "name": "internalMerge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "source",
                                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                                        "line": 190,
                                                                        "char": 61
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "key",
                                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                                        "line": 190,
                                                                        "char": 65
                                                                    },
                                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                                    "line": 190,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                                "line": 190,
                                                                "char": 66
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                                    "line": 190,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                                "line": 190,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 190,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 190,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 191,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 191,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 191,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "int",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 191,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 191,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "source",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                                "line": 192,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 192,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 193,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 193,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "source",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 194,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 194,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 194,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 195,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 196,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 198,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "source",
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 198,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 199,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Performs a merge recursively\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 185,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 185,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 184,
                    "last-line": 203,
                    "char": 28
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "setData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 204,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 204,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 206,
                                    "char": 17
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 206,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 208,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "element",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 208,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 208,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 208,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 209,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "insensitive",
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 209,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 209,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 209,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "mb_strtolower",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "element",
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 209,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                                    "line": 209,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 209,
                                            "char": 68
                                        },
                                        "extra": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 209,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 209,
                                        "char": 77
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 209,
                                    "char": 77
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 211,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "lowerKeys",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 211,
                                            "char": 32
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "element",
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 211,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 211,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 213,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 213,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 213,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 213,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                "line": 213,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "new",
                                                "class": "Config",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                                            "line": 214,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                                        "line": 214,
                                                        "char": 40
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 214,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 214,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 215,
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
                                            "variable": "data",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Config\/Config.zep",
                                                "line": 216,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 216,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 217,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 219,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Config\/Config.zep",
                                            "line": 219,
                                            "char": 31
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Config\/Config.zep",
                                        "line": 219,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Config\/Config.zep",
                                    "line": 219,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Config.zep",
                            "line": 220,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the collection data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 205,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 204,
                    "last-line": 221,
                    "char": 22
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "DEFAULT_PATH_DELIMITER",
                    "default": {
                        "type": "string",
                        "value": ".",
                        "file": "\/app\/phalcon\/Config\/Config.zep",
                        "line": 43,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Config\/Config.zep",
                    "line": 47,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Config\/Config.zep",
            "line": 41,
            "char": 5
        },
        "file": "\/app\/phalcon\/Config\/Config.zep",
        "line": 41,
        "char": 5
    }
]