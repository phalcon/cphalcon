[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Config\\Adapter",
        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Exception",
                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
        "line": 52,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Reads YAML files and converts them to Phalcon\\Config objects.\n *\n * Given the following configuration file:\n *\n *```yaml\n * phalcon:\n *   baseuri:        \/phalcon\/\n *   controllersDir: !approot  \/app\/controllers\/\n * models:\n *   metadata: memory\n *```\n *\n * You can read it as follows:\n *\n *```php\n * define(\n *     \"APPROOT\",\n *     dirname(__DIR__)\n * );\n *\n * use Phalcon\\Config\\Adapter\\Yaml;\n *\n * $config = new Yaml(\n *     \"path\/config.yaml\",\n *     [\n *         \"!approot\" => function($value) {\n *             return APPROOT . $value;\n *         },\n *     ]\n * );\n *\n * echo $config->phalcon->controllersDir;\n * echo $config->phalcon->baseuri;\n * echo $config->models->metadata;\n *```\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
        "line": 53,
        "char": 5
    },
    {
        "type": "class",
        "name": "Yaml",
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
                            "name": "filePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 58,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "callbacks",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                "line": 58,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 58,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "yamlConfig",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 60,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 61,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "ndocs",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 61,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 61,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 63,
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
                                        "name": "extension_loaded",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "yaml",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                    "line": 63,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                "line": 63,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 63,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 63,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                "line": 63,
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
                                                    "value": "Yaml extension not loaded",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                    "line": 64,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                "line": 64,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 64,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 65,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 67,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "variable",
                                        "value": "callbacks",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 67,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 67,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                "line": 67,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "yamlConfig",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "yaml_parse_file",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filePath",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                            "line": 68,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                        "line": 68,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                "line": 68,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                            "line": 68,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 69,
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
                                            "variable": "yamlConfig",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "yaml_parse_file",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filePath",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                            "line": 70,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                        "line": 70,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                            "line": 70,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                        "line": 70,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ndocs",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                            "line": 70,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                        "line": 70,
                                                        "char": 64
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "callbacks",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                            "line": 70,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                        "line": 70,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                "line": 70,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                            "line": 70,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 71,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 73,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "yamlConfig",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 73,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 73,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 73,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                "line": 73,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Configuration file ",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                            "line": 75,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "basename",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "filePath",
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                                        "line": 75,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                                    "line": 75,
                                                                    "char": 56
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                            "line": 75,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                        "line": 75,
                                                        "char": 58
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " can't be loaded",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                        "line": 76,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                    "line": 76,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                                "line": 76,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 76,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                    "line": 77,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 79,
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
                                            "value": "yamlConfig",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                            "line": 79,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                        "line": 79,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                                "line": 79,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                            "line": 80,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Config\\Adapter\\Yaml constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
                    "line": 58,
                    "last-line": 81,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
            "line": 53,
            "char": 5
        },
        "file": "\/app\/phalcon\/Config\/Adapter\/Yaml.zep",
        "line": 53,
        "char": 5
    }
]