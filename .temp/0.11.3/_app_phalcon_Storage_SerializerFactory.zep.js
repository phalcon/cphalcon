[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage",
        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                "line": 14,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "SerializerFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
        "definition": {
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
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 23,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 23,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 25,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 25,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 25,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 25,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 26,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * SerializerFactory constructor.\n     *\n     * @param array services\n     *",
                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                    "line": 23,
                    "last-line": 33,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 34,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 36,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 38,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 38,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 38,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 38,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 38,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 40,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                "line": 40,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                "line": 40,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 40,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 40,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 40,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 40,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 40,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                        "line": 41,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                        "line": 41,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                    "line": 41,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                    "line": 41,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                "line": 41,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 41,
                                            "char": 58
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "services",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                    "line": 42,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "definition",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                                "line": 42,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 42,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 43,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 45,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 45,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 45,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 45,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 45,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 45,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 46,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param string name\n     *\n     * @return mixed\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "SerializerInterface",
                                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                    "line": 35,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 35,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                        "line": 35,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                    "line": 34,
                    "last-line": 48,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "base64",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 51,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Storage\\\\Serializer\\\\Base64",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 51,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 51,
                                        "char": 62
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "igbinary",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 52,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Storage\\\\Serializer\\\\Igbinary",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 52,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 52,
                                        "char": 64
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "json",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 53,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Storage\\\\Serializer\\\\Json",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 53,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 53,
                                        "char": 60
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "msgpack",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 54,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Storage\\\\Serializer\\\\Msgpack",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 54,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 54,
                                        "char": 63
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "none",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 55,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Storage\\\\Serializer\\\\None",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 55,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 55,
                                        "char": 60
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "php",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 56,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Storage\\\\Serializer\\\\Php",
                                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                            "line": 57,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                        "line": 57,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 57,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                            "line": 58,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                                "line": 49,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                        "line": 49,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
                    "line": 48,
                    "last-line": 59,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/SerializerFactory.zep",
        "line": 16,
        "char": 5
    }
]