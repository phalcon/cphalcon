[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/EscaperInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/EscaperInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Escaper\n *",
        "file": "\/app\/phalcon\/EscaperInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "EscaperInterface",
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/EscaperInterface.zep",
                            "line": 22,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Escape CSS strings by replacing non-alphanumeric chars by their\n     * hexadecimal representation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/EscaperInterface.zep",
                                "line": 22,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 22,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 22,
                    "last-line": 26,
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
                            "file": "\/app\/phalcon\/EscaperInterface.zep",
                            "line": 27,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Escapes a HTML string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/EscaperInterface.zep",
                                "line": 27,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 27,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 27,
                    "last-line": 31,
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
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/EscaperInterface.zep",
                            "line": 32,
                            "char": 47
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
                                "file": "\/app\/phalcon\/EscaperInterface.zep",
                                "line": 32,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 32,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 32,
                    "last-line": 37,
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
                            "file": "\/app\/phalcon\/EscaperInterface.zep",
                            "line": 38,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Escape Javascript strings by replacing non-alphanumeric chars by their\n     * hexadecimal representation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/EscaperInterface.zep",
                                "line": 38,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 38,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 38,
                    "last-line": 42,
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
                            "file": "\/app\/phalcon\/EscaperInterface.zep",
                            "line": 43,
                            "char": 41
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
                                "file": "\/app\/phalcon\/EscaperInterface.zep",
                                "line": 43,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 43,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEncoding",
                    "docblock": "**\n     * Returns the internal encoding used by the escaper\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/EscaperInterface.zep",
                                "line": 48,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 48,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 48,
                    "last-line": 52,
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
                            "file": "\/app\/phalcon\/EscaperInterface.zep",
                            "line": 53,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Sets the encoding to be used by the escaper\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 53,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 53,
                    "last-line": 57,
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
                            "file": "\/app\/phalcon\/EscaperInterface.zep",
                            "line": 58,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets the HTML quoting type for htmlspecialchars\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/EscaperInterface.zep",
                        "line": 58,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/EscaperInterface.zep",
                    "line": 58,
                    "last-line": 59,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/EscaperInterface.zep",
            "line": 59,
            "char": 1
        },
        "file": "\/app\/phalcon\/EscaperInterface.zep",
        "line": 0,
        "char": 0
    }
]