[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Config",
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Adapter\\Grouped",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 13,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Adapter\\Ini",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Adapter\\Json",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 15,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Adapter\\Php",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 16,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Adapter\\Yaml",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Exception",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 18,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 19,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\Exception",
                "alias": "FactoryException",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 20,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                "line": 21,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 37,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Loads Config Adapter class using 'adapter' option, if no extension is\n * provided it will be added to filePath\n *\n *```php\n * use Phalcon\\Config\\ConfigFactory;\n *\n * $options = [\n *     \"filePath\" => \"path\/config\",\n *     \"adapter\"  => \"php\",\n * ];\n *\n * $config = (new ConfigFactory())->load($options);\n *```\n *",
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 38,
        "char": 5
    },
    {
        "type": "class",
        "name": "ConfigFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
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
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 43,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 43,
                            "char": 52
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
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 45,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 45,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 45,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 45,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 46,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * ConfigFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                    "line": 43,
                    "last-line": 50,
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
                            "name": "config",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 51,
                            "char": 32
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "adapter",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 53,
                                    "char": 20
                                },
                                {
                                    "variable": "extension",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 53,
                                    "char": 31
                                },
                                {
                                    "variable": "first",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 53,
                                    "char": 38
                                },
                                {
                                    "variable": "oldConfig",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 53,
                                    "char": 49
                                },
                                {
                                    "variable": "second",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 53,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 55,
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
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 55,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 55,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 55,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 55,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "oldConfig",
                                            "expr": {
                                                "type": "variable",
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 56,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 56,
                                            "char": 35
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "extension",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "pathinfo",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "config",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 57,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 57,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "PATHINFO_EXTENSION",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 57,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 57,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 57,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 57,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 59,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "list",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "extension",
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 59,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 59,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 59,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 59,
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
                                                            "value": "You need to provide the extension in the file path",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 62,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 62,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 62,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 63,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 65,
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
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "adapter",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 66,
                                                            "char": 26
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "extension",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 66,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 66,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "filePath",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 67,
                                                            "char": 26
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "oldConfig",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 68,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 68,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 68,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 68,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 69,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 71,
                            "char": 10
                        },
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
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 71,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 71,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 71,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 71,
                                    "char": 38
                                },
                                "right": {
                                    "type": "instanceof",
                                    "left": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 71,
                                        "char": 56
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "Config",
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 71,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 71,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 71,
                                "char": 65
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
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 72,
                                                    "char": 33
                                                },
                                                "name": "toArray",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 72,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 72,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 75,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 75,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 75,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 75,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 75,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 75,
                                "char": 45
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
                                                    "value": "Config must be array or Phalcon\\\\Config\\\\Config object",
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 78,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 78,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 78,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 79,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
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
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 81,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "filePath",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 81,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 81,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 81,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 81,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 81,
                                "char": 45
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
                                                    "value": "You must provide 'filePath' option in factory config parameter.",
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 84,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 84,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 84,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 85,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 87,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 87,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "adapter",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 87,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 87,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 87,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 87,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 87,
                                "char": 44
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
                                                    "value": "You must provide 'adapter' option in factory config parameter.",
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 90,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 90,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 90,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 91,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 93,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "adapter",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "config",
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 93,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "adapter",
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 93,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 93,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 93,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 93,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 93,
                                    "char": 50
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "first",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 94,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "filePath",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 94,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 94,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 94,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "second",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 95,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 95,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 97,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "strpos",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "first",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 97,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 97,
                                            "char": 25
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": ".",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 97,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 97,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 97,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 97,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "first",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "first",
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 98,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": ".",
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 98,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 98,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "lcfirst",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "adapter",
                                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                "line": 98,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 98,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 98,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 98,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 98,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 99,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 101,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "string",
                                    "value": "ini",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 101,
                                    "char": 18
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 101,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 101,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "second",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Arr",
                                                "dynamic": 0,
                                                "name": "get",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "config",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 102,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 102,
                                                        "char": 41
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "mode",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 102,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 102,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 102,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 102,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 102,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 102,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 103,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "string",
                                            "value": "yaml",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 103,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "adapter",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 103,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 103,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "second",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Arr",
                                                        "dynamic": 0,
                                                        "name": "get",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "config",
                                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                    "line": 104,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                "line": 104,
                                                                "char": 41
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "callbacks",
                                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                    "line": 104,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                "line": 104,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "empty-array",
                                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                    "line": 104,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                "line": 104,
                                                                "char": 56
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 104,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 104,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 105,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 107,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 107,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 107,
                                    "char": 21
                                },
                                "name": "newInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "adapter",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 107,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 107,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "first",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 107,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 107,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "second",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 107,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 107,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 107,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 108,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Load a config to create a new instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 52,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                        "line": 52,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                    "line": 51,
                    "last-line": 112,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 113,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "fileName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 113,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 113,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 113,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 115,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 117,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 117,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 117,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 117,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 117,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 119,
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
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 119,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 119,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 119,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 119,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 119,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 119,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 119,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 120,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 120,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 120,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 120,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 120,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 120,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 122,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "json",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 122,
                                                "char": 23
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 122,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 122,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "php",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 122,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                "line": 122,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 122,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 122,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "services",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 123,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "definition",
                                                        "dynamic": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "fileName",
                                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                    "line": 123,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                "line": 123,
                                                                "char": 69
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 123,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 123,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 124,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "services",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                            "line": 125,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "definition",
                                                        "dynamic": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "fileName",
                                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                    "line": 125,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                "line": 125,
                                                                "char": 69
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "params",
                                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                    "line": 125,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                                "line": 125,
                                                                "char": 77
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                        "line": 125,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                                    "line": 125,
                                                    "char": 78
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 126,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 127,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 129,
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
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 129,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 129,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 129,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                    "line": 129,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 129,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 130,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a new Config instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 114,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                        "line": 114,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                    "line": 113,
                    "last-line": 134,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "grouped",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 138,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Config\\\\Adapter\\\\Grouped",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 138,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 138,
                                        "char": 58
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "ini",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 139,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Config\\\\Adapter\\\\Ini",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 139,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 139,
                                        "char": 54
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "json",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 140,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Config\\\\Adapter\\\\Json",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 140,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 140,
                                        "char": 55
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "php",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 141,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Config\\\\Adapter\\\\Php",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 141,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 141,
                                        "char": 54
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "yaml",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 142,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Config\\\\Adapter\\\\Yaml",
                                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                            "line": 143,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                        "line": 143,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 143,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                            "line": 144,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the adapters for the factory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                                "line": 136,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                        "line": 136,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
                    "line": 135,
                    "last-line": 145,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
            "line": 38,
            "char": 5
        },
        "file": "\/app\/phalcon\/Config\/ConfigFactory.zep",
        "line": 38,
        "char": 5
    }
]