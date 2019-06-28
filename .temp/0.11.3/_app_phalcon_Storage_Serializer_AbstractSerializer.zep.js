[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Serializer",
        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                "line": 13,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                "line": 14,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
        "line": 16,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractSerializer",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                "line": 17,
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
                    "name": "data",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                        "line": 21,
                        "char": 27
                    },
                    "docblock": "**\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                            "line": 21,
                            "char": 32
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                            "line": 21,
                            "char": 38
                        }
                    ],
                    "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                    "line": 25,
                    "char": 3
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
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                "line": 26,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                            "line": 26,
                            "char": 45
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
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                        "line": 28,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                    "line": 28,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                            "line": 29,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n\t * Constructor\n\t *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                        "line": 27,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                    "line": 26,
                    "last-line": 33,
                    "char": 16
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "isSerializable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                            "line": 34,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "or",
                                    "left": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                            "line": 36,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                        "line": 36,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "identical",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                                "line": 36,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                            "line": 36,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "bool",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                            "line": 36,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                        "line": 36,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                    "line": 36,
                                    "char": 52
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "is_numeric",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                                "line": 36,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                            "line": 36,
                                            "char": 69
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                    "line": 36,
                                    "char": 70
                                },
                                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                "line": 36,
                                "char": 70
                            },
                            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                            "line": 37,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n     * If this returns true, then the data returns back as is\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                                "line": 35,
                                "char": 2
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                        "line": 35,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
                    "line": 34,
                    "last-line": 38,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
            "line": 16,
            "char": 14
        },
        "file": "\/app\/phalcon\/Storage\/Serializer\/AbstractSerializer.zep",
        "line": 16,
        "char": 14
    }
]