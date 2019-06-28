[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Config\\Adapter",
        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Exception",
                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
        "line": 57,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Reads ini files and converts them to Phalcon\\Config objects.\n *\n * Given the next configuration file:\n *\n *```ini\n * [database]\n * adapter = Mysql\n * host = localhost\n * username = scott\n * password = cheetah\n * dbname = test_db\n *\n * [phalcon]\n * controllersDir = \"..\/app\/controllers\/\"\n * modelsDir = \"..\/app\/models\/\"\n * viewsDir = \"..\/app\/views\/\"\n * ```\n *\n * You can read it as follows:\n *\n *```php\n * use Phalcon\\Config\\Adapter\\Ini;\n *\n * $config = new Ini(\"path\/config.ini\");\n *\n * echo $config->phalcon->controllersDir;\n * echo $config->database->username;\n *```\n *\n * PHP constants may also be parsed in the ini file, so if you define a constant\n * as an ini value before calling the constructor, the constant's value will be\n * integrated into the results. To use it this way you must specify the optional\n * second parameter as `INI_SCANNER_NORMAL` when calling the constructor:\n *\n * ```php\n * $config = new \\Phalcon\\Config\\Adapter\\Ini(\n *     \"path\/config-with-constants.ini\",\n *     INI_SCANNER_NORMAL\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
        "line": 58,
        "char": 5
    },
    {
        "type": "class",
        "name": "Ini",
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
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 63,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "mode",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 63,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 63,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "directives",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 65,
                                    "char": 23
                                },
                                {
                                    "variable": "iniConfig",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 65,
                                    "char": 34
                                },
                                {
                                    "variable": "lastValue",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 65,
                                    "char": 45
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 65,
                                    "char": 51
                                },
                                {
                                    "variable": "section",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 65,
                                    "char": 60
                                },
                                {
                                    "variable": "sections",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 65,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 66,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "config",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 66,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 69,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 69,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "mode",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 69,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 69,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 69,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "mode",
                                            "expr": {
                                                "type": "constant",
                                                "value": "INI_SCANNER_RAW",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 70,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 70,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 71,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 73,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "iniConfig",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "parse_ini_file",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filePath",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 73,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 73,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 73,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 73,
                                                "char": 54
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "mode",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 73,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 73,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 73,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 73,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 75,
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
                                        "value": "iniConfig",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 75,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 75,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 75,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 75,
                                "char": 41
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
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 77,
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
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                        "line": 77,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                    "line": 77,
                                                                    "char": 56
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 77,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 77,
                                                        "char": 58
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " cannot be loaded",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 78,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 78,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 78,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 78,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 79,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 81,
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
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 81,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 81,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 83,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "iniConfig",
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 83,
                                "char": 46
                            },
                            "key": "section",
                            "value": "directives",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "directives",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 84,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 84,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 84,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 84,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "sections",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 85,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 85,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 87,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "directives",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 87,
                                                "char": 51
                                            },
                                            "key": "path",
                                            "value": "lastValue",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "sections",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                    "line": 88,
                                                                    "char": 43
                                                                },
                                                                "name": "parseIniString",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "cast",
                                                                            "left": "string",
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "path",
                                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                                "line": 89,
                                                                                "char": 38
                                                                            },
                                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                            "line": 89,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                        "line": 89,
                                                                        "char": 38
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "lastValue",
                                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                            "line": 91,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                        "line": 91,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                "line": 91,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 91,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 92,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 94,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "count",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sections",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 94,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 94,
                                                        "char": 34
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 94,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "config",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "section",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                    "line": 95,
                                                                    "char": 39
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "call_user_func_array",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "array_replace_recursive",
                                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                            "line": 96,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                        "line": 96,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "sections",
                                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                            "line": 98,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                        "line": 98,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                "line": 98,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 98,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 99,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 100,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "config",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "section",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 101,
                                                            "char": 35
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 101,
                                                            "char": 44
                                                        },
                                                        "name": "cast",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "directives",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                    "line": 101,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                "line": 101,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 101,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 101,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 102,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 103,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 105,
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
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 105,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 105,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 105,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 106,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Ini constructor.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                    "line": 63,
                    "last-line": 111,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "cast",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "ini",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 112,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 114,
                                    "char": 16
                                },
                                {
                                    "variable": "lowerIni",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 114,
                                    "char": 26
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 114,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 116,
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
                                        "value": "ini",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 116,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 116,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 116,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 116,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "ini",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 117,
                                        "char": 35
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "ini",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 118,
                                                            "char": 28
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                            "line": 118,
                                                            "char": 37
                                                        },
                                                        "name": "cast",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                    "line": 118,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                                "line": 118,
                                                                "char": 48
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 118,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 118,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 119,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 121,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "ini",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 121,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 122,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 125,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ini",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "ini",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 125,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 125,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 125,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "lowerIni",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ini",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 126,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 126,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 126,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 126,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 128,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "variable",
                                    "value": "lowerIni",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 128,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 128,
                                "char": 27
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 129,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 130,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "yes",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 130,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 131,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "on",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 131,
                                        "char": 20
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 132,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 133,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 133,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 133,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 134,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "no",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 134,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 135,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "off",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 135,
                                        "char": 21
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 136,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 137,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 137,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "null",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 137,
                                        "char": 22
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 138,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 139,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 139,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 142,
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
                                            "value": "ini",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 142,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 142,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 142,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 142,
                                    "char": 35
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "is_numeric",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "ini",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 142,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 142,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 142,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 142,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_match",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/[.]+\/",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 143,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 143,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ini",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 143,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 143,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 143,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "cast",
                                                "left": "double",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "ini",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 144,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 144,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 145,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "ini",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 146,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 146,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 147,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 148,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 150,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "ini",
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 150,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 151,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * We have to cast values manually because parse_ini_file() has a poor\n     * implementation.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 112,
                                "char": 46
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 112,
                                "char": 53
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "double",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 112,
                                "char": 62
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 112,
                                "char": 68
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 113,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                        "line": 113,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                    "line": 112,
                    "last-line": 155,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "parseIniString",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 156,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 156,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 158,
                                    "char": 16
                                },
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 158,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 160,
                            "char": 11
                        },
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
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 160,
                                            "char": 29
                                        },
                                        "name": "cast",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 160,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 160,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 160,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 160,
                                    "char": 41
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "position",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strpos",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 161,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 161,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ".",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 161,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 161,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 161,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 161,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 163,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 163,
                                    "char": 20
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "position",
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 163,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 163,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 165,
                                                    "char": 22
                                                },
                                                "value": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 166,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 166,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 166,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 167,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 169,
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
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 169,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 169,
                                                "char": 31
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 169,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 169,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "position",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 169,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 169,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 169,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 169,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "path",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 170,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 170,
                                                "char": 31
                                            },
                                            {
                                                "parameter": {
                                                    "type": "add",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "position",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 170,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 170,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 170,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 170,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 170,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                    "line": 170,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 172,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 173,
                                            "char": 17
                                        },
                                        "value": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                "line": 173,
                                                "char": 24
                                            },
                                            "name": "parseIniString",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "path",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 173,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 173,
                                                    "char": 44
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                        "line": 173,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                                    "line": 173,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                            "line": 174,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                        "line": 174,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 174,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                            "line": 175,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Build multidimensional array from string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                                "line": 157,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                        "line": 157,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
                    "line": 156,
                    "last-line": 176,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
            "line": 58,
            "char": 5
        },
        "file": "\/app\/phalcon\/Config\/Adapter\/Ini.zep",
        "line": 58,
        "char": 5
    }
]