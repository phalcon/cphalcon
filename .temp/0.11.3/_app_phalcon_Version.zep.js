[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Version.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Version.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class allows to get the installed version of the framework\n *",
        "file": "\/app\/phalcon\/Version.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Version",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "method",
                    "name": "_getVersion",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "int",
                                            "value": "4",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 85,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 85,
                                        "char": 18
                                    },
                                    {
                                        "value": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 85,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 85,
                                        "char": 21
                                    },
                                    {
                                        "value": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 85,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 85,
                                        "char": 24
                                    },
                                    {
                                        "value": {
                                            "type": "int",
                                            "value": "2",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 85,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 85,
                                        "char": 27
                                    },
                                    {
                                        "value": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 85,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 85,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 85,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 86,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Area where the version number is set. The format is as follows:\n     * ABBCCDE\n     *\n     * A - Major version\n     * B - Med version (two digits)\n     * C - Min version (two digits)\n     * D - Special release: 1 = alpha, 2 = beta, 3 = RC, 4 = stable\n     * E - Special release version i.e. RC1, Beta2 etc.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 84,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 84,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 83,
                    "last-line": 90,
                    "char": 29
                },
                {
                    "visibility": [
                        "protected",
                        "final",
                        "static"
                    ],
                    "type": "method",
                    "name": "_getSpecial",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "special",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 91,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "suffix",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 93,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 93,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 95,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "special",
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 95,
                                "char": 24
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 96,
                                        "char": 19
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
                                                        "type": "string",
                                                        "value": "alpha",
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 97,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 97,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 98,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 99,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 99,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "2",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 99,
                                        "char": 19
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
                                                        "type": "string",
                                                        "value": "beta",
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 100,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 100,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 101,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 102,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 102,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "3",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 102,
                                        "char": 19
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
                                                        "type": "string",
                                                        "value": "RC",
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 103,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 103,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 104,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 105,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 105,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 107,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "suffix",
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 107,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 108,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Translates a number to a special release.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 92,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 92,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 91,
                    "last-line": 116,
                    "char": 35
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "get",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "version",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 119,
                                    "char": 20
                                },
                                {
                                    "variable": "major",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 119,
                                    "char": 27
                                },
                                {
                                    "variable": "medium",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 119,
                                    "char": 35
                                },
                                {
                                    "variable": "minor",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 119,
                                    "char": 42
                                },
                                {
                                    "variable": "special",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 119,
                                    "char": 51
                                },
                                {
                                    "variable": "specialNumber",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 119,
                                    "char": 66
                                },
                                {
                                    "variable": "suffix",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 119,
                                    "char": 74
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 120,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 120,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 122,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "version",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "static",
                                        "dynamic": 0,
                                        "name": "_getVersion",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 122,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 122,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 124,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "major",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 124,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 124,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_MAJOR",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 124,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 124,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 124,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 124,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "medium",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 125,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 125,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_MEDIUM",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 125,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 125,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 125,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 125,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "minor",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 126,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 126,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_MINOR",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 126,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 126,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 126,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 126,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "special",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 127,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 127,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_SPECIAL",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 127,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 127,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 127,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 127,
                                    "char": 59
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "specialNumber",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 128,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 128,
                                                "char": 65
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_SPECIAL_NUMBER",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 128,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 128,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 128,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 128,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 130,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "major",
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 130,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": ".",
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 130,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 130,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "medium",
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 130,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 130,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": ".",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 130,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 130,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "minor",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 130,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 130,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 130,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 131,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "suffix",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "static",
                                        "dynamic": 0,
                                        "name": "_getSpecial",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "special",
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 131,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 131,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 131,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 131,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 133,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "suffix",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 133,
                                    "char": 20
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 133,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 133,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "-",
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 139,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "suffix",
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 139,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 139,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 139,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 141,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "specialNumber",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 141,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 141,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 141,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "result",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": ".",
                                                            "file": "\/app\/phalcon\/Version.zep",
                                                            "line": 142,
                                                            "char": 32
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "specialNumber",
                                                            "file": "\/app\/phalcon\/Version.zep",
                                                            "line": 142,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 142,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 142,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 143,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 144,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 146,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 146,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 147,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the active version (string)\n     *\n     * ```php\n     * echo Phalcon\\Version::get();\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 118,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 118,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 117,
                    "last-line": 155,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getId",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "version",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 158,
                                    "char": 20
                                },
                                {
                                    "variable": "major",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 158,
                                    "char": 27
                                },
                                {
                                    "variable": "medium",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 158,
                                    "char": 35
                                },
                                {
                                    "variable": "minor",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 158,
                                    "char": 42
                                },
                                {
                                    "variable": "special",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 158,
                                    "char": 51
                                },
                                {
                                    "variable": "specialNumber",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 158,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 160,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "version",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "static",
                                        "dynamic": 0,
                                        "name": "_getVersion",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 160,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 160,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 162,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "major",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 162,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 162,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_MAJOR",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 162,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 162,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 162,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 162,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "medium",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 163,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 163,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_MEDIUM",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 163,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 163,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 163,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 163,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "minor",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 164,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 164,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_MINOR",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 164,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 164,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 164,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 164,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "special",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 165,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 165,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_SPECIAL",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 165,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 165,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 165,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 165,
                                    "char": 59
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "specialNumber",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 166,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 166,
                                                "char": 65
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "VERSION_SPECIAL_NUMBER",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 166,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 166,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 166,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 166,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 168,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "variable",
                                                "value": "major",
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 168,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "sprintf",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "%02s",
                                                            "file": "\/app\/phalcon\/Version.zep",
                                                            "line": 168,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 168,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "medium",
                                                            "file": "\/app\/phalcon\/Version.zep",
                                                            "line": 168,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 168,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 168,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 168,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "sprintf",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "%02s",
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 168,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 168,
                                                    "char": 60
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "minor",
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 168,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 168,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 168,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 168,
                                        "char": 69
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "special",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 168,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 168,
                                    "char": 79
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "specialNumber",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 168,
                                    "char": 94
                                },
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 168,
                                "char": 94
                            },
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 169,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the numeric active version\n     *\n     * ```php\n     * echo Phalcon\\Version::getId();\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 157,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 157,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 156,
                    "last-line": 180,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getPart",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "part",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 181,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "version",
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 183,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 185,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "version",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "static",
                                        "dynamic": 0,
                                        "name": "_getVersion",
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 185,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 185,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 187,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "part",
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 187,
                                "char": 21
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 188,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "VERSION_MAJOR",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 188,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 188,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 189,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 189,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "VERSION_MEDIUM",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 189,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 189,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 190,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 190,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "VERSION_MINOR",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 190,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 190,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 191,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 191,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "VERSION_SPECIAL_NUMBER",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 191,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 191,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "version",
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 192,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Version.zep",
                                                    "line": 192,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 192,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 194,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 194,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 194,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "VERSION_SPECIAL",
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 194,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Version.zep",
                                        "line": 194,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "static",
                                                "dynamic": 0,
                                                "name": "_getSpecial",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "version",
                                                                "file": "\/app\/phalcon\/Version.zep",
                                                                "line": 196,
                                                                "char": 28
                                                            },
                                                            "right": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "self",
                                                                    "file": "\/app\/phalcon\/Version.zep",
                                                                    "line": 196,
                                                                    "char": 50
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "VERSION_SPECIAL",
                                                                    "file": "\/app\/phalcon\/Version.zep",
                                                                    "line": 196,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Version.zep",
                                                                "line": 196,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Version.zep",
                                                            "line": 197,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Version.zep",
                                                        "line": 197,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Version.zep",
                                                "line": 197,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Version.zep",
                                            "line": 198,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Version.zep",
                                    "line": 198,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 200,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "static",
                                "dynamic": 0,
                                "name": "get",
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 200,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Version.zep",
                            "line": 201,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a specific part of the version. If the wrong parameter is passed\n     * it will return the full version\n     *\n     * ```php\n     * echo Phalcon\\Version::getPart(\n     *     Phalcon\\Version::VERSION_MAJOR\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Version.zep",
                                "line": 182,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 182,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 181,
                    "last-line": 202,
                    "char": 26
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "VERSION_MAJOR",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 27,
                        "char": 28
                    },
                    "docblock": "**\n     * The constant referencing the major version. Returns 0\n     *\n     * ```php\n     * echo Phalcon\\Version::getPart(\n     *     Phalcon\\Version::VERSION_MAJOR\n     * );\n     * ```\n     *",
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 37,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "VERSION_MEDIUM",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 38,
                        "char": 29
                    },
                    "docblock": "**\n     * The constant referencing the major version. Returns 1\n     *\n     * ```php\n     * echo Phalcon\\Version::getPart(\n     *     Phalcon\\Version::VERSION_MEDIUM\n     * );\n     * ```\n     *",
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 48,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "VERSION_MINOR",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 49,
                        "char": 28
                    },
                    "docblock": "**\n     * The constant referencing the major version. Returns 2\n     *\n     * ```php\n     * echo Phalcon\\Version::getPart(\n     *     Phalcon\\Version::VERSION_MINOR\n     * );\n     * ```\n     *",
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 59,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "VERSION_SPECIAL",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 60,
                        "char": 30
                    },
                    "docblock": "**\n     * The constant referencing the major version. Returns 3\n     *\n     * ```php\n     * echo Phalcon\\Version::getPart(\n     *     Phalcon\\Version::VERSION_SPECIAL\n     * );\n     * ```\n     *",
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 70,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "VERSION_SPECIAL_NUMBER",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Version.zep",
                        "line": 71,
                        "char": 37
                    },
                    "docblock": "**\n     * The constant referencing the major version. Returns 4\n     *\n     * ```php\n     * echo Phalcon\\Version::getPart(\n     *     Phalcon\\Version::VERSION_SPECIAL_NUMBER\n     * );\n     * ```\n     *",
                    "file": "\/app\/phalcon\/Version.zep",
                    "line": 82,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Version.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Version.zep",
        "line": 16,
        "char": 5
    }
]