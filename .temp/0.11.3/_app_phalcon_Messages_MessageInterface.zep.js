[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Messages",
        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Messages\\MessageInterface\n *\n * Interface for Phalcon\\Messages\\MessageInterface\n *",
        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "MessageInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__toString",
                    "docblock": "**\n     * Magic __toString method returns verbose message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 25,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 25,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 25,
                    "last-line": 31,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCode",
                    "docblock": "**\n     * Returns the message code related to this message\n     *\n     * @return int\n     *",
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 32,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getField",
                    "docblock": "**\n     * Returns field name related to message\n     *\n     * @return string\n     *",
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 39,
                    "last-line": 43,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessage",
                    "docblock": "**\n     * Returns verbose message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 44,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 44,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 44,
                    "last-line": 48,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMetaData",
                    "docblock": "**\n     * Returns message metadata\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 49,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 49,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 49,
                    "last-line": 53,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "docblock": "**\n     * Returns message type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 54,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 54,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 54,
                    "last-line": 58,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                            "line": 59,
                            "char": 37
                        }
                    ],
                    "docblock": "**\n     * Sets code for the message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                    "line": 59,
                                    "char": 60
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 59,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 59,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 59,
                    "last-line": 63,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                            "line": 64,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Sets field name related to message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                    "line": 64,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 64,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 64,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 64,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                            "line": 69,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Sets verbose message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                    "line": 69,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 69,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 69,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 69,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMetaData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "metaData",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                            "line": 74,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Sets message metadata\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                    "line": 74,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 74,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 74,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 74,
                    "last-line": 78,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                            "line": 79,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Sets message type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                    "line": 79,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                                "line": 79,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                        "line": 79,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
                    "line": 79,
                    "last-line": 80,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
            "line": 80,
            "char": 1
        },
        "file": "\/app\/phalcon\/Messages\/MessageInterface.zep",
        "line": 0,
        "char": 0
    }
]