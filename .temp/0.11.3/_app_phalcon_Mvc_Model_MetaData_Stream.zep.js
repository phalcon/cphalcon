[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
        "line": 28,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\MetaData\\Stream\n *\n * Stores model meta-data in PHP files.\n *\n *```php\n * $metaData = new \\Phalcon\\Mvc\\Model\\MetaData\\Files(\n *     [\n *         \"metaDataDir\" => \"app\/cache\/metadata\/\",\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
        "line": 29,
        "char": 5
    },
    {
        "type": "class",
        "name": "Stream",
        "abstract": 0,
        "final": 0,
        "extends": "MetaData",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "metaDataDir",
                    "default": {
                        "type": "string",
                        "value": ".\/",
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                        "line": 31,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                    "line": 37,
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
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                "line": 38,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 38,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "metaDataDir",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 40,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 42,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "metaDataDir",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 42,
                                    "char": 52
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                        "line": 42,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "metaDataDir",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                        "line": 42,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 42,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                "line": 42,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "metaDataDir",
                                            "expr": {
                                                "type": "variable",
                                                "value": "metaDataDir",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 43,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 43,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 44,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 45,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\MetaData\\Files constructor\n     *\n     * @param array options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                        "line": 39,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                    "line": 38,
                    "last-line": 49,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 50,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 52,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 54,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "path",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 54,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "metaDataDir",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 54,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 54,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "prepare_virtual_path",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 54,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 54,
                                                        "char": 64
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "_",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 54,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 54,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 54,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 54,
                                            "char": 69
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ".php",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 54,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                        "line": 54,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 54,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 56,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "file_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 56,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 56,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 56,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                "line": 56,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                        "line": 57,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 58,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 60,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "require",
                                "left": {
                                    "type": "variable",
                                    "value": "path",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 60,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                "line": 60,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads meta-data from files\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                "line": 50,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                "line": 51,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                        "line": 51,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                    "line": 50,
                    "last-line": 65,
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 66,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 66,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "option",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 68,
                                    "char": 19
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 68,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 70,
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
                                            "variable": "path",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 71,
                                                            "char": 31
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "metaDataDir",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 71,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 71,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "prepare_virtual_path",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                    "line": 71,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                "line": 71,
                                                                "char": 70
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "_",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                    "line": 71,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                "line": 71,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 71,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 71,
                                                    "char": 75
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ".php",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 71,
                                                    "char": 81
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 71,
                                                "char": 81
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 71,
                                            "char": 81
                                        },
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
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 72,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 72,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 72,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 72,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 74,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 74,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "file_put_contents",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "path",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 74,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 74,
                                                    "char": 48
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "<?php return ",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                "line": 74,
                                                                "char": 64
                                                            },
                                                            "right": {
                                                                "type": "fcall",
                                                                "name": "var_export",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "data",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                            "line": 74,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                        "line": 74,
                                                                        "char": 81
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "bool",
                                                                            "value": "true",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                            "line": 74,
                                                                            "char": 87
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                        "line": 74,
                                                                        "char": 87
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                                "line": 74,
                                                                "char": 89
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 74,
                                                            "char": 89
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "; ",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 74,
                                                            "char": 93
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 74,
                                                        "char": 93
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 74,
                                                    "char": 93
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 74,
                                            "char": 95
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                        "line": 74,
                                        "char": 95
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 75,
                                                    "char": 22
                                                },
                                                "name": "throwWriteException",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "option",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 75,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 75,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 75,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 76,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 77,
                                    "char": 9
                                }
                            ],
                            "catches": [
                                {
                                    "classes": [
                                        {
                                            "type": "variable",
                                            "value": "\\Exception",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 77,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 78,
                                                    "char": 18
                                                },
                                                "name": "throwWriteException",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "option",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                            "line": 78,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                        "line": 78,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 78,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                            "line": 79,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 80,
                                    "char": 5
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 80,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes the meta-data to files\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                    "line": 66,
                    "last-line": 84,
                    "char": 19
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 85,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "option",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                "line": 87,
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
                                                    "type": "string",
                                                    "value": "Meta-Data directory cannot be written",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 90,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 90,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                        "line": 90,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 91,
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
                                                    "type": "string",
                                                    "value": "Meta-Data directory cannot be written",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                    "line": 94,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                                "line": 94,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                        "line": 94,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                                    "line": 95,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                            "line": 96,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Throws an exception when the metadata cannot be written\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                        "line": 86,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
                    "line": 85,
                    "last-line": 97,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
            "line": 29,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Stream.zep",
        "line": 29,
        "char": 5
    }
]