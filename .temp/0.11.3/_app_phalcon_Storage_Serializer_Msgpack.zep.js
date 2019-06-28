[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Serializer",
        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\AbstractSerializer",
                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                "line": 13,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
        "line": 15,
        "char": 5
    },
    {
        "type": "class",
        "name": "Msgpack",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractSerializer",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "serialize",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                    "line": 22,
                                    "char": 17
                                },
                                "name": "isSerializable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                                "line": 22,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                                "line": 22,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                            "line": 22,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                        "line": 22,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                "line": 22,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                            "line": 23,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                            "line": 23,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                        "line": 23,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                    "line": 24,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                            "line": 26,
                            "char": 8
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "msgpack_pack",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                                "line": 26,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                                "line": 26,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                            "line": 26,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                        "line": 26,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                "line": 26,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                            "line": 27,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n\t * Serializes data\n\t *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                "line": 20,
                                "char": 39
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                "line": 21,
                                "char": 2
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                        "line": 21,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                    "line": 20,
                    "last-line": 31,
                    "char": 16
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "unserialize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                            "line": 32,
                            "char": 38
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
                                    "property": "data",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "msgpack_unpack",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                                    "line": 34,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                                "line": 34,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                        "line": 34,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                                    "line": 34,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                            "line": 35,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n\t * Unserializes data\n\t *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                        "line": 33,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
                    "line": 32,
                    "last-line": 36,
                    "char": 16
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
            "line": 15,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Serializer\/Msgpack.zep",
        "line": 15,
        "char": 5
    }
]