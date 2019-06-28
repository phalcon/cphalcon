[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Session\\Adapter",
        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Str",
                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Session\\Exception",
                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                "line": 14,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
        "line": 35,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Session\\Adapter\\Stream\n *\n * This is the file based adapter. It stores sessions in a file based system\n *\n * ```php\n * <?php\n *\n * use Phalcon\\Session\\Manager;\n * use Phalcon\\Session\\Adapter\\Stream;\n *\n * $session = new Manager();\n * $files = new Stream(\n *     [\n *         'savePath' => '\/tmp',\n *     ]\n * );\n * $session->setHandler($files);\n * ```\n *",
        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
        "line": 36,
        "char": 5
    },
    {
        "type": "class",
        "name": "Stream",
        "abstract": 0,
        "final": 0,
        "extends": "Noop",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "path",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                        "line": 41,
                        "char": 20
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                    "line": 43,
                    "char": 10
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
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 43,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 43,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 45,
                                    "char": 17
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 45,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 47,
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
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 47,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 47,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 47,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 49,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 49,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 49,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 49,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 49,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 55,
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
                                        "value": "path",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 55,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 55,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "savePath",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 55,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 55,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 55,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 55,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "path",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "ini_get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "session.save_path",
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 56,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 56,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 56,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 56,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 57,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 59,
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
                                        "name": "is_writable",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 59,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 59,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 59,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 59,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 59,
                                "char": 40
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
                                                            "value": "The save_path [",
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 60,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "path",
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 60,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 60,
                                                        "char": 56
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "]is not writeable",
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 60,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 60,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 60,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 60,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 61,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 63,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "path",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Str",
                                        "dynamic": 0,
                                        "name": "dirSeparator",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 63,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 63,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 63,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 63,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 64,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                        "line": 44,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                    "line": 43,
                    "last-line": 66,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "destroy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 66,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 68,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 70,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "file",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 70,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 70,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 70,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 70,
                                                "char": 38
                                            },
                                            "name": "getPrefixedName",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 70,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 70,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 70,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 70,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 70,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 72,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fcall",
                                    "name": "file_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 72,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 72,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 72,
                                    "char": 31
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "is_file",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 72,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 72,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 72,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 72,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "unlink",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 73,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 73,
                                                "char": 24
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 73,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 74,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 76,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 76,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 77,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                    "line": 66,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "gc",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "maxlifetime",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 79,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 81,
                                    "char": 17
                                },
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 81,
                                    "char": 26
                                },
                                {
                                    "variable": "time",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 81,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 83,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pattern",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 83,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 83,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 83,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 83,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 83,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 83,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 83,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "*",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 83,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 83,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 83,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "time",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "fcall",
                                            "name": "time",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 84,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "maxlifetime",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 84,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 84,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 84,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 86,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "glob",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "pattern",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 86,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 86,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 86,
                                "char": 35
                            },
                            "value": "file",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "and",
                                            "left": {
                                                "type": "fcall",
                                                "name": "file_exists",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 87,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 87,
                                                        "char": 32
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 87,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "is_file",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 88,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 88,
                                                        "char": 28
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 88,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 88,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "list",
                                            "left": {
                                                "type": "less",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "filemtime",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "file",
                                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                                "line": 89,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 89,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 89,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "time",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 89,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 89,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 89,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 89,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "unlink",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 90,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 90,
                                                        "char": 28
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 90,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 91,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 92,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 94,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 94,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 80,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                        "line": 80,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                    "line": 79,
                    "last-line": 97,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "open",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "savePath",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 97,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "sessionName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 97,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 99,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 101,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 101,
                                    "char": 19
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "ends_with",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "savePath",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 101,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 101,
                                            "char": 39
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "\/",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 101,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 101,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 101,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 101,
                                "char": 44
                            },
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
                                                    "type": "variable",
                                                    "value": "savePath",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 102,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "\/",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 102,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 102,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 102,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 103,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 105,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "path",
                                    "expr": {
                                        "type": "variable",
                                        "value": "path",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 105,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 105,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 107,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 107,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 108,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 98,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                        "line": 98,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                    "line": 97,
                    "last-line": 110,
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
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 110,
                            "char": 32
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 112,
                                    "char": 17
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 112,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 114,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 114,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 114,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 114,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 114,
                                                "char": 38
                                            },
                                            "name": "getPrefixedName",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 114,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 114,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 114,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 114,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 114,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 115,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 115,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 117,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "file_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 117,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 117,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 117,
                                "char": 30
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
                                                "type": "fcall",
                                                "name": "file_get_contents",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                            "line": 118,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 118,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 118,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 118,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 120,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 120,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 120,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 120,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 121,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 122,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 123,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 125,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 125,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 126,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 111,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                        "line": 111,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                    "line": 110,
                    "last-line": 128,
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
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 128,
                            "char": 33
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 128,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 130,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 132,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 132,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 132,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 132,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 132,
                                                "char": 38
                                            },
                                            "name": "getPrefixedName",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                        "line": 132,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                    "line": 132,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 132,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                        "line": 132,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 132,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 134,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 134,
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
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 134,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 134,
                                            "char": 48
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                                "line": 134,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                            "line": 134,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                    "line": 134,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 134,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                            "line": 135,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                                "line": 129,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                        "line": 129,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
                    "line": 128,
                    "last-line": 136,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
            "line": 36,
            "char": 5
        },
        "file": "\/app\/phalcon\/Session\/Adapter\/Stream.zep",
        "line": 36,
        "char": 5
    }
]