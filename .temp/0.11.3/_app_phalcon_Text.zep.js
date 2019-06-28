[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Text.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Text.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Str",
                "file": "\/app\/phalcon\/Text.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Text.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Provides utilities to work with texts\n *",
        "file": "\/app\/phalcon\/Text.zep",
        "line": 18,
        "char": 8
    },
    {
        "type": "class",
        "name": "Text",
        "abstract": 1,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 36,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 36,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 36,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "camelize",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 38,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 38,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 38,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 38,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 38,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 39,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Converts strings to camelize style\n     *\n     * ```php\n     * echo Phalcon\\Text::camelize(\"coco_bongo\"); \/\/ CocoBongo\n     * echo Phalcon\\Text::camelize(\"co_co-bon_go\", \"-\"); \/\/ Co_coBon_go\n     * echo Phalcon\\Text::camelize(\"co_co-bon_go\", \"_-\"); \/\/ CoCoBonGo\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 37,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 37,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 36,
                    "last-line": 62,
                    "char": 26
                },
                {
                    "visibility": [
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
                                    "variable": "args",
                                    "file": "\/app\/phalcon\/Text.zep",
                                    "line": 66,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 68,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "args",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "func_get_args",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 68,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Text.zep",
                                    "line": 68,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 70,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "call_user_func_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Helper\\\\Str::concat",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 70,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 70,
                                        "char": 67
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "args",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 70,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 70,
                                        "char": 73
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 70,
                                "char": 74
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Concatenates strings using the separator only once without duplication in\n     * places concatenation\n     *\n     * ```php\n     * $str = Phalcon\\Text::concat(\n     *     \"\/\",\n     *     \"\/tmp\/\",\n     *     \"\/folder_1\/\",\n     *     \"\/folder_2\",\n     *     \"folder_3\/\"\n     * );\n     *\n     * \/\/ \/tmp\/folder_1\/folder_2\/folder_3\/\n     * echo $str;\n     * ```\n     *\n     * @param string separator\n     * @param string a\n     * @param string b\n     * @param string ...N\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 64,
                    "last-line": 93,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 95,
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 96,
                                "char": 34
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 96,
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 97,
                                "char": 35
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 97,
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 99,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "dynamic",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 101,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 101,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "leftDelimiter",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 101,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 101,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "rightDelimiter",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 101,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 101,
                                        "char": 64
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "separator",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 101,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 101,
                                        "char": 75
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 101,
                                "char": 76
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 102,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates random text in accordance with the template\n     *\n     * ```php\n     * \/\/ Hi my name is a Bob\n     * echo Phalcon\\Text::dynamic(\"{Hi|Hello}, my name is a {Bob|Mark|Jon}!\");\n     *\n     * \/\/ Hi my name is a Jon\n     * echo Phalcon\\Text::dynamic(\"{Hi|Hello}, my name is a {Bob|Mark|Jon}!\");\n     *\n     * \/\/ Hello my name is a Bob\n     * echo Phalcon\\Text::dynamic(\"{Hi|Hello}, my name is a {Bob|Mark|Jon}!\");\n     *\n     * \/\/ Hello my name is a Zyxep\n     * echo Phalcon\\Text::dynamic(\n     *     \"[Hi\/Hello], my name is a [Zyxep\/Mark]!\",\n     *     \"[\", \"]\",\n     *     \"\/\"\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 100,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 100,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 94,
                    "last-line": 112,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 113,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "end",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 113,
                            "char": 60
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 113,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 113,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "endsWith",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 115,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 115,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "end",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 115,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 115,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ignoreCase",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 115,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 115,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 115,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 116,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a string ends with a given string\n     *\n     * ```php\n     * echo Phalcon\\Text::endsWith(\"Hello\", \"llo\"); \/\/ true\n     * echo Phalcon\\Text::endsWith(\"Hello\", \"LLO\", false); \/\/ false\n     * echo Phalcon\\Text::endsWith(\"Hello\", \"LLO\"); \/\/ true\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 114,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 114,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 113,
                    "last-line": 125,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 126,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "humanize",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 128,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 128,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 128,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Makes an underscored or dashed phrase human-readable\n     *\n     * ```php\n     * echo Phalcon\\Text::humanize(\"start-a-horse\"); \/\/ \"start a horse\"\n     * echo Phalcon\\Text::humanize(\"five_cats\"); \/\/ \"five cats\"\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 127,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 127,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 126,
                    "last-line": 139,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 140,
                            "char": 49
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 140,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 140,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "increment",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 142,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 142,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "separator",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 142,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 142,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 142,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a number to a string or increment that number if it already is\n     * defined\n     *\n     * ```php\n     * echo Phalcon\\Text::increment(\"a\"); \/\/ \"a_1\"\n     * echo Phalcon\\Text::increment(\"a_1\"); \/\/ \"a_2\"\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 141,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 140,
                    "last-line": 152,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 153,
                            "char": 46
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 153,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 153,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "lower",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 155,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 155,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "encoding",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 155,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 155,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 155,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 156,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Lowercases a string, this function makes use of the mbstring extension if\n     * available\n     *\n     * ```php\n     * echo Phalcon\\Text::lower(\"HELLO\"); \/\/ hello\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 154,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 154,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 153,
                    "last-line": 166,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 167,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "start",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 167,
                            "char": 64
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 167,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 167,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "startsWith",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 169,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 169,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "start",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 169,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 169,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ignoreCase",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 169,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 169,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 169,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 170,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a string starts with a given string\n     *\n     * ```php\n     * echo Phalcon\\Text::startsWith(\"Hello\", \"He\"); \/\/ true\n     * echo Phalcon\\Text::startsWith(\"Hello\", \"he\", false); \/\/ false\n     * echo Phalcon\\Text::startsWith(\"Hello\", \"he\"); \/\/ true\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 168,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 168,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 167,
                    "last-line": 182,
                    "char": 26
                },
                {
                    "visibility": [
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 183,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 183,
                            "char": 47
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 183,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 183,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "random",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 185,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 185,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "length",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 185,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 185,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 185,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random string based on the given type. Type is one of the\n     * RANDOM_* constants\n     *\n     * ```php\n     * use Phalcon\\Text;\n     *\n     * \/\/ \"aloiwkqz\"\n     * echo Text::random(Text::RANDOM_ALNUM);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 183,
                    "last-line": 198,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 199,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "reduceSlashes",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 201,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 201,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 201,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 202,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reduces multiple slashes in a string to single slashes\n     *\n     * ```php\n     * \/\/ foo\/bar\/baz\n     * echo Phalcon\\Text::reduceSlashes(\"foo\/\/bar\/baz\");\n     *\n     * \/\/ http:\/\/foo.bar\/baz\/buz\n     * echo Phalcon\\Text::reduceSlashes(\"http:\/\/foo.bar\/\/\/baz\/buz\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 200,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 200,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 199,
                    "last-line": 211,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 212,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 212,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 212,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "uncamelize",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 214,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 214,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 214,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 214,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 214,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 215,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Uncamelize strings which are camelized\n     *\n     * ```php\n     * echo Phalcon\\Text::uncamelize(\"CocoBongo\"); \/\/ coco_bongo\n     * echo Phalcon\\Text::uncamelize(\"CocoBongo\", \"-\"); \/\/ coco-bongo\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 213,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 213,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 212,
                    "last-line": 224,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 225,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "underscore",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 227,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 227,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 227,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 228,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Makes a phrase underscored instead of spaced\n     *\n     * ```php\n     * echo Phalcon\\Text::underscore(\"look behind\"); \/\/ \"look_behind\"\n     * echo Phalcon\\Text::underscore(\"Awesome Phalcon\"); \/\/ \"Awesome_Phalcon\"\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 226,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 226,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 225,
                    "last-line": 237,
                    "char": 26
                },
                {
                    "visibility": [
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
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 238,
                            "char": 46
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
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 238,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 238,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Str",
                                "dynamic": 0,
                                "name": "upper",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 240,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 240,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "encoding",
                                            "file": "\/app\/phalcon\/Text.zep",
                                            "line": 240,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Text.zep",
                                        "line": 240,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 240,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Text.zep",
                            "line": 241,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Uppercases a string, this function makes use of the mbstring extension if\n     * available\n     *\n     * ```php\n     * echo Phalcon\\Text::upper(\"hello\"); \/\/ HELLO\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Text.zep",
                                "line": 239,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 239,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 238,
                    "last-line": 242,
                    "char": 26
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "RANDOM_ALNUM",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 20,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 21,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_ALPHA",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 21,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 22,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_DISTINCT",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 22,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 23,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_HEXDEC",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 23,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 24,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_NOZERO",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 24,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 25,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "RANDOM_NUMERIC",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Text.zep",
                        "line": 25,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Text.zep",
                    "line": 35,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Text.zep",
            "line": 18,
            "char": 14
        },
        "file": "\/app\/phalcon\/Text.zep",
        "line": 18,
        "char": 14
    }
]