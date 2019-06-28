[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Escaper.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Escaper.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\EscaperInterface",
                "file": "\/app\/phalcon\/Escaper.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Escaper.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Escaper\\Exception",
                "file": "\/app\/phalcon\/Escaper.zep",
                "line": 14,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Escaper.zep",
        "line": 32,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Escaper\n *\n * Escapes different kinds of text securing them. By using this component you\n * may prevent XSS attacks.\n *\n * This component only works with UTF-8. The PREG extension needs to be compiled\n * with UTF-8 support.\n *\n *```php\n * $escaper = new \\Phalcon\\Escaper();\n *\n * $escaped = $escaper->escapeCss(\"font-family: <Verdana>\");\n *\n * echo $escaped; \/\/ font\\2D family\\3A \\20 \\3C Verdana\\3E\n *```\n *",
        "file": "\/app\/phalcon\/Escaper.zep",
        "line": 33,
        "char": 5
    },
    {
        "type": "class",
        "name": "Escaper",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "EscaperInterface",
                "file": "\/app\/phalcon\/Escaper.zep",
                "line": 34,
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
                    "name": "doubleEncode",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 38,
                        "char": 34
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 42,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "encoding",
                    "default": {
                        "type": "string",
                        "value": "utf-8",
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 43,
                        "char": 31
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 45,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "htmlEscapeMap",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 45,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 47,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "htmlQuoteType",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 47,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 53,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "detectEncoding",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "str",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 54,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "charset",
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 56,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 61,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "charset",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "phalcon_is_basic_charset",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "str",
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 61,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 61,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 61,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 61,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 63,
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
                                        "value": "charset",
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 63,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 63,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 63,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 63,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "charset",
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 64,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 65,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 70,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "function_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "mb_detect_encoding",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 70,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 70,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 70,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 70,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 71,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 72,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 78,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "string",
                                            "value": "UTF-32",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 78,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 78,
                                        "char": 31
                                    },
                                    {
                                        "value": {
                                            "type": "string",
                                            "value": "UTF-8",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 78,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 78,
                                        "char": 38
                                    },
                                    {
                                        "value": {
                                            "type": "string",
                                            "value": "ISO-8859-1",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 78,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 78,
                                        "char": 50
                                    },
                                    {
                                        "value": {
                                            "type": "string",
                                            "value": "ASCII",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 78,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 78,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 78,
                                "char": 59
                            },
                            "value": "charset",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_detect_encoding",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "str",
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 79,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 79,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "charset",
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 79,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 79,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 79,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 79,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 79,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "charset",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 80,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 81,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 87,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "mb_detect_encoding",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "str",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 87,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 87,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 87,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 88,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Detect the character encoding of a string to be handled by an encoder.\n     * Special-handling for chr(172) and chr(128) to chr(159) which fail to be\n     * detected by mb_detect_encoding()\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 54,
                                "char": 64
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 55,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 55,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 54,
                    "last-line": 93,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeCss",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "css",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 94,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "phalcon_escape_css",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 101,
                                                "char": 18
                                            },
                                            "name": "normalizeEncoding",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "css",
                                                        "file": "\/app\/phalcon\/Escaper.zep",
                                                        "line": 101,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 101,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 102,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 102,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 102,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escape CSS strings by replacing non-alphanumeric chars by their\n     * hexadecimal escaped representation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 95,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 95,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 94,
                    "last-line": 108,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeJs",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "js",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 109,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "phalcon_escape_js",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 116,
                                                "char": 18
                                            },
                                            "name": "normalizeEncoding",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "js",
                                                        "file": "\/app\/phalcon\/Escaper.zep",
                                                        "line": 116,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 116,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 117,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 117,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 117,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escape javascript strings by replacing non-alphanumeric chars by their\n     * hexadecimal escaped representation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 110,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 110,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 109,
                    "last-line": 122,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeHtml",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 123,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "htmlspecialchars",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 126,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 126,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 127,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "htmlQuoteType",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 127,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 127,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 127,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 128,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "encoding",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 128,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 128,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 128,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 129,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "doubleEncode",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 130,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 130,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 130,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 130,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 131,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escapes a HTML string. Internally uses htmlspecialchars\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 124,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 124,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 123,
                    "last-line": 135,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeHtmlAttr",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 136,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "htmlspecialchars",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attribute",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 139,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 139,
                                        "char": 22
                                    },
                                    {
                                        "parameter": {
                                            "type": "constant",
                                            "value": "ENT_QUOTES",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 140,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 140,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 141,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "encoding",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 141,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 141,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 141,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 142,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "doubleEncode",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 143,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 143,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 143,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 143,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 144,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escapes a HTML attribute string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 137,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 137,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 136,
                    "last-line": 148,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeUrl",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "url",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 149,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "rawurlencode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "url",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 151,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 151,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 151,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 152,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escapes a URL. Internally uses rawurlencode\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 150,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 150,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 149,
                    "last-line": 156,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEncoding",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 159,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "encoding",
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 159,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 159,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 160,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal encoding used by the escaper\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 158,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 158,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 157,
                    "last-line": 164,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "normalizeEncoding",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "str",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 165,
                            "char": 55
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
                                                    "value": "mb_convert_encoding",
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 170,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 170,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 170,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 170,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 170,
                                "char": 59
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
                                                    "value": "Extension 'mbstring' is required",
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 171,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 171,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 171,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 172,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 178,
                            "char": 14
                        },
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
                                            "value": "str",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 179,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 179,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "UTF-32",
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 180,
                                            "char": 19
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 180,
                                        "char": 19
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Escaper.zep",
                                                "line": 181,
                                                "char": 18
                                            },
                                            "name": "detectEncoding",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "str",
                                                        "file": "\/app\/phalcon\/Escaper.zep",
                                                        "line": 181,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Escaper.zep",
                                                    "line": 181,
                                                    "char": 37
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Escaper.zep",
                                            "line": 182,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 182,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 182,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 183,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Utility to normalize a string's encoding to UTF-32.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Escaper.zep",
                                "line": 166,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 166,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 165,
                    "last-line": 191,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDoubleEncode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "doubleEncode",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 192,
                            "char": 54
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
                                    "property": "doubleEncode",
                                    "expr": {
                                        "type": "variable",
                                        "value": "doubleEncode",
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 194,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 194,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 195,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the double_encode to be used by the escaper\n     *\n     *```php\n     * $escaper->setDoubleEncode(false);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 193,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 192,
                    "last-line": 203,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEncoding",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "encoding",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 204,
                            "char": 48
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
                                    "property": "encoding",
                                    "expr": {
                                        "type": "variable",
                                        "value": "encoding",
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 206,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 206,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 207,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the encoding to be used by the escaper\n     *\n     *```php\n     * $escaper->setEncoding(\"utf-8\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 205,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 204,
                    "last-line": 215,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHtmlQuoteType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "quoteType",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 216,
                            "char": 51
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
                                    "property": "htmlQuoteType",
                                    "expr": {
                                        "type": "variable",
                                        "value": "quoteType",
                                        "file": "\/app\/phalcon\/Escaper.zep",
                                        "line": 218,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Escaper.zep",
                                    "line": 218,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Escaper.zep",
                            "line": 219,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the HTML quoting type for htmlspecialchars\n     *\n     *```php\n     * $escaper->setHtmlQuoteType(ENT_XHTML);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Escaper.zep",
                        "line": 217,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Escaper.zep",
                    "line": 216,
                    "last-line": 220,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Escaper.zep",
            "line": 33,
            "char": 5
        },
        "file": "\/app\/phalcon\/Escaper.zep",
        "line": 33,
        "char": 5
    }
]