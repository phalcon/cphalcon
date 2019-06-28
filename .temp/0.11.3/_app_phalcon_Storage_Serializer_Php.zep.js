[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Serializer",
        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                "line": 13,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\AbstractSerializer",
                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                "line": 14,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Php",
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
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                    "line": 23,
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
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                "line": 23,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                "line": 23,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                            "line": 23,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                        "line": 23,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                "line": 23,
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
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                            "line": 24,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                            "line": 24,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                        "line": 24,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                    "line": 25,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                            "line": 27,
                            "char": 8
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "serialize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                "line": 27,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                "line": 27,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                            "line": 27,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                        "line": 27,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                "line": 27,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                            "line": 28,
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
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                "line": 22,
                                "char": 2
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                        "line": 22,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                    "line": 21,
                    "last-line": 32,
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
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                            "line": 33,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                    "line": 35,
                                    "char": 14
                                },
                                "name": "isSerializable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                            "line": 35,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                        "line": 35,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                "line": 35,
                                "char": 36
                            },
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
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                "line": 36,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                            "line": 36,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                    "line": 37,
                                    "char": 6
                                }
                            ],
                            "else_statements": [
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
                                                "name": "unserialize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                            "line": 38,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                        "line": 38,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                                "line": 38,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                            "line": 38,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                                    "line": 39,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                            "line": 40,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n\t * Unserializes data\n\t *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                        "line": 34,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
                    "line": 33,
                    "last-line": 41,
                    "char": 16
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Serializer\/Php.zep",
        "line": 16,
        "char": 5
    }
]