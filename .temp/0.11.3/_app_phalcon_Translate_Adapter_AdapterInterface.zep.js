[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate\\Adapter",
        "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Translate\\AdapterInterface\n *\n * Interface for Phalcon\\Translate adapters\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "AdapterInterface",
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                            "line": 23,
                            "char": 41
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
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                                "line": 23,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                        "line": 23,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                    "line": 23,
                    "last-line": 29,
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
                            "name": "translateKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                            "line": 30,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                                "line": 30,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                            "line": 30,
                            "char": 68
                        }
                    ],
                    "docblock": "**\n     * Returns the translation related to the given key\n     *\n     * @param array placeholders\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                                "line": 30,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                        "line": 30,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                    "line": 30,
                    "last-line": 36,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "t",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "translateKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                            "line": 37,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                                "line": 37,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                            "line": 37,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Returns the translation string of the given key\n     *\n     * @param array placeholders\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                                "line": 37,
                                "char": 75
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                        "line": 37,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
                    "line": 37,
                    "last-line": 38,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
            "line": 38,
            "char": 1
        },
        "file": "\/app\/phalcon\/Translate\/Adapter\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]