[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations\\Adapter",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                "line": 13,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Reflection",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                "line": 14,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Exception",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                "line": 15,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
        "line": 29,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Stores the parsed annotations in files. This adapter is suitable for production\n *\n *```php\n * use Phalcon\\Annotations\\Adapter\\Stream;\n *\n * $annotations = new Stream(\n *     [\n *         \"annotationsDir\" => \"app\/cache\/annotations\/\",\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
        "line": 30,
        "char": 5
    },
    {
        "type": "class",
        "name": "Stream",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "annotationsDir",
                    "default": {
                        "type": "string",
                        "value": ".\/",
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                        "line": 35,
                        "char": 34
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                    "line": 39,
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
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 40,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 40,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotationsDir",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 42,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 44,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "annotationsDir",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 44,
                                    "char": 58
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 44,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "annotationsDir",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 44,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 44,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 44,
                                "char": 58
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "annotationsDir",
                                            "expr": {
                                                "type": "variable",
                                                "value": "annotationsDir",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 45,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 45,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 46,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 47,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Annotations\\Adapter\\Stream constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                        "line": 41,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                    "line": 40,
                    "last-line": 51,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 52,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 54,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 59,
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
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                    "line": 59,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "annotationsDir",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                    "line": 59,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 59,
                                                "char": 41
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
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                            "line": 59,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                        "line": 59,
                                                        "char": 67
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "_",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                            "line": 59,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                        "line": 59,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 59,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 59,
                                            "char": 72
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ".php",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 59,
                                            "char": 78
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 59,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 59,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 61,
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
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 61,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 61,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 61,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 61,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 62,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 63,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 65,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "require",
                                "left": {
                                    "type": "variable",
                                    "value": "path",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 65,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 65,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 66,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads parsed annotations from files\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Reflection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 52,
                                    "char": 54
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 52,
                                "char": 54
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 52,
                                "char": 61
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 53,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                        "line": 53,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                    "line": 52,
                    "last-line": 70,
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
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 71,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Reflection",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 71,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 71,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 73,
                                    "char": 20
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 73,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 78,
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
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                    "line": 78,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "annotationsDir",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                    "line": 78,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 78,
                                                "char": 41
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
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                            "line": 78,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                        "line": 78,
                                                        "char": 67
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "_",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                            "line": 78,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                        "line": 78,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 78,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 78,
                                            "char": 72
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ".php",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 78,
                                            "char": 78
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 78,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 78,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 80,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "<?php return ",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 80,
                                                "char": 34
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
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                            "line": 80,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                        "line": 80,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                            "line": 80,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                        "line": 80,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 80,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 80,
                                            "char": 59
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "; ",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                            "line": 80,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 80,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 80,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 82,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "fcall",
                                        "name": "file_put_contents",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                    "line": 82,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 82,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "code",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                    "line": 82,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 82,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 82,
                                        "char": 53
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 82,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 82,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                "line": 82,
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
                                                    "value": "Annotations directory cannot be written",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                    "line": 83,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                                "line": 83,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                        "line": 83,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                                    "line": 84,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                            "line": 85,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes parsed annotations to files\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
                    "line": 71,
                    "last-line": 86,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
            "line": 30,
            "char": 5
        },
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Stream.zep",
        "line": 30,
        "char": 5
    }
]