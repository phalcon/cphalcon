[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\View\\Engine",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Engine\\AbstractEngine",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                "line": 14,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Engine\\Volt\\Compiler",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                "line": 15,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Exception",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                "line": 16,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Designer friendly and fast template engine for PHP written in Zephir\/C\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "Volt",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractEngine",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "compiler",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 24,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "macros",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 25,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 29,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "callMacro",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 30,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 30,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 30,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "macro",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 32,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 34,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "macro",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 34,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 34,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "macros",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 34,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 34,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 34,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 34,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 34,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 34,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 34,
                                "char": 54
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
                                                            "value": "Macro '",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 35,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 35,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 35,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' does not exist",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 35,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 35,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 35,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 35,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 36,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 38,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "call_user_func",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "macro",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 38,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 38,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "arguments",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 38,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 38,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 38,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 39,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a macro is defined and calls it\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 31,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                        "line": 31,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 30,
                    "last-line": 43,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "convertEncoding",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 44,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "from",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 44,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "to",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 44,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "from",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 49,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "latin1",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 49,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 49,
                                    "char": 28
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "to",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 49,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "utf8",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 49,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 49,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 49,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "utf8_encode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 50,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 50,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 50,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 51,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 56,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "to",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 56,
                                        "char": 16
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "latin1",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 56,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 56,
                                    "char": 26
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "from",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 56,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "utf8",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 56,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 56,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 56,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "utf8_decode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 57,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 57,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 57,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 58,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 63,
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
                                            "value": "mb_convert_encoding",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 63,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 63,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 63,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_convert_encoding",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 64,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 64,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "from",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 64,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 64,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "to",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 64,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 64,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 64,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 65,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 70,
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
                                            "value": "iconv",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 70,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 70,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 70,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "iconv",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "from",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 71,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 71,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "to",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 71,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 71,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 71,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 71,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 71,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 72,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 77,
                            "char": 13
                        },
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
                                            "value": "Any of 'mbstring' or 'iconv' is required to perform the charset conversion",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 79,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 79,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 79,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 80,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Performs a string conversion\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 45,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                        "line": 45,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 44,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCompiler",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "compiler",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 87,
                                    "char": 21
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 87,
                                    "char": 32
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 87,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 89,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "compiler",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 89,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "compiler",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 89,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 89,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 89,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 91,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "compiler",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 91,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 91,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 91,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 91,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "compiler",
                                            "expr": {
                                                "type": "new",
                                                "class": "Compiler",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                "line": 92,
                                                                "char": 46
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "view",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                "line": 92,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 92,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 92,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 92,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 92,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 97,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "container",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "DiInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 97,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 97,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 97,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 97,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 97,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 97,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 99,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 99,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 99,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 99,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 99,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "compiler",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 100,
                                                    "char": 26
                                                },
                                                "name": "setDi",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 100,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 100,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 100,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 101,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 106,
                                    "char": 15
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
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 106,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 106,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 106,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 106,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 108,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 108,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 108,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 108,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 108,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "compiler",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 109,
                                                    "char": 26
                                                },
                                                "name": "setOptions",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 109,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 109,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 109,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 110,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 112,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "compiler",
                                            "expr": {
                                                "type": "variable",
                                                "value": "compiler",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 112,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 112,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 113,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 115,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "compiler",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 115,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 116,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the Volt's compiler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Compiler",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 86,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 86,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                        "line": 86,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 85,
                    "last-line": 120,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 123,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 123,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 123,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 124,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return Volt's options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 122,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                        "line": 122,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 121,
                    "last-line": 128,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isIncluded",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "needle",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 129,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "haystack",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 129,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "haystack",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 131,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 131,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 131,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 131,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "in_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "needle",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 132,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 132,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "haystack",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 132,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 132,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 132,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 133,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 135,
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
                                        "value": "haystack",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 135,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 135,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 135,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 135,
                                "char": 38
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
                                                    "value": "mb_strpos",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 136,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 136,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 136,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "mb_strpos",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "haystack",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                "line": 137,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 137,
                                                            "char": 42
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "needle",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                "line": 137,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 137,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 137,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 137,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 137,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 138,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 140,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strpos",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "haystack",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 140,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 140,
                                                    "char": 35
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "needle",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 140,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 140,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 140,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 140,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 140,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 141,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 143,
                            "char": 13
                        },
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
                                            "value": "Invalid haystack",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 143,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 143,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 143,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 144,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if the needle is included in the haystack\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 130,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                        "line": 130,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 129,
                    "last-line": 148,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "length",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "item",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 149,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "item",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 151,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 151,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 151,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 151,
                                    "char": 35
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "item",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 151,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 151,
                                        "char": 50
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 151,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 151,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 151,
                                "char": 58
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "item",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 152,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 152,
                                                "char": 30
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 152,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 153,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 155,
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
                                            "value": "mb_strlen",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 155,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 155,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 155,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "item",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 156,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 156,
                                                "char": 34
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 156,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 157,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 159,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "strlen",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "item",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 159,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 159,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 159,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 160,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Length filter. If an array\/object is passed a count is performed otherwise a strlen\/mb_strlen\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 150,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                        "line": 150,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 149,
                    "last-line": 164,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "templatePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 165,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 165,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "mustClean",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 165,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 165,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "compiler",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 167,
                                    "char": 21
                                },
                                {
                                    "variable": "compiledTemplatePath",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 167,
                                    "char": 43
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 167,
                                    "char": 58
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 167,
                                    "char": 63
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 167,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 169,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "mustClean",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 169,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "ob_clean",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 170,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 171,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 176,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "compiler",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 176,
                                            "char": 34
                                        },
                                        "name": "getCompiler",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 176,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 176,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 177,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 177,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 177,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 177,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 179,
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
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 179,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 179,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 179,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 179,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 180,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "view:beforeCompile",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 180,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 180,
                                                    "char": 54
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 180,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 180,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 180,
                                            "char": 64
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 180,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 180,
                                        "char": 72
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 181,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 182,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 183,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 185,
                            "char": 16
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "compiler",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 185,
                                    "char": 18
                                },
                                "name": "compile",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "templatePath",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 185,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 185,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 185,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 187,
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
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 187,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 187,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 187,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 187,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 188,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "view:afterCompile",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 188,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 188,
                                                    "char": 53
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 188,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 188,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 188,
                                            "char": 63
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 188,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 188,
                                        "char": 71
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 189,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 190,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 191,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 193,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "compiledTemplatePath",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "compiler",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 193,
                                            "char": 45
                                        },
                                        "name": "getCompiledTemplatePath",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 193,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 193,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 198,
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
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 198,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 198,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 198,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 198,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 199,
                                        "char": 38
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "dynamic-variable",
                                                    "operator": "assign",
                                                    "variable": "key",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 200,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 200,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 201,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 202,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 204,
                            "char": 15
                        },
                        {
                            "type": "require",
                            "expr": {
                                "type": "variable",
                                "value": "compiledTemplatePath",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 204,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 206,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "mustClean",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 206,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 207,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "view",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 207,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 207,
                                            "char": 24
                                        },
                                        "name": "setContent",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "ob_get_contents",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 207,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 207,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 207,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 208,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 209,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a view using the template engine\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 165,
                    "last-line": 213,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 214,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 216,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 216,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 217,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set Volt's options\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 214,
                    "last-line": 221,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "slice",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 222,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "start",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 222,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 222,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "end",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 222,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 222,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "length",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 224,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 225,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "slice",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 225,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 226,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 226,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 231,
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
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 231,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 231,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 231,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 231,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "end",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 232,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 232,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 232,
                                        "char": 29
                                    },
                                    "statements": [
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
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                        "line": 233,
                                                                        "char": 38
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                    "line": 233,
                                                                    "char": 38
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 233,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 233,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 233,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 233,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 234,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 236,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "position",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 236,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 236,
                                            "char": 29
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "slice",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 237,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 237,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 239,
                                    "char": 17
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 239,
                                            "char": 19
                                        },
                                        "name": "rewind",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 239,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 241,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 241,
                                            "char": 25
                                        },
                                        "name": "valid",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 241,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "greater-equal",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "position",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 242,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "start",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 242,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 242,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "less-equal",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "position",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 242,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "end",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 242,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 242,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 242,
                                                "char": 55
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "slice",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                    "line": 243,
                                                                    "char": 41
                                                                },
                                                                "name": "current",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                                "line": 243,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 243,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 244,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 246,
                                            "char": 21
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 246,
                                                    "char": 23
                                                },
                                                "name": "next",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 246,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 248,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "incr",
                                                    "variable": "position",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 248,
                                                    "char": 31
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 249,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 251,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "slice",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 251,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 252,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 257,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "end",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 257,
                                    "char": 18
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 257,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 257,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "length",
                                            "expr": {
                                                "type": "add",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "sub",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "end",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 258,
                                                            "char": 31
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "start",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 258,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 258,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 258,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 258,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 258,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 258,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 259,
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
                                            "variable": "length",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 260,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 260,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 261,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 266,
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
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 266,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 266,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 266,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 266,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_slice",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 267,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 267,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "start",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 267,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 267,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 267,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 267,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 267,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 268,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 273,
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
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 273,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 273,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 273,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "length",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 274,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 274,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 274,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "mb_substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 275,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 275,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "start",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 275,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 275,
                                                        "char": 46
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "length",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                            "line": 275,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                        "line": 275,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 275,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 276,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 278,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 278,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 278,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "start",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 278,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 278,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 278,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 279,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 284,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "length",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 284,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 284,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 284,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 285,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 285,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "start",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 285,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 285,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                    "line": 285,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                                "line": 285,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 285,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                    "line": 286,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 288,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "substr",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 288,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 288,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "start",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 288,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 288,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 288,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 289,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Extracts a slice from a string\/array\/traversable object value\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 222,
                    "last-line": 293,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sort",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 294,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "asort",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                            "line": 296,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                        "line": 296,
                                        "char": 20
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 296,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 298,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 298,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                            "line": 299,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sorts an array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                                "line": 295,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                        "line": 295,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
                    "line": 294,
                    "last-line": 300,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt.zep",
        "line": 21,
        "char": 5
    }
]