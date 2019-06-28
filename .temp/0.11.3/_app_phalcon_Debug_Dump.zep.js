[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Debug",
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Reflection",
                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                "line": 14,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionClass",
                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                "line": 15,
                "char": 20
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionProperty",
                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                "line": 16,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "stdClass",
                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                "line": 17,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 35,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Dumps information about a variable(s)\n *\n * ```php\n * $foo = 123;\n *\n * echo (new \\Phalcon\\Debug\\Dump())->variable($foo, \"foo\");\n * ```\n *\n * ```php\n * $foo = \"string\";\n * $bar = [\"key\" => \"value\"];\n * $baz = new stdClass();\n *\n * echo (new \\Phalcon\\Debug\\Dump())->variables($foo, $bar, $baz);\n * ```\n *",
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 36,
        "char": 5
    },
    {
        "type": "class",
        "name": "Dump",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "detailed",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 41,
                        "char": 32
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 41,
                            "char": 37
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 41,
                            "char": 43
                        }
                    ],
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 45,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "methods",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 46,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "styles",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 51,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 55,
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
                            "name": "styles",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 56,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 56,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "detailed",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 56,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 56,
                            "char": 74
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
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 58,
                                    "char": 14
                                },
                                "name": "setStyles",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "styles",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 58,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 58,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 58,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 60,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "detailed",
                                    "expr": {
                                        "type": "variable",
                                        "value": "detailed",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 60,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 60,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Debug\\Dump constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 56,
                    "last-line": 66,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "all",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "call_user_func_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 71,
                                                        "char": 21
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 71,
                                                    "char": 21
                                                },
                                                {
                                                    "value": {
                                                        "type": "string",
                                                        "value": "variables",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 73,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 73,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 73,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 73,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "func_get_args",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 75,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 75,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 75,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 76,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias of variables() method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 68,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 68,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 67,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "one",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "variable",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 81,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 81,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 81,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 83,
                                    "char": 21
                                },
                                "name": "variable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 83,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 83,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 83,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 83,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 83,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias of variable() method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 82,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 82,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 81,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStyles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "styles",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 89,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 89,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "defaultStyles",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 91,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 93,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "defaultStyles",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "pre",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 94,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "background-color:#f3f3f3; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 94,
                                                    "char": 127
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 94,
                                                "char": 127
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "arr",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 95,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:red",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 95,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 95,
                                                "char": 30
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "bool",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 96,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:green",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 96,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 96,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "float",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 97,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:fuchsia",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 97,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 97,
                                                "char": 34
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "int",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 98,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:blue",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 98,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 98,
                                                "char": 31
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "null",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 99,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:black",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 99,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 99,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "num",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 100,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:navy",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 100,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 100,
                                                "char": 31
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "obj",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 101,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:purple",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 101,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 101,
                                                "char": 33
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "other",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 102,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:maroon",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 102,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 102,
                                                "char": 33
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "res",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 103,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:lime",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 103,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 103,
                                                "char": 31
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "str",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 104,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "color:teal",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 105,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 105,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 105,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 105,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 107,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "styles",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "defaultStyles",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 107,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 107,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "styles",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 107,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 107,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 107,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 107,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 109,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 109,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "styles",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 109,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 109,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 110,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set styles for vars type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 90,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 89,
                    "last-line": 127,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toJson",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "variable",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 128,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "json_encode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 131,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 131,
                                        "char": 21
                                    },
                                    {
                                        "parameter": {
                                            "type": "bitwise_or",
                                            "left": {
                                                "type": "bitwise_or",
                                                "left": {
                                                    "type": "constant",
                                                    "value": "JSON_PRETTY_PRINT",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 132,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "JSON_UNESCAPED_SLASHES",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 132,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 132,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "constant",
                                                "value": "JSON_UNESCAPED_UNICODE",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 133,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 133,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 133,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 133,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 134,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an JSON string of information about a single variable.\n     *\n     * ```php\n     * $foo = [\n     *     \"key\" => \"value\",\n     * ];\n     *\n     * echo (new \\Phalcon\\Debug\\Dump())->toJson($foo);\n     *\n     * $foo = new stdClass();\n     * $foo->bar = \"buz\";\n     *\n     * echo (new \\Phalcon\\Debug\\Dump())->toJson($foo);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 129,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 129,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 128,
                    "last-line": 142,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "variable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "variable",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 143,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 143,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 143,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "strtr",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "<pre style=':style'>:output<\/pre>",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 146,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 146,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": ":style",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 148,
                                                        "char": 23
                                                    },
                                                    "value": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 148,
                                                            "char": 31
                                                        },
                                                        "name": "getStyle",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "pre",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 148,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 148,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 148,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 148,
                                                    "char": 45
                                                },
                                                {
                                                    "key": {
                                                        "type": "string",
                                                        "value": ":output",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 149,
                                                        "char": 24
                                                    },
                                                    "value": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 149,
                                                            "char": 31
                                                        },
                                                        "name": "output",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "variable",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 149,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 149,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 149,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 149,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 150,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 150,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 151,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 151,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 151,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 152,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an HTML string of information about a single variable.\n     *\n     * ```php\n     * echo (new \\Phalcon\\Debug\\Dump())->variable($foo, \"foo\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 144,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 144,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 143,
                    "last-line": 165,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "variables",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 168,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 168,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 169,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "output",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 169,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 171,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "output",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 171,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 171,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 173,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "func_get_args",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 173,
                                "char": 43
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 174,
                                                    "char": 31
                                                },
                                                "name": "one",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 175,
                                                            "char": 22
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 175,
                                                        "char": 22
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "var ",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 176,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 177,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 177,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 177,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 177,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 177,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 178,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 180,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "output",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 180,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 181,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an HTML string of debugging information about any number of\n     * variables, each wrapped in a \"pre\" tag.\n     *\n     * ```php\n     * $foo = \"string\";\n     * $bar = [\"key\" => \"value\"];\n     * $baz = new stdClass();\n     *\n     * echo (new \\Phalcon\\Debug\\Dump())->variables($foo, $bar, $baz);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 167,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 167,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 166,
                    "last-line": 185,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getStyle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 186,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "style",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 188,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 190,
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
                                        "value": "style",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 190,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 190,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "styles",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 190,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 190,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 190,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 190,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 190,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 190,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "color:gray",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 191,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 192,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 194,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "style",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 194,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 195,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get style for type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 187,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 187,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 186,
                    "last-line": 199,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "output",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "variable",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 200,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 200,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 200,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "tab",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "1",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 200,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 200,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 202,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 202,
                                    "char": 23
                                },
                                {
                                    "variable": "output",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 202,
                                    "char": 31
                                },
                                {
                                    "variable": "space",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 202,
                                    "char": 38
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 202,
                                    "char": 44
                                },
                                {
                                    "variable": "attr",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 202,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 204,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "space",
                                    "expr": {
                                        "type": "string",
                                        "value": "  ",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 204,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 204,
                                    "char": 23
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "output",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 205,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 205,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 207,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "name",
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 207,
                                "char": 17
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 208,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 208,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 208,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 208,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 209,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 211,
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
                                        "value": "variable",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 211,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 211,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 211,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 211,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strtr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "<b style =':style'>Array<\/b> (<span style =':style'>:count<\/span>) (\\n",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 213,
                                                            "char": 87
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 213,
                                                        "char": 87
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": ":style",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 215,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 215,
                                                                            "char": 34
                                                                        },
                                                                        "name": "getStyle",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "arr",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 215,
                                                                                    "char": 47
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 215,
                                                                                "char": 47
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 215,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 215,
                                                                    "char": 48
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": ":count",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 216,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "fcall",
                                                                        "name": "count",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "variable",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 216,
                                                                                    "char": 43
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 216,
                                                                                "char": 43
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 217,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 217,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 218,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 218,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 218,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 218,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 220,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "variable",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 220,
                                        "char": 40
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "output",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "str_repeat",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "space",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 221,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 221,
                                                                    "char": 46
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "tab",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 221,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 221,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 221,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "strtr",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "[<span style=':style'>:key<\/span>] => ",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 221,
                                                                        "char": 99
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 221,
                                                                    "char": 99
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "array",
                                                                        "left": [
                                                                            {
                                                                                "key": {
                                                                                    "type": "string",
                                                                                    "value": ":style",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 221,
                                                                                    "char": 108
                                                                                },
                                                                                "value": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 221,
                                                                                        "char": 115
                                                                                    },
                                                                                    "name": "getStyle",
                                                                                    "call-type": 1,
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "string",
                                                                                                "value": "arr",
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 221,
                                                                                                "char": 128
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 221,
                                                                                            "char": 128
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 221,
                                                                                    "char": 129
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 221,
                                                                                "char": 129
                                                                            },
                                                                            {
                                                                                "key": {
                                                                                    "type": "string",
                                                                                    "value": ":key",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 221,
                                                                                    "char": 135
                                                                                },
                                                                                "value": {
                                                                                    "type": "variable",
                                                                                    "value": "key",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 221,
                                                                                    "char": 140
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 221,
                                                                                "char": 140
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 221,
                                                                        "char": 141
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 221,
                                                                    "char": 141
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 221,
                                                            "char": 142
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 221,
                                                        "char": 142
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 221,
                                                    "char": 142
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 223,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "and",
                                                    "left": {
                                                        "type": "and",
                                                        "left": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "tab",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 223,
                                                                "char": 25
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 223,
                                                                "char": 30
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 223,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "not-equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 223,
                                                                "char": 38
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 223,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 223,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 223,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "is_int",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "key",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 223,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 223,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 223,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 223,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 223,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 223,
                                                        "char": 66
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 223,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 223,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 223,
                                                "char": 72
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 225,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 227,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "output",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 227,
                                                                "char": 35
                                                            },
                                                            "name": "output",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 227,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 227,
                                                                    "char": 48
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 227,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 227,
                                                                    "char": 50
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "add",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "tab",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 227,
                                                                            "char": 56
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "1",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 227,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 227,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 227,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 227,
                                                            "char": 61
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "\\n",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 227,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 227,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 227,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 228,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 230,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "variable",
                                                "value": "output",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 230,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "str_repeat",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "space",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 230,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 230,
                                                        "char": 45
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "sub",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "tab",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 230,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 230,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 230,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 230,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 230,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 230,
                                            "char": 56
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 230,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 230,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 231,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 233,
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
                                        "value": "variable",
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 233,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 233,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 233,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 233,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strtr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "<b style=':style'>Object<\/b> :class",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 235,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 235,
                                                        "char": 52
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": ":style",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 237,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 237,
                                                                            "char": 34
                                                                        },
                                                                        "name": "getStyle",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "obj",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 237,
                                                                                    "char": 47
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 237,
                                                                                "char": 47
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 237,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 237,
                                                                    "char": 48
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": ":class",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 238,
                                                                        "char": 27
                                                                    },
                                                                    "value": {
                                                                        "type": "fcall",
                                                                        "name": "get_class",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "variable",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 238,
                                                                                    "char": 47
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 238,
                                                                                "char": 47
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 239,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 239,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 240,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 240,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 240,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 240,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 242,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_parent_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "variable",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 242,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 242,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 242,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "output",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "strtr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": " <b style=':style'>extends<\/b> :parent",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 244,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 244,
                                                                "char": 59
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array",
                                                                    "left": [
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": ":style",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 246,
                                                                                "char": 31
                                                                            },
                                                                            "value": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 246,
                                                                                    "char": 38
                                                                                },
                                                                                "name": "getStyle",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "obj",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 246,
                                                                                            "char": 51
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 246,
                                                                                        "char": 51
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 246,
                                                                                "char": 52
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 246,
                                                                            "char": 52
                                                                        },
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": ":parent",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 247,
                                                                                "char": 32
                                                                            },
                                                                            "value": {
                                                                                "type": "fcall",
                                                                                "name": "get_parent_class",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "variable",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 247,
                                                                                            "char": 59
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 247,
                                                                                        "char": 59
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 248,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 248,
                                                                            "char": 21
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 249,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 249,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 249,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 249,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 250,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 251,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "string",
                                                "value": " (\\n",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 251,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 251,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 253,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 253,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "Di",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 253,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 253,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "output",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "str_repeat",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "space",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 255,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 255,
                                                                    "char": 46
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "tab",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 255,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 255,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 255,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "[skipped]\\n",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 255,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 255,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 255,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 256,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "or",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 256,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "detailed",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 256,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 256,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 256,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "instanceof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "variable",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 256,
                                                        "char": 59
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "stdClass",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 256,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 256,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 256,
                                                "char": 70
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "get_object_vars",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "variable",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 258,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 258,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 258,
                                                        "char": 61
                                                    },
                                                    "key": "key",
                                                    "value": "value",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "output",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "fcall",
                                                                            "name": "str_repeat",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "space",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 259,
                                                                                        "char": 50
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 259,
                                                                                    "char": 50
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "tab",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 259,
                                                                                        "char": 55
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 259,
                                                                                    "char": 55
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 259,
                                                                            "char": 57
                                                                        },
                                                                        "right": {
                                                                            "type": "fcall",
                                                                            "name": "strtr",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "-><span style=':style'>:key<\/span> (<span style=':style'>:type<\/span>) = ",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 259,
                                                                                        "char": 138
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 259,
                                                                                    "char": 138
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "array",
                                                                                        "left": [
                                                                                            {
                                                                                                "key": {
                                                                                                    "type": "string",
                                                                                                    "value": ":style",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 259,
                                                                                                    "char": 147
                                                                                                },
                                                                                                "value": {
                                                                                                    "type": "mcall",
                                                                                                    "variable": {
                                                                                                        "type": "variable",
                                                                                                        "value": "this",
                                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                        "line": 259,
                                                                                                        "char": 154
                                                                                                    },
                                                                                                    "name": "getStyle",
                                                                                                    "call-type": 1,
                                                                                                    "parameters": [
                                                                                                        {
                                                                                                            "parameter": {
                                                                                                                "type": "string",
                                                                                                                "value": "obj",
                                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                                "line": 259,
                                                                                                                "char": 167
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                            "line": 259,
                                                                                                            "char": 167
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 259,
                                                                                                    "char": 168
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 259,
                                                                                                "char": 168
                                                                                            },
                                                                                            {
                                                                                                "key": {
                                                                                                    "type": "string",
                                                                                                    "value": ":key",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 259,
                                                                                                    "char": 174
                                                                                                },
                                                                                                "value": {
                                                                                                    "type": "variable",
                                                                                                    "value": "key",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 259,
                                                                                                    "char": 179
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 259,
                                                                                                "char": 179
                                                                                            },
                                                                                            {
                                                                                                "key": {
                                                                                                    "type": "string",
                                                                                                    "value": ":type",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 259,
                                                                                                    "char": 186
                                                                                                },
                                                                                                "value": {
                                                                                                    "type": "string",
                                                                                                    "value": "public",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 259,
                                                                                                    "char": 194
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 259,
                                                                                                "char": 194
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 259,
                                                                                        "char": 195
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 259,
                                                                                    "char": 195
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 259,
                                                                            "char": 196
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 259,
                                                                        "char": 196
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 259,
                                                                    "char": 196
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 260,
                                                            "char": 23
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "output",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 260,
                                                                                "char": 39
                                                                            },
                                                                            "name": "output",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 260,
                                                                                        "char": 52
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 260,
                                                                                    "char": 52
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 260,
                                                                                        "char": 54
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 260,
                                                                                    "char": 54
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "add",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "tab",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 260,
                                                                                            "char": 60
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "int",
                                                                                            "value": "1",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 260,
                                                                                            "char": 63
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 260,
                                                                                        "char": 63
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 260,
                                                                                    "char": 63
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 260,
                                                                            "char": 65
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "\\n",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 260,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 260,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 260,
                                                                    "char": 69
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 261,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 262,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 262,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "declare",
                                            "data-type": "variable",
                                            "variables": [
                                                {
                                                    "variable": "reflect",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 264,
                                                    "char": 28
                                                },
                                                {
                                                    "variable": "props",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 264,
                                                    "char": 35
                                                },
                                                {
                                                    "variable": "property",
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 264,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 266,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "reflect",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "ReflectionClass",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "variable",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 266,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 266,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 266,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 266,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 267,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "props",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "reflect",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 267,
                                                            "char": 37
                                                        },
                                                        "name": "getProperties",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "bitwise_or",
                                                                    "left": {
                                                                        "type": "bitwise_or",
                                                                        "left": {
                                                                            "type": "static-constant-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "ReflectionProperty",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 268,
                                                                                "char": 51
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "IS_PUBLIC",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 268,
                                                                                "char": 51
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 268,
                                                                            "char": 51
                                                                        },
                                                                        "right": {
                                                                            "type": "static-constant-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "ReflectionProperty",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 269,
                                                                                "char": 54
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "IS_PROTECTED",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 269,
                                                                                "char": 54
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 269,
                                                                            "char": 54
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 269,
                                                                        "char": 54
                                                                    },
                                                                    "right": {
                                                                        "type": "static-constant-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "ReflectionProperty",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 271,
                                                                            "char": 17
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "IS_PRIVATE",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 271,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 271,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 271,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 271,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 271,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 271,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 273,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "props",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 273,
                                                "char": 39
                                            },
                                            "value": "property",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "property",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 274,
                                                            "char": 30
                                                        },
                                                        "name": "setAccessible",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 274,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 274,
                                                                "char": 49
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 274,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 276,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "key",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "property",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 276,
                                                                    "char": 40
                                                                },
                                                                "name": "getName",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 276,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 276,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 278,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "type",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "implode",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": " ",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 279,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 279,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "scall",
                                                                            "dynamic-class": 0,
                                                                            "class": "Reflection",
                                                                            "dynamic": 0,
                                                                            "name": "getModifierNames",
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "mcall",
                                                                                        "variable": {
                                                                                            "type": "variable",
                                                                                            "value": "property",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 281,
                                                                                            "char": 38
                                                                                        },
                                                                                        "name": "getModifiers",
                                                                                        "call-type": 1,
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 282,
                                                                                        "char": 25
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 282,
                                                                                    "char": 25
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 283,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 283,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 283,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 283,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 285,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "output",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "str_repeat",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "space",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 285,
                                                                                "char": 50
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 285,
                                                                            "char": 50
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "tab",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 285,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 285,
                                                                            "char": 55
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 285,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "strtr",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "-><span style=':style'>:key<\/span> (<span style=':style'>:type<\/span>) = ",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 285,
                                                                                "char": 138
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 285,
                                                                            "char": 138
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "array",
                                                                                "left": [
                                                                                    {
                                                                                        "key": {
                                                                                            "type": "string",
                                                                                            "value": ":style",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 285,
                                                                                            "char": 147
                                                                                        },
                                                                                        "value": {
                                                                                            "type": "mcall",
                                                                                            "variable": {
                                                                                                "type": "variable",
                                                                                                "value": "this",
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 285,
                                                                                                "char": 154
                                                                                            },
                                                                                            "name": "getStyle",
                                                                                            "call-type": 1,
                                                                                            "parameters": [
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "string",
                                                                                                        "value": "obj",
                                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                        "line": 285,
                                                                                                        "char": 167
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 285,
                                                                                                    "char": 167
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 285,
                                                                                            "char": 168
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 285,
                                                                                        "char": 168
                                                                                    },
                                                                                    {
                                                                                        "key": {
                                                                                            "type": "string",
                                                                                            "value": ":key",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 285,
                                                                                            "char": 174
                                                                                        },
                                                                                        "value": {
                                                                                            "type": "variable",
                                                                                            "value": "key",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 285,
                                                                                            "char": 179
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 285,
                                                                                        "char": 179
                                                                                    },
                                                                                    {
                                                                                        "key": {
                                                                                            "type": "string",
                                                                                            "value": ":type",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 285,
                                                                                            "char": 186
                                                                                        },
                                                                                        "value": {
                                                                                            "type": "variable",
                                                                                            "value": "type",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 285,
                                                                                            "char": 192
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 285,
                                                                                        "char": 192
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 285,
                                                                                "char": 193
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 285,
                                                                            "char": 193
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 285,
                                                                    "char": 194
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 285,
                                                                "char": 194
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 285,
                                                            "char": 194
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 286,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "output",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 286,
                                                                        "char": 39
                                                                    },
                                                                    "name": "output",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "property",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 286,
                                                                                    "char": 56
                                                                                },
                                                                                "name": "getValue",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "variable",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 286,
                                                                                            "char": 74
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 286,
                                                                                        "char": 74
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 286,
                                                                                "char": 75
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 286,
                                                                            "char": 75
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 286,
                                                                                "char": 77
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 286,
                                                                            "char": 77
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "add",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "tab",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 286,
                                                                                    "char": 83
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "1",
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 286,
                                                                                    "char": 86
                                                                                },
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 286,
                                                                                "char": 86
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 286,
                                                                            "char": 86
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 286,
                                                                    "char": 88
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "\\n",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 286,
                                                                    "char": 92
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 286,
                                                                "char": 92
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 286,
                                                            "char": 92
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 287,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 288,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 290,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "attr",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "get_class_methods",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "variable",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 290,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 290,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 290,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 290,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 291,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "str_repeat",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "space",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 291,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 291,
                                                            "char": 42
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "tab",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 291,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 291,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 291,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "strtr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": ":class <b style=':style'>methods<\/b>: (<span style=':style'>:count<\/span>) (\\n",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 291,
                                                                "char": 135
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 291,
                                                            "char": 135
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "key": {
                                                                            "type": "string",
                                                                            "value": ":style",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 291,
                                                                            "char": 144
                                                                        },
                                                                        "value": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 291,
                                                                                "char": 151
                                                                            },
                                                                            "name": "getStyle",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "obj",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 291,
                                                                                        "char": 164
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 291,
                                                                                    "char": 164
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 291,
                                                                            "char": 165
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 291,
                                                                        "char": 165
                                                                    },
                                                                    {
                                                                        "key": {
                                                                            "type": "string",
                                                                            "value": ":class",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 291,
                                                                            "char": 173
                                                                        },
                                                                        "value": {
                                                                            "type": "fcall",
                                                                            "name": "get_class",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "variable",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 291,
                                                                                        "char": 193
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 291,
                                                                                    "char": 193
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 291,
                                                                            "char": 194
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 291,
                                                                        "char": 194
                                                                    },
                                                                    {
                                                                        "key": {
                                                                            "type": "string",
                                                                            "value": ":count",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 291,
                                                                            "char": 202
                                                                        },
                                                                        "value": {
                                                                            "type": "fcall",
                                                                            "name": "count",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "attr",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 291,
                                                                                        "char": 214
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 291,
                                                                                    "char": 214
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 291,
                                                                            "char": 215
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 291,
                                                                        "char": 215
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 291,
                                                                "char": 216
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 291,
                                                            "char": 216
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 291,
                                                    "char": 217
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 291,
                                                "char": 217
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 291,
                                            "char": 217
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 293,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "in_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "get_class",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "variable",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 293,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 293,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 293,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 293,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 293,
                                                        "char": 51
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "methods",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 293,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 293,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 293,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 293,
                                        "char": 61
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "output",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "str_repeat",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "space",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 294,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 294,
                                                                    "char": 46
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "tab",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 294,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 294,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 294,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "[already listed]\\n",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 294,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 294,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 294,
                                                    "char": 73
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 295,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "attr",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 296,
                                                "char": 35
                                            },
                                            "value": "value",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-append",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "methods",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "get_class",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "variable",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 297,
                                                                            "char": 61
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 297,
                                                                        "char": 61
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 297,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 297,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 299,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 299,
                                                            "char": 31
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "__construct",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 299,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 299,
                                                        "char": 45
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "output",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "fcall",
                                                                            "name": "str_repeat",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "space",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 300,
                                                                                        "char": 54
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 300,
                                                                                    "char": 54
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "add",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "tab",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 300,
                                                                                            "char": 60
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "int",
                                                                                            "value": "1",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 300,
                                                                                            "char": 63
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 300,
                                                                                        "char": 63
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 300,
                                                                                    "char": 63
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 300,
                                                                            "char": 65
                                                                        },
                                                                        "right": {
                                                                            "type": "fcall",
                                                                            "name": "strtr",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "-><span style=':style'>:method<\/span>(); [<b style=':style'>constructor<\/b>]\\n",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 300,
                                                                                        "char": 151
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 300,
                                                                                    "char": 151
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "array",
                                                                                        "left": [
                                                                                            {
                                                                                                "key": {
                                                                                                    "type": "string",
                                                                                                    "value": ":style",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 300,
                                                                                                    "char": 160
                                                                                                },
                                                                                                "value": {
                                                                                                    "type": "mcall",
                                                                                                    "variable": {
                                                                                                        "type": "variable",
                                                                                                        "value": "this",
                                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                        "line": 300,
                                                                                                        "char": 167
                                                                                                    },
                                                                                                    "name": "getStyle",
                                                                                                    "call-type": 1,
                                                                                                    "parameters": [
                                                                                                        {
                                                                                                            "parameter": {
                                                                                                                "type": "string",
                                                                                                                "value": "obj",
                                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                                "line": 300,
                                                                                                                "char": 180
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                            "line": 300,
                                                                                                            "char": 180
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 300,
                                                                                                    "char": 181
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 300,
                                                                                                "char": 181
                                                                                            },
                                                                                            {
                                                                                                "key": {
                                                                                                    "type": "string",
                                                                                                    "value": ":method",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 300,
                                                                                                    "char": 190
                                                                                                },
                                                                                                "value": {
                                                                                                    "type": "variable",
                                                                                                    "value": "value",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 300,
                                                                                                    "char": 197
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 300,
                                                                                                "char": 197
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 300,
                                                                                        "char": 198
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 300,
                                                                                    "char": 198
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 300,
                                                                            "char": 199
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 300,
                                                                        "char": 199
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 300,
                                                                    "char": 199
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 301,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "output",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "fcall",
                                                                            "name": "str_repeat",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "space",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 302,
                                                                                        "char": 54
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 302,
                                                                                    "char": 54
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "add",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "tab",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 302,
                                                                                            "char": 60
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "int",
                                                                                            "value": "1",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 302,
                                                                                            "char": 63
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 302,
                                                                                        "char": 63
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 302,
                                                                                    "char": 63
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 302,
                                                                            "char": 65
                                                                        },
                                                                        "right": {
                                                                            "type": "fcall",
                                                                            "name": "strtr",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "-><span style=':style'>:method<\/span>();\\n",
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 302,
                                                                                        "char": 115
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 302,
                                                                                    "char": 115
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "array",
                                                                                        "left": [
                                                                                            {
                                                                                                "key": {
                                                                                                    "type": "string",
                                                                                                    "value": ":style",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 302,
                                                                                                    "char": 124
                                                                                                },
                                                                                                "value": {
                                                                                                    "type": "mcall",
                                                                                                    "variable": {
                                                                                                        "type": "variable",
                                                                                                        "value": "this",
                                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                        "line": 302,
                                                                                                        "char": 131
                                                                                                    },
                                                                                                    "name": "getStyle",
                                                                                                    "call-type": 1,
                                                                                                    "parameters": [
                                                                                                        {
                                                                                                            "parameter": {
                                                                                                                "type": "string",
                                                                                                                "value": "obj",
                                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                                "line": 302,
                                                                                                                "char": 144
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                            "line": 302,
                                                                                                            "char": 144
                                                                                                        }
                                                                                                    ],
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 302,
                                                                                                    "char": 145
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 302,
                                                                                                "char": 145
                                                                                            },
                                                                                            {
                                                                                                "key": {
                                                                                                    "type": "string",
                                                                                                    "value": ":method",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 302,
                                                                                                    "char": 154
                                                                                                },
                                                                                                "value": {
                                                                                                    "type": "variable",
                                                                                                    "value": "value",
                                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                    "line": 302,
                                                                                                    "char": 161
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                                "line": 302,
                                                                                                "char": 161
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 302,
                                                                                        "char": 162
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                    "line": 302,
                                                                                    "char": 162
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 302,
                                                                            "char": 163
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 302,
                                                                        "char": 163
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 302,
                                                                    "char": 163
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 303,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 304,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 306,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "output",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "str_repeat",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "space",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 306,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 306,
                                                                    "char": 46
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "tab",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 306,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 306,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 306,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ")\\n",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 306,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 306,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 306,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 307,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 309,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "variable",
                                                "value": "output",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 309,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "str_repeat",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "space",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 309,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 309,
                                                        "char": 45
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "sub",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "tab",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 309,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 309,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 309,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 309,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 309,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 309,
                                            "char": 56
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 309,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 309,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 310,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 312,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_int",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 312,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 312,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 312,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "output",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 313,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "<b style=':style'>Integer<\/b> (<span style=':style'>:var<\/span>)",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 313,
                                                        "char": 99
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 313,
                                                    "char": 99
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":style",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 313,
                                                                    "char": 108
                                                                },
                                                                "value": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 313,
                                                                        "char": 115
                                                                    },
                                                                    "name": "getStyle",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "int",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 313,
                                                                                "char": 128
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 313,
                                                                            "char": 128
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 313,
                                                                    "char": 129
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 313,
                                                                "char": 129
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":var",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 313,
                                                                    "char": 135
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "variable",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 313,
                                                                    "char": 145
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 313,
                                                                "char": 145
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 313,
                                                        "char": 146
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 313,
                                                    "char": 146
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 313,
                                            "char": 147
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 313,
                                        "char": 147
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 314,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 316,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_float",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 316,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 316,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 316,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "output",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 317,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "<b style=':style'>Float<\/b> (<span style=':style'>:var<\/span>)",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 317,
                                                        "char": 97
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 317,
                                                    "char": 97
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":style",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 317,
                                                                    "char": 106
                                                                },
                                                                "value": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 317,
                                                                        "char": 113
                                                                    },
                                                                    "name": "getStyle",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "float",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 317,
                                                                                "char": 128
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 317,
                                                                            "char": 128
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 317,
                                                                    "char": 129
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 317,
                                                                "char": 129
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":var",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 317,
                                                                    "char": 135
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "variable",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 317,
                                                                    "char": 145
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 317,
                                                                "char": 145
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 317,
                                                        "char": 146
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 317,
                                                    "char": 146
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 317,
                                            "char": 147
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 317,
                                        "char": 147
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 318,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 320,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_numeric",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 320,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 320,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 320,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "output",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 321,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "<b style=':style'>Numeric string<\/b> (<span style=':style'>:length<\/span>) \\\"<span style=':style'>:var<\/span>\\\"",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 321,
                                                        "char": 146
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 321,
                                                    "char": 146
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":style",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 321,
                                                                    "char": 155
                                                                },
                                                                "value": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 321,
                                                                        "char": 162
                                                                    },
                                                                    "name": "getStyle",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "num",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 321,
                                                                                "char": 175
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 321,
                                                                            "char": 175
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 321,
                                                                    "char": 176
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 321,
                                                                "char": 176
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":length",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 321,
                                                                    "char": 185
                                                                },
                                                                "value": {
                                                                    "type": "fcall",
                                                                    "name": "strlen",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "variable",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 321,
                                                                                "char": 202
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 321,
                                                                            "char": 202
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 321,
                                                                    "char": 203
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 321,
                                                                "char": 203
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":var",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 321,
                                                                    "char": 209
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "variable",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 321,
                                                                    "char": 219
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 321,
                                                                "char": 219
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 321,
                                                        "char": 220
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 321,
                                                    "char": 220
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 321,
                                            "char": 221
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 321,
                                        "char": 221
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 322,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 324,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_string",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 324,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 324,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 324,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "output",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 325,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "<b style=':style'>String<\/b> (<span style=':style'>:length<\/span>) \\\"<span style=':style'>:var<\/span>\\\"",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 325,
                                                        "char": 138
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 325,
                                                    "char": 138
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":style",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 325,
                                                                    "char": 147
                                                                },
                                                                "value": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 325,
                                                                        "char": 154
                                                                    },
                                                                    "name": "getStyle",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "str",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 325,
                                                                                "char": 167
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 325,
                                                                            "char": 167
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 325,
                                                                    "char": 168
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 325,
                                                                "char": 168
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":length",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 325,
                                                                    "char": 177
                                                                },
                                                                "value": {
                                                                    "type": "fcall",
                                                                    "name": "strlen",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "variable",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 325,
                                                                                "char": 194
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 325,
                                                                            "char": 194
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 325,
                                                                    "char": 195
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 325,
                                                                "char": 195
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":var",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 325,
                                                                    "char": 201
                                                                },
                                                                "value": {
                                                                    "type": "fcall",
                                                                    "name": "nl2br",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "fcall",
                                                                                "name": "htmlentities",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "variable",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 325,
                                                                                            "char": 230
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 325,
                                                                                        "char": 230
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "constant",
                                                                                            "value": "ENT_IGNORE",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 325,
                                                                                            "char": 242
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 325,
                                                                                        "char": 242
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "utf-8",
                                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                            "line": 325,
                                                                                            "char": 249
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                        "line": 325,
                                                                                        "char": 249
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 325,
                                                                                "char": 250
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 325,
                                                                            "char": 250
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 325,
                                                                    "char": 251
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 325,
                                                                "char": 251
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 325,
                                                        "char": 252
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 325,
                                                    "char": 252
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 325,
                                            "char": 253
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 325,
                                        "char": 253
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 326,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 328,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_bool",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 328,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 328,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 328,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "output",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 329,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "<b style=':style'>Boolean<\/b> (<span style=':style'>:var<\/span>)",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 329,
                                                        "char": 99
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 329,
                                                    "char": 99
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":style",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 329,
                                                                    "char": 108
                                                                },
                                                                "value": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 329,
                                                                        "char": 115
                                                                    },
                                                                    "name": "getStyle",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "bool",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 329,
                                                                                "char": 129
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 329,
                                                                            "char": 129
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 329,
                                                                    "char": 130
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 329,
                                                                "char": 130
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":var",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 329,
                                                                    "char": 136
                                                                },
                                                                "value": {
                                                                    "type": "list",
                                                                    "left": {
                                                                        "type": "ternary",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "variable",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 329,
                                                                            "char": 148
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "TRUE",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 329,
                                                                            "char": 155
                                                                        },
                                                                        "extra": {
                                                                            "type": "string",
                                                                            "value": "FALSE",
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 329,
                                                                            "char": 162
                                                                        },
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 329,
                                                                        "char": 162
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 329,
                                                                    "char": 163
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 329,
                                                                "char": 163
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 329,
                                                        "char": 164
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 329,
                                                    "char": 164
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 329,
                                            "char": 165
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 329,
                                        "char": 165
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 330,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 332,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_null",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "variable",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 332,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 332,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 332,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "output",
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 333,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "<b style=':style'>NULL<\/b>",
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 333,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 333,
                                                    "char": 61
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ":style",
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 333,
                                                                    "char": 70
                                                                },
                                                                "value": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 333,
                                                                        "char": 77
                                                                    },
                                                                    "name": "getStyle",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "null",
                                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                                "line": 333,
                                                                                "char": 91
                                                                            },
                                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                            "line": 333,
                                                                            "char": 91
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 333,
                                                                    "char": 92
                                                                },
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 333,
                                                                "char": 92
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 333,
                                                        "char": 93
                                                    },
                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                    "line": 333,
                                                    "char": 93
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 333,
                                            "char": 94
                                        },
                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                        "line": 333,
                                        "char": 94
                                    },
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 334,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 336,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "output",
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 336,
                                    "char": 23
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "strtr",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "(<span style=':style'>:var<\/span>)",
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 336,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 336,
                                            "char": 65
                                        },
                                        {
                                            "parameter": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": ":style",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 336,
                                                            "char": 74
                                                        },
                                                        "value": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                "line": 336,
                                                                "char": 81
                                                            },
                                                            "name": "getStyle",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "other",
                                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                        "line": 336,
                                                                        "char": 96
                                                                    },
                                                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                                    "line": 336,
                                                                    "char": 96
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 336,
                                                            "char": 97
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 336,
                                                        "char": 97
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": ":var",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 336,
                                                            "char": 103
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "variable",
                                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                            "line": 336,
                                                            "char": 113
                                                        },
                                                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                        "line": 336,
                                                        "char": 113
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                                "line": 336,
                                                "char": 114
                                            },
                                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                            "line": 336,
                                            "char": 114
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                    "line": 336,
                                    "char": 115
                                },
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 336,
                                "char": 115
                            },
                            "file": "\/app\/phalcon\/Debug\/Dump.zep",
                            "line": 337,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepare an HTML string of information about a single variable.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Debug\/Dump.zep",
                                "line": 201,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Debug\/Dump.zep",
                        "line": 201,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Debug\/Dump.zep",
                    "line": 200,
                    "last-line": 338,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Debug\/Dump.zep",
            "line": 36,
            "char": 5
        },
        "file": "\/app\/phalcon\/Debug\/Dump.zep",
        "line": 36,
        "char": 5
    }
]