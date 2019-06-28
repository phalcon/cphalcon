[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Serializer",
        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "InvalidArgumentException",
                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\AbstractSerializer",
                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                "line": 14,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Base64",
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
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                            "line": 23,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                            "line": 23,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                        "line": 23,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                    "line": 23,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                    "line": 23,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                "line": 23,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Data for the serializer must of type string",
                                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                    "line": 26,
                                                    "char": 10
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                "line": 26,
                                                "char": 10
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                        "line": 26,
                                        "char": 11
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                    "line": 27,
                                    "char": 6
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                            "line": 29,
                            "char": 8
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "base64_encode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                "line": 29,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                "line": 29,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                            "line": 29,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                        "line": 29,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                "line": 29,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                            "line": 30,
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
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                "line": 22,
                                "char": 2
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                        "line": 22,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                    "line": 21,
                    "last-line": 34,
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
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                            "line": 35,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                        "line": 37,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                    "line": 37,
                                    "char": 23
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                    "line": 37,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                "line": 37,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Data for the unserializer must of type string",
                                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                    "line": 40,
                                                    "char": 10
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                "line": 40,
                                                "char": 10
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                        "line": 40,
                                        "char": 11
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                    "line": 41,
                                    "char": 6
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                            "line": 43,
                            "char": 5
                        },
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
                                        "name": "base64_decode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                    "line": 43,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                                "line": 43,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                        "line": 43,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                                    "line": 43,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                            "line": 44,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n\t * Unserializes data\n\t *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                        "line": 36,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
                    "line": 35,
                    "last-line": 45,
                    "char": 16
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Serializer\/Base64.zep",
        "line": 16,
        "char": 5
    }
]