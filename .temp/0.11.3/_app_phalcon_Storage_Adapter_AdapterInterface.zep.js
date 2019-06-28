[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Adapter",
        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                "line": 13,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\AdapterInterface\n *\n * Interface for Phalcon\\Logger adapters\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
        "line": 20,
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
                    "name": "clear",
                    "docblock": "**\n     * Flushes\/clears the cache\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 25,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 25,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "decrement",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 30,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "1",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 30,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 30,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Decrements a stored number\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 30,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 30,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 30,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 35,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Deletes data from the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 35,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 35,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 40,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 40,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 40,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 40,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAdapter",
                    "docblock": "**\n     * Returns the already connected adapter or connects to the backend\n     * server(s)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 46,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 46,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getKeys",
                    "docblock": "**\n     * Returns all the keys stored\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 51,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 51,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrefix",
                    "docblock": "**\n     * Returns the prefix for the keys\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 56,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 56,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 56,
                    "last-line": 60,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 61,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Checks if an element exists in the cache\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 61,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 61,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "increment",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 66,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "1",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 66,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 66,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Increments a stored number\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 66,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 66,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 66,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 66,
                    "last-line": 70,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 71,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 71,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "ttl",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 71,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                            "line": 71,
                            "char": 63
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                                "line": 71,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                        "line": 71,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
                    "line": 71,
                    "last-line": 72,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
            "line": 72,
            "char": 1
        },
        "file": "\/app\/phalcon\/Storage\/Adapter\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]