[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Helper\/Str.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Helper",
        "file": "\/app\/phalcon\/Helper\/Str.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Helper\/Str.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Helper\/Str.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Exception",
                "file": "\/app\/phalcon\/Helper\/Str.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Helper\/Str.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "RuntimeException",
                "file": "\/app\/phalcon\/Helper\/Str.zep",
                "line": 15,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Helper\/Str.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class offers quick string functions throughout the framework\n *",
        "file": "\/app\/phalcon\/Helper\/Str.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Str",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "camelize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 45,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 45,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 45,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "text",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 47,
                                    "char": 21
                                },
                                "name": "camelize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 47,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 47,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 47,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 48,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Converts strings to camelize style\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::camelize(\"coco_bongo\");            \/\/ CocoBongo\n     * echo Str::camelize(\"co_co-bon_go\", \"-\");     \/\/ Co_coBon_go\n     * echo Str::camelize(\"co_co-bon_go\", \"_-\");    \/\/ CoCoBonGo\n     * ```\n     *\n     * @param string $text\n     * @param mixed  $delimiter\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 46,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 46,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 45,
                    "last-line": 72,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "concat",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "argument",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 21
                                },
                                {
                                    "variable": "arguments",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 32
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 38
                                },
                                {
                                    "variable": "first",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 45
                                },
                                {
                                    "variable": "last",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 51
                                },
                                {
                                    "variable": "prefix",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 59
                                },
                                {
                                    "variable": "delimiter",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 70
                                },
                                {
                                    "variable": "suffix",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 75,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 77,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "arguments",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "func_get_args",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 77,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 77,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 79,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "less",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "arguments",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 79,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 79,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 79,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "3",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 79,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 79,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 79,
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
                                                    "value": "concat needs at least three parameters",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 80,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 80,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 80,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 81,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 83,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "delimiter",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "first",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "arguments",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 83,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 83,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 83,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 83,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "arguments",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "sliceRight",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "arguments",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 84,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 84,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 84,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 84,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "first",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "first",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "arguments",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 85,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 85,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 85,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 85,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "last",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "last",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "arguments",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 86,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 86,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 86,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 86,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefix",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 87,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 87,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "suffix",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 88,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 88,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 89,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 89,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 91,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "startsWith",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "first",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 91,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 91,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 91,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 91,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 91,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "prefix",
                                            "expr": {
                                                "type": "variable",
                                                "value": "delimiter",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 92,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 92,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 95,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "endsWith",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "last",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 95,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 95,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 95,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 95,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 95,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "suffix",
                                            "expr": {
                                                "type": "variable",
                                                "value": "delimiter",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 96,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 96,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 97,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 100,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "arguments",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 100,
                                "char": 35
                            },
                            "value": "argument",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "trim",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "argument",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 101,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 101,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "delimiter",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 101,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 101,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 101,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 101,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 102,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 104,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "variable",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 104,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "implode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "delimiter",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 104,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 104,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 104,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 104,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 104,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 104,
                                    "char": 50
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "suffix",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 104,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 104,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 105,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Concatenates strings using the separator only once without duplication in\n     * places concatenation\n     *\n     * ```php\n     * $str = Phalcon\\Helper\\Str::concat(\n     *     \"\/\",\n     *     \"\/tmp\/\",\n     *     \"\/folder_1\/\",\n     *     \"\/folder_2\",\n     *     \"folder_3\/\"\n     * );\n     *\n     * echo $str;   \/\/ \/tmp\/folder_1\/folder_2\/folder_3\/\n     * ```\n     *\n     * @param string separator\n     * @param string a\n     * @param string b\n     * @param string ...N\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 74,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 74,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 73,
                    "last-line": 114,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "countVowels",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 115,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 117,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 119,
                            "char": 22
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "preg_match_all",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\/[aeiou]\/i",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 119,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 119,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 119,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 119,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "matches",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 119,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 119,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 119,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 121,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "matches",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 121,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 121,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 121,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 121,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 121,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 122,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retuns number of vowels in provided string. Uses a regular expression\n     * to count the number of vowels (A, E, I, O, U) in a string.\n     *\n     * @param string $string\n     *\n     * @return int\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 116,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 116,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 115,
                    "last-line": 134,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "decapitalize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 136,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "upperRest",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 137,
                                "char": 31
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 137,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "encoding",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "UTF-8",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 139,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 139,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "substr",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 141,
                                    "char": 19
                                },
                                {
                                    "variable": "suffix",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 141,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 143,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_substr",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 143,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 143,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 143,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "substr",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "mb_substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 144,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 144,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 144,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 144,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 144,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 144,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 145,
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
                                            "variable": "substr",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 146,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 146,
                                                        "char": 37
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 146,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 146,
                                                        "char": 40
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 146,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 146,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 147,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 149,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "upperRest",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 149,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "function_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "mb_strtoupper",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 150,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 150,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 150,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "suffix",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "mb_strtoupper",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "substr",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 151,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 151,
                                                                "char": 50
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "encoding",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 151,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 151,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 151,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 151,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 152,
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
                                                    "variable": "suffix",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "substr",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 153,
                                                            "char": 37
                                                        },
                                                        "name": "upper",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 153,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 153,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 154,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 155,
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
                                            "variable": "suffix",
                                            "expr": {
                                                "type": "variable",
                                                "value": "substr",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 156,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 156,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 157,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 159,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strtolower",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 159,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 159,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 159,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "fcall",
                                            "name": "mb_strtolower",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "mb_substr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "text",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 160,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 160,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 160,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 160,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 160,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 160,
                                                                "char": 54
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 160,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 160,
                                                    "char": 55
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "encoding",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 160,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 160,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 160,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "suffix",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 160,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 160,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 161,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strtolower",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "substr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "text",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 162,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 162,
                                                                "char": 42
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 162,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 162,
                                                                "char": 45
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 162,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 162,
                                                                "char": 48
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 162,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 162,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 162,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "suffix",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 162,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 162,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 163,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 164,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Decapitalizes the first letter of the sring and then adds it with rest\n     * of the string. Omit the upperRest parameter to keep the rest of the\n     * string intact, or set it to true to convert to uppercase.\n     *\n     * @param string $string\n     * @param bool   $upperRest\n     * @param string $encoding\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 140,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 140,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 135,
                    "last-line": 179,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "dirFromFile",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 180,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 182,
                                    "char": 17
                                },
                                {
                                    "variable": "start",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 182,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 184,
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
                                        "type": "fcall",
                                        "name": "pathinfo",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 184,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 184,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "PATHINFO_FILENAME",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 184,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 184,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 184,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 184,
                                    "char": 54
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "start",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 185,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 185,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 185,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 185,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "-2",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 185,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 185,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 185,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 185,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 187,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "start",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 187,
                                    "char": 19
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 187,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "start",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 188,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 188,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 188,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 188,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 188,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 188,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 188,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 188,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 189,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 191,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "fcall",
                                    "name": "implode",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "\/",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 191,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 191,
                                            "char": 25
                                        },
                                        {
                                            "parameter": {
                                                "type": "fcall",
                                                "name": "str_split",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "start",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 191,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 191,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "2",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 191,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 191,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 191,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 191,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 191,
                                    "char": 48
                                },
                                "right": {
                                    "type": "string",
                                    "value": "\/",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 191,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 191,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 192,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Accepts a file name (without extension) and returns a calculated\n     * directory structure with the filename in the end\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::dirFromFile(\"file1234.jpg\"); \/\/ fi\/le\/12\/\n     * ```\n     *\n     * @param string $file\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 181,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 181,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 180,
                    "last-line": 207,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "dirSeparator",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "directory",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 208,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "fcall",
                                    "name": "rtrim",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "directory",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 210,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 210,
                                            "char": 31
                                        },
                                        {
                                            "parameter": {
                                                "type": "constant",
                                                "value": "DIRECTORY_SEPARATOR",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 210,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 210,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 210,
                                    "char": 54
                                },
                                "right": {
                                    "type": "constant",
                                    "value": "DIRECTORY_SEPARATOR",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 210,
                                    "char": 75
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 210,
                                "char": 75
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 211,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Accepts a directory name and ensures that it ends with\n     * DIRECTORY_SEPARATOR\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::dirSeparator(\"\/home\/phalcon\"); \/\/ \/home\/phalcon\/\n     * ```\n     *\n     * @param string $directory\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 209,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 209,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 208,
                    "last-line": 242,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "dynamic",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 244,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "leftDelimiter",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "{",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 245,
                                "char": 34
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 245,
                            "char": 34
                        },
                        {
                            "type": "parameter",
                            "name": "rightDelimiter",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "}",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 246,
                                "char": 35
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 246,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "separator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "|",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 248,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 248,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "ldS",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 250,
                                    "char": 16
                                },
                                {
                                    "variable": "rdS",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 250,
                                    "char": 21
                                },
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 250,
                                    "char": 30
                                },
                                {
                                    "variable": "match",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 250,
                                    "char": 37
                                },
                                {
                                    "variable": "words",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 250,
                                    "char": 44
                                },
                                {
                                    "variable": "word",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 250,
                                    "char": 50
                                },
                                {
                                    "variable": "sub",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 250,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 251,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 251,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 253,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "fcall",
                                        "name": "substr_count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 253,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 253,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "leftDelimiter",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 253,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 253,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 253,
                                        "char": 57
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "substr_count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 253,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 253,
                                                "char": 76
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "rightDelimiter",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 253,
                                                    "char": 92
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 253,
                                                "char": 92
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 253,
                                        "char": 94
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 253,
                                    "char": 94
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 253,
                                "char": 94
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Syntax error in string \\\"",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 255,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 255,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 255,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\\"",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 256,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 256,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 256,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 256,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 257,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 259,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ldS",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_quote",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "leftDelimiter",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 259,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 259,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 259,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 259,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "rdS",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_quote",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "rightDelimiter",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 260,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 260,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 260,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 260,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pattern",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "\/",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 261,
                                                                    "char": 25
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "ldS",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 261,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 261,
                                                                "char": 31
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "([^",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 261,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 261,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ldS",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 261,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 261,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "rdS",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 261,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 261,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "]+)",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 261,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 261,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "rdS",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 261,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 261,
                                            "char": 61
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "\/",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 261,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 261,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 261,
                                    "char": 64
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "matches",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 262,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 262,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 264,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "preg_match_all",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "pattern",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 264,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 264,
                                            "char": 35
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 264,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 264,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "matches",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 264,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 264,
                                            "char": 50
                                        },
                                        {
                                            "parameter": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 264,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 264,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 264,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 264,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "text",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 265,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 266,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 268,
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
                                        "value": "matches",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 268,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 268,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 268,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 268,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "matches",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 269,
                                        "char": 34
                                    },
                                    "value": "match",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "or",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "match",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 270,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 270,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 270,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 270,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 270,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "match",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 270,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 270,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 270,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 270,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 270,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 270,
                                                "char": 55
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 272,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 274,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "words",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "explode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "separator",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 274,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 274,
                                                                "char": 46
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "match",
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 274,
                                                                        "char": 53
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 274,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 274,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 274,
                                                                "char": 56
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 274,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 274,
                                                    "char": 57
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "word",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "words",
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 275,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "array_rand",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "words",
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 275,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 275,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 275,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 275,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 275,
                                                    "char": 52
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "sub",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "preg_quote",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "match",
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 276,
                                                                        "char": 43
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 276,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 276,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 276,
                                                                "char": 46
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "separator",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 276,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 276,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 276,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 276,
                                                    "char": 58
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "text",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "preg_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "\/",
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 277,
                                                                            "char": 43
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "sub",
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 277,
                                                                            "char": 49
                                                                        },
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 277,
                                                                        "char": 49
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "\/",
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 277,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 277,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 277,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "word",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 277,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 277,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "text",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 277,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 277,
                                                                "char": 64
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 277,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 277,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 277,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 277,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 278,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 279,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 281,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "text",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 281,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 282,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates random text in accordance with the template\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * \/\/ Hi my name is a Bob\n     * echo Str::dynamic(\"{Hi|Hello}, my name is a {Bob|Mark|Jon}!\");\n     *\n     * \/\/ Hi my name is a Jon\n     * echo Str::dynamic(\"{Hi|Hello}, my name is a {Bob|Mark|Jon}!\");\n     *\n     * \/\/ Hello my name is a Bob\n     * echo Str::dynamic(\"{Hi|Hello}, my name is a {Bob|Mark|Jon}!\");\n     *\n     * \/\/ Hello my name is a Zyxep\n     * echo Str::dynamic(\n     *     \"[Hi\/Hello], my name is a [Zyxep\/Mark]!\",\n     *     \"[\", \"]\",\n     *     \"\/\"\n     * );\n     * ```\n     *\n     * @param string $text\n     * @param string $leftDelimiter\n     * @param string $rightDelimiter\n     * @param string $separator\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 249,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 249,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 243,
                    "last-line": 300,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "endsWith",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 301,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "end",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 301,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "ignoreCase",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 301,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 301,
                            "char": 90
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "ends_with",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 303,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 303,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "end",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 303,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 303,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ignoreCase",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 303,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 303,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 303,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 304,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a string ends with a given string\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::endsWith(\"Hello\", \"llo\");          \/\/ true\n     * echo Str::endsWith(\"Hello\", \"LLO\", false);   \/\/ false\n     * echo Str::endsWith(\"Hello\", \"LLO\");          \/\/ true\n     * ```\n     *\n     * @param string $text\n     * @param string $end\n     * @param bool   $ignoreCase\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 302,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 302,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 301,
                    "last-line": 315,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "firstBetween",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 317,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "start",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 318,
                            "char": 22
                        },
                        {
                            "type": "parameter",
                            "name": "end",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 320,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strstr",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 322,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 322,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 322,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "text",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "mb_strstr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "mb_strstr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "text",
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 323,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 323,
                                                                        "char": 57
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "start",
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 323,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 323,
                                                                        "char": 64
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 323,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 323,
                                                            "char": 65
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "end",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 323,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 323,
                                                            "char": 70
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 323,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 323,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 323,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 323,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 323,
                                            "char": 77
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 324,
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
                                            "variable": "text",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "strstr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "strstr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "text",
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 325,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 325,
                                                                        "char": 51
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "start",
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 325,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                        "line": 325,
                                                                        "char": 58
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 325,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 325,
                                                            "char": 59
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "end",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 325,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 325,
                                                            "char": 64
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 325,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 325,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 325,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 325,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 325,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 326,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 328,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "trim",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 329,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 329,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "variable",
                                                "value": "start",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 330,
                                                "char": 19
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "end",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 331,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 331,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 331,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 331,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 332,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the first string there is between the strings from the\n     * parameter start and end.\n     *\n     * @param string $text\n     * @param string $start\n     * @param string $end\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 321,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 321,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 316,
                    "last-line": 347,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "humanize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 348,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "preg_replace",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "#[_-]+#",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 350,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 350,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": " ",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 350,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 350,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "trim",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "text",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 350,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 350,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 350,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 350,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 350,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 351,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Makes an underscored or dashed phrase human-readable\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::humanize(\"start-a-horse\"); \/\/ \"start a horse\"\n     * echo Str::humanize(\"five_cats\");     \/\/ \"five cats\"\n     * ```\n     *\n     * @param string $text\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 349,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 349,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 348,
                    "last-line": 360,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "includes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "needle",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 361,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "haystack",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 361,
                            "char": 75
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strpos",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 363,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 363,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 363,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "fcall",
                                            "name": "mb_strpos",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "haystack",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 364,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 364,
                                                    "char": 45
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "needle",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 364,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 364,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 364,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 364,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 365,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "fcall",
                                            "name": "strpos",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "haystack",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 366,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 366,
                                                    "char": 42
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "needle",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 366,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 366,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 366,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 366,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 367,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 368,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Lets you determine whether or not a string includes another string.\n     *\n     * @param string $needle\n     * @param string $haystack\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 362,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 362,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 361,
                    "last-line": 385,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "increment",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 386,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "separator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "_",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 386,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 386,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 388,
                                    "char": 18
                                },
                                {
                                    "variable": "number",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 388,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 390,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "parts",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "separator",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 390,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 390,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 390,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 390,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 390,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 390,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 392,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "number",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 392,
                                    "char": 35
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "parts",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 392,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 392,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 392,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 392,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "incr",
                                            "variable": "number",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 393,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 394,
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
                                            "variable": "number",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 395,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 395,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 396,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 398,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "parts",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 398,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 398,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 398,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "separator",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 398,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 398,
                                    "char": 36
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "number",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 398,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 398,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 399,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a number to a string or increment that number if it already is\n     * defined\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::increment(\"a\");    \/\/ \"a_1\"\n     * echo Str::increment(\"a_1\");  \/\/ \"a_2\"\n     * ```\n     *\n     * @param string $text\n     * @param string $separator\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 387,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 387,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 386,
                    "last-line": 409,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "isAnagram",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "first",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 410,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "second",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 410,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "count_chars",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "first",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 412,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 412,
                                            "char": 33
                                        },
                                        {
                                            "parameter": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 412,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 412,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 412,
                                    "char": 40
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "count_chars",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "second",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 412,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 412,
                                            "char": 60
                                        },
                                        {
                                            "parameter": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 412,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 412,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 412,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 412,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 413,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Compare two strings and returns true if both strings are anagram,\n     * false otherwise.\n     *\n     * @param string $first\n     * @param string $second\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 411,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 411,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 410,
                    "last-line": 422,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "isLower",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 423,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "encoding",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "UTF-8",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 423,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 423,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strtolower",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 425,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 425,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 425,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 426,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "mb_strtolower",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "text",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 426,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 426,
                                                    "char": 47
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "encoding",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 426,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 426,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 426,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 426,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 427,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 428,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 428,
                                                "char": 34
                                            },
                                            "name": "lower",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 428,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 428,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 429,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 430,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns true if the given string is lower case, false otherwise.\n     *\n     * @param string $text\n     * @param string $encoding\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 424,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 424,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 423,
                    "last-line": 438,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "isPalindrome",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 439,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "strrev",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 441,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 441,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 441,
                                    "char": 31
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "text",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 441,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 441,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 442,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns true if the given string is a palindrome, false otherwise.\n     *\n     * @param string $text\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 440,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 440,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 439,
                    "last-line": 451,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "isUpper",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 452,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "encoding",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "UTF-8",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 452,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 452,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strtoupper",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 454,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 454,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 454,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 455,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "mb_strtoupper",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "text",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 455,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 455,
                                                    "char": 47
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "encoding",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 455,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 455,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 455,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 455,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 456,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 457,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 457,
                                                "char": 34
                                            },
                                            "name": "upper",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 457,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 457,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 458,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 459,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns true if the given string is upper case, false otherwise.\n     *\n     * @param string text\n     * @param string encoding\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 453,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 453,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 452,
                    "last-line": 473,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "lower",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 474,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "encoding",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "UTF-8",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 474,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 474,
                            "char": 78
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strtolower",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 480,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 480,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 480,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 481,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 481,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "encoding",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 481,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 481,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 481,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 482,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 484,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "text",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 484,
                                    "char": 21
                                },
                                "name": "lower",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 484,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 485,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Lowercases a string, this function makes use of the mbstring extension if\n     * available\n     *\n     * ```php\n     * echo Phalcon\\Helper\\Str::lower(\"HELLO\"); \/\/ hello\n     * ```\n     *\n     * @param string $text\n     * @param string $encoding\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 475,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 475,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 474,
                    "last-line": 501,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "random",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 502,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 502,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "length",
                            "const": 0,
                            "data-type": "long",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "8",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 502,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 502,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "pool",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 504,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 505,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "end",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 505,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 506,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "text",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 506,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 506,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 508,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "type",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 508,
                                "char": 21
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Str",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 510,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "RANDOM_ALPHA",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 510,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 510,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pool",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "range",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "a",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 511,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 511,
                                                                            "char": 47
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "z",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 511,
                                                                                "char": 50
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 511,
                                                                            "char": 50
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 511,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 511,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "range",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "A",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 511,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 511,
                                                                            "char": 60
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "Z",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 511,
                                                                                "char": 63
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 511,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 511,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 511,
                                                                "char": 64
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 511,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 511,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 512,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 514,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 514,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Str",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 514,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "RANDOM_HEXDEC",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 514,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 514,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pool",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "range",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "int",
                                                                                "value": "0",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 515,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 515,
                                                                            "char": 47
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "int",
                                                                                "value": "9",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 515,
                                                                                "char": 50
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 515,
                                                                            "char": 50
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 515,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 515,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "range",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "a",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 515,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 515,
                                                                            "char": 60
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "f",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 515,
                                                                                "char": 63
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 515,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 515,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 515,
                                                                "char": 64
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 515,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 515,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 516,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 518,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 518,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Str",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 518,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "RANDOM_NUMERIC",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 518,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 518,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pool",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "range",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 519,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 519,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "9",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 519,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 519,
                                                                "char": 38
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 519,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 519,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 520,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 522,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 522,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Str",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 522,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "RANDOM_NOZERO",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 522,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 522,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pool",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "range",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 523,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 523,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "9",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 523,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 523,
                                                                "char": 38
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 523,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 523,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 524,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 526,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 526,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Str",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 526,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "RANDOM_DISTINCT",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 526,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 526,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pool",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_split",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "2345679ACDEFHJKLMNPRSTUVWXYZ",
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 527,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 527,
                                                                "char": 66
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 527,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 527,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 528,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 530,
                                            "char": 19
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 530,
                                    "char": 19
                                },
                                {
                                    "type": "default",
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pool",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "range",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "int",
                                                                                "value": "0",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 533,
                                                                                "char": 28
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 533,
                                                                            "char": 28
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "int",
                                                                                "value": "9",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 533,
                                                                                "char": 31
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 533,
                                                                            "char": 31
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 533,
                                                                    "char": 32
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 533,
                                                                "char": 32
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "range",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "a",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 534,
                                                                                "char": 28
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 534,
                                                                            "char": 28
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "z",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 534,
                                                                                "char": 31
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 534,
                                                                            "char": 31
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 534,
                                                                    "char": 32
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 534,
                                                                "char": 32
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "range",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "A",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 535,
                                                                                "char": 28
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 535,
                                                                            "char": 28
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "Z",
                                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                                "line": 535,
                                                                                "char": 31
                                                                            },
                                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                            "line": 535,
                                                                            "char": 31
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                    "line": 536,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 536,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 536,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 536,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 538,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 539,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 539,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 541,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "end",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "fcall",
                                            "name": "count",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "pool",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 541,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 541,
                                                    "char": 29
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 541,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 541,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 541,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 541,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 543,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "fcall",
                                    "name": "strlen",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 543,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 543,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 543,
                                    "char": 28
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "length",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 543,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 543,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "text",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "pool",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 544,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "mt_rand",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 544,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 544,
                                                            "char": 38
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "end",
                                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                                "line": 544,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                            "line": 544,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 544,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 544,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 544,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 545,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 547,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "text",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 547,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 548,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random string based on the given type. Type is one of the\n     * RANDOM_* constants\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::random(Str::RANDOM_ALNUM); \/\/ \"aloiwkqz\"\n     * ```\n     *\n     * @param int $type\n     * @param int $length\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 503,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 503,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 502,
                    "last-line": 564,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "reduceSlashes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 565,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "preg_replace",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "#(?<!:)\/\/+#",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 567,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 567,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\/",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 567,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 567,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 567,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 567,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 567,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 568,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reduces multiple slashes in a string to single slashes\n     *\n     * ```php\n     * \/\/ foo\/bar\/baz\n     * echo Phalcon\\Helper\\Str::reduceSlashes(\"foo\/\/bar\/baz\");\n     *\n     * \/\/ http:\/\/foo.bar\/baz\/buz\n     * echo Phalcon\\Helper\\Str::reduceSlashes(\"http:\/\/foo.bar\/\/\/baz\/buz\");\n     * ```\n     *\n     * @param string $text\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 566,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 566,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 565,
                    "last-line": 586,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "startsWith",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 587,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "start",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 587,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "ignoreCase",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 587,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 587,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "starts_with",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 589,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 589,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "start",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 589,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 589,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ignoreCase",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 589,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 589,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 589,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 590,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a string starts with a given string\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::startsWith(\"Hello\", \"He\");         \/\/ true\n     * echo Str::startsWith(\"Hello\", \"he\", false);  \/\/ false\n     * echo Str::startsWith(\"Hello\", \"he\");         \/\/ true\n     * ```\n     *\n     * @param string $text\n     * @param string $start\n     * @param bool   $ignoreCase\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 588,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 588,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 587,
                    "last-line": 606,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "uncamelize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 607,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 607,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 607,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "text",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 609,
                                    "char": 21
                                },
                                "name": "uncamelize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 609,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 609,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 609,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 610,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Uncamelize strings which are camelized\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::uncamelize(\"CocoBongo\");       \/\/ coco_bongo\n     * echo Str::uncamelize(\"CocoBongo\", \"-\");  \/\/ coco-bongo\n     * ```\n     *\n     * @param string $text\n     * @param mixed  $delimiter\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 608,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 608,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 607,
                    "last-line": 625,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "underscore",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 626,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "preg_replace",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "#\\s+#",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 628,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 628,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "_",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 628,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 628,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "trim",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "text",
                                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                        "line": 628,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 628,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 628,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 628,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 628,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 629,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Makes a phrase underscored instead of spaced\n     *\n     * ```php\n     * use Phalcon\\Helper\\Str;\n     *\n     * echo Str::underscore(\"look behind\");     \/\/ \"look_behind\"\n     * echo Str::underscore(\"Awesome Phalcon\"); \/\/ \"Awesome_Phalcon\"\n     * ```\n     *\n     * @param string $text\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 627,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 627,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 626,
                    "last-line": 643,
                    "char": 32
                },
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "upper",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 644,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "encoding",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "UTF-8",
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 644,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 644,
                            "char": 78
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "mb_strtoupper",
                                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                                            "line": 650,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 650,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 650,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_strtoupper",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 651,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 651,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "encoding",
                                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                    "line": 651,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                                "line": 651,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                                        "line": 651,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 652,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 654,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "text",
                                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                                    "line": 654,
                                    "char": 21
                                },
                                "name": "upper",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 654,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Helper\/Str.zep",
                            "line": 655,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Uppercases a string, this function makes use of the mbstring extension if\n     * available\n     *\n     * ```php\n     * echo Phalcon\\Helper\\Str::upper(\"hello\"); \/\/ HELLO\n     * ```\n     *\n     * @param string $text\n     * @param string $encoding\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Str.zep",
                                "line": 645,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 645,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 644,
                    "last-line": 656,
                    "char": 32
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "RANDOM_ALNUM",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 22,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 23,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_ALPHA",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 23,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 24,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_DISTINCT",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 24,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 25,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_HEXDEC",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 25,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 26,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_NOZERO",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 26,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 27,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_NUMERIC",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Helper\/Str.zep",
                        "line": 27,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Helper\/Str.zep",
                    "line": 44,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Helper\/Str.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Helper\/Str.zep",
        "line": 20,
        "char": 5
    }
]