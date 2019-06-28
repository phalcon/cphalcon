[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate\\Adapter",
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Exception",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                "line": 15,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\InterpolatorFactory",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                "line": 16,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 35,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Translate\\Adapter\\Gettext\n *\n * ```php\n * use Phalcon\\Translate\\Adapter\\Gettext;\n *\n * $adapter = new Gettext(\n *     [\n *         \"locale\"        => \"de_DE.UTF-8\",\n *         \"defaultDomain\" => \"translations\",\n *         \"directory\"     => \"\/path\/to\/application\/locales\",\n *         \"category\"      => LC_MESSAGES,\n *     ]\n * );\n * ```\n *\n * Allows translate using gettext\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 36,
        "char": 5
    },
    {
        "type": "class",
        "name": "Gettext",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "implements": [
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                "line": 37,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "category",
                    "docblock": "**\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 41,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 45,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultDomain",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 46,
                            "char": 35
                        }
                    ],
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "directory",
                    "docblock": "**\n     * @var string|array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 51,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 55,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "locale",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 56,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 60,
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
                            "name": "interpolator",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "InterpolatorFactory",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 61,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 61,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 61,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "function_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "gettext",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 63,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 63,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 63,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 63,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 63,
                                "char": 47
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
                                                    "value": "This class requires the gettext extension for PHP",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 66,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 66,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 66,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 67,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 69,
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
                                            "value": "interpolator",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 69,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 69,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 69,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 69,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 69,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 71,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 71,
                                    "char": 14
                                },
                                "name": "prepareOptions",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 71,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 71,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 71,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 72,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Translate\\Adapter\\Gettext constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 62,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 61,
                    "last-line": 76,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "exists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 77,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 79,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 81,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 81,
                                            "char": 27
                                        },
                                        "name": "query",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 81,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 81,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 81,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 81,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 83,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 83,
                                    "char": 25
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "index",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 83,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 83,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether is defined a translation key in the internal array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 78,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 78,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 77,
                    "last-line": 90,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "nquery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "msgid1",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 91,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "msgid2",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 91,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "count",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 91,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 91,
                                "char": 91
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 91,
                            "char": 91
                        },
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 91,
                                "char": 114
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 91,
                            "char": 114
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "translation",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 93,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 95,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "domain",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 95,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 95,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "translation",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "ngettext",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "msgid1",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 96,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 96,
                                                        "char": 46
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "msgid2",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 96,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 96,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "count",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 96,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 96,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 96,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 96,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 97,
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
                                            "variable": "translation",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "dngettext",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "domain",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 98,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 98,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "msgid1",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 98,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 98,
                                                        "char": 55
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "msgid2",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 98,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 98,
                                                        "char": 63
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "count",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 98,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 98,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 98,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 98,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 99,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 101,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 101,
                                    "char": 21
                                },
                                "name": "replacePlaceholders",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translation",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 101,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 101,
                                        "char": 53
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 101,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 101,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 101,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 102,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * The plural version of gettext().\n     * Some languages have more than one form for plural messages dependent on\n     * the count.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 92,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 92,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 91,
                    "last-line": 112,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "query",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 113,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 113,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 113,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "translation",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 115,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 117,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "translation",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "gettext",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 117,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 117,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 117,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 117,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 119,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 119,
                                    "char": 21
                                },
                                "name": "replacePlaceholders",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translation",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 119,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 119,
                                        "char": 53
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 119,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 119,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 119,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 120,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the translation related to the given key.\n     *\n     * ```php\n     * $translator->query(\"\u4f60\u597d %name%\uff01\", [\"name\" => \"Phalcon\"]);\n     * ```\n     *\n     * @param array   placeholders\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 114,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 114,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 113,
                    "last-line": 124,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "resetDomain",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "textdomain",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 128,
                                                "char": 18
                                            },
                                            "name": "getDefaultDomain",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 129,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 129,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 129,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 130,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default domain\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 126,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 126,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 125,
                    "last-line": 134,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultDomain",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 135,
                            "char": 52
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
                                    "property": "defaultDomain",
                                    "expr": {
                                        "type": "variable",
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 137,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 137,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 138,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the domain default to search within when calls are made to gettext()\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 136,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 135,
                    "last-line": 157,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDirectory",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "directory",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 158,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 160,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 160,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 162,
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
                                        "value": "directory",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 162,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 162,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 162,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 164,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 166,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "directory",
                                    "expr": {
                                        "type": "variable",
                                        "value": "directory",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 166,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 166,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 168,
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
                                        "value": "directory",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 168,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 168,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 168,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 168,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "directory",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 169,
                                        "char": 41
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "bindtextdomain",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 170,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 170,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                            "line": 170,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 170,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 170,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 171,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 172,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "bindtextdomain",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 174,
                                                        "char": 22
                                                    },
                                                    "name": "getDefaultDomain",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 174,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 174,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "directory",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 176,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 176,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 176,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 177,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 178,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the path for a domain\n     *\n     * ```php\n     * \/\/ Set the directory path\n     * $gettext->setDirectory(\"\/path\/to\/the\/messages\");\n     *\n     * \/\/ Set the domains and directories path\n     * $gettext->setDirectory(\n     *     [\n     *         \"messages\" => \"\/path\/to\/the\/messages\",\n     *         \"another\"  => \"\/path\/to\/the\/another\",\n     *     ]\n     * );\n     * ```\n     *\n     * @param string|array directory The directory path or an array of directories and domains\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 158,
                    "last-line": 182,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDomain",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 183,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "textdomain",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 185,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 185,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 185,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Changes the current domain (i.e. the translation file)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 183,
                    "last-line": 198,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLocale",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "category",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 199,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "locale",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 199,
                            "char": 60
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
                                    "property": "locale",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "call_user_func_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "setlocale",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 202,
                                                    "char": 22
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 202,
                                                "char": 22
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "func_get_args",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 204,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 204,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 204,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 204,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 206,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "category",
                                    "expr": {
                                        "type": "variable",
                                        "value": "category",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 206,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 206,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 208,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "putenv",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "LC_ALL=",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 208,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 208,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "locale",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 208,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 208,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 208,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 208,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 208,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 209,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "putenv",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "LANG=",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 209,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 209,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "locale",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 209,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 209,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 209,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 209,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 209,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 210,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "putenv",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "LANGUAGE=",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 210,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 210,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "locale",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 210,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 210,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 210,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 210,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 210,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 211,
                            "char": 17
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "setlocale",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "constant",
                                            "value": "LC_ALL",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 211,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 211,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 211,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "locale",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 211,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 211,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 211,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 211,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 213,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 213,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "locale",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 213,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 213,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 214,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets locale information\n     *\n     * ```php\n     * \/\/ Set locale to Dutch\n     * $gettext->setLocale(LC_ALL, \"nl_NL\");\n     *\n     * \/\/ Try different possible locale names for german\n     * $gettext->setLocale(LC_ALL, \"de_DE@euro\", \"de_DE\", \"de\", \"ge\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 199,
                                "char": 72
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 200,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 200,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 199,
                    "last-line": 218,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getOptionsDefault",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "category",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 222,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "constant",
                                            "value": "LC_ALL",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 222,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 222,
                                        "char": 34
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "defaultDomain",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 223,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 224,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 224,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 224,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 225,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets default options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 220,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 220,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 219,
                    "last-line": 229,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 230,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 232,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "locale",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 232,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 232,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 232,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 232,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 232,
                                "char": 44
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
                                                    "value": "Parameter 'locale' is required",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 233,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 233,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 233,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 234,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 236,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 236,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "directory",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 236,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 236,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 236,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 236,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 236,
                                "char": 47
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
                                                    "value": "Parameter 'directory' is required",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 237,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 237,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 237,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 238,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 240,
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
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                        "line": 241,
                                                        "char": 18
                                                    },
                                                    "name": "getOptionsDefault",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 241,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 241,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                    "line": 243,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 243,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 243,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 243,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 245,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 245,
                                    "char": 14
                                },
                                "name": "setLocale",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 246,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "category",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 246,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 246,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 246,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 247,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "locale",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 247,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 248,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 248,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 248,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 250,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 250,
                                    "char": 14
                                },
                                "name": "setDefaultDomain",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 251,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "defaultDomain",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 251,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 252,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 252,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 252,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 254,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 254,
                                    "char": 14
                                },
                                "name": "setDirectory",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 255,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "directory",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 255,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 256,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 256,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 256,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 258,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                    "line": 258,
                                    "char": 14
                                },
                                "name": "setDomain",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 259,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "defaultDomain",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                                "line": 259,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                            "line": 260,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                        "line": 260,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                                "line": 260,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                            "line": 261,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Validator for constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                        "line": 231,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
                    "line": 230,
                    "last-line": 262,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
            "line": 36,
            "char": 5
        },
        "file": "\/app\/phalcon\/Translate\/Adapter\/Gettext.zep",
        "line": 36,
        "char": 5
    }
]