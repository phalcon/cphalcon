[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Response",
        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Http\\Response\\HeadersInterface\n *\n * Interface for Phalcon\\Http\\Response\\Headers compatible bags\n *",
        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "HeadersInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "__set_state",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                            "line": 23,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Restore a \\Phalcon\\Http\\Response\\Headers object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "HeadersInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                                    "line": 23,
                                    "char": 74
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                                "line": 23,
                                "char": 74
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                        "line": 23,
                        "char": 74
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                            "line": 28,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Gets a header value from the internal bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                                "line": 28,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                                "line": 28,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                        "line": 28,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                            "line": 33,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Returns true if the header is set, false otherwise\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                                "line": 33,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                        "line": 33,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "docblock": "**\n     * Reset set headers\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "send",
                    "docblock": "**\n     * Sends the headers to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                                "line": 43,
                                "char": 35
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                        "line": 43,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                            "line": 48,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                            "line": 48,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Sets a header to be sent at the end of the request\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRaw",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "header",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                            "line": 53,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Sets a raw header to be sent at the end of the request\n     *",
                    "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
                    "line": 53,
                    "last-line": 54,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
            "line": 54,
            "char": 1
        },
        "file": "\/app\/phalcon\/Http\/Response\/HeadersInterface.zep",
        "line": 0,
        "char": 0
    }
]