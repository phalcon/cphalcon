[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Flash",
        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\FlashInterface\n *\n * Interface for Phalcon\\Flash\n *",
        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "FlashInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "error",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                            "line": 23,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML error message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                                "line": 23,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                        "line": 23,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "message",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                            "line": 28,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                            "line": 28,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Outputs a message\n     *",
                    "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notice",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                            "line": 33,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML notice\/information message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                                "line": 33,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                        "line": 33,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "success",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                            "line": 38,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML success message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                                "line": 38,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                        "line": 38,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "warning",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                            "line": 43,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML warning message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                                "line": 43,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                        "line": 43,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
                    "line": 43,
                    "last-line": 44,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
            "line": 44,
            "char": 1
        },
        "file": "\/app\/phalcon\/Flash\/FlashInterface.zep",
        "line": 0,
        "char": 0
    }
]