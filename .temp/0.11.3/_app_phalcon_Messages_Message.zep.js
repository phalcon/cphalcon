[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Messages\/Message.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Messages",
        "file": "\/app\/phalcon\/Messages\/Message.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "JsonSerializable",
                "file": "\/app\/phalcon\/Messages\/Message.zep",
                "line": 13,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Message.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Messages\/Message.zep",
                "line": 14,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Message.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Messages\\Message\n *\n * Stores a message from various components\n *",
        "file": "\/app\/phalcon\/Messages\/Message.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "Message",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "MessageInterface",
                "file": "\/app\/phalcon\/Messages\/Message.zep",
                "line": 21,
                "char": 42
            },
            {
                "type": "variable",
                "value": "JsonSerializable",
                "file": "\/app\/phalcon\/Messages\/Message.zep",
                "line": 22,
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
                    "name": "code",
                    "docblock": "**\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 26,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 30,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "field",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 31,
                            "char": 27
                        }
                    ],
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "message",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 36,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 40,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 41,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 45,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "metaData",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 46,
                        "char": 29
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 46,
                            "char": 35
                        }
                    ],
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 50,
                    "char": 6
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
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 51,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 51,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 51,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 51,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 51,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 51,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 51,
                            "char": 92
                        },
                        {
                            "type": "parameter",
                            "name": "metaData",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 51,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 51,
                            "char": 113
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
                                    "property": "message",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 53,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 53,
                                    "char": 37
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "field",
                                    "expr": {
                                        "type": "variable",
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 54,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 54,
                                    "char": 35
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 55,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 55,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "code",
                                    "expr": {
                                        "type": "variable",
                                        "value": "code",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 56,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 56,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "metaData",
                                    "expr": {
                                        "type": "variable",
                                        "value": "metaData",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 57,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 57,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 58,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Messages\\Message constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 52,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 51,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__toString",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 65,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "message",
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 65,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 65,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 66,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic __toString method returns verbose message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 64,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 63,
                    "last-line": 70,
                    "char": 19
                },
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
                            "name": "message",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 71,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "self",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 74,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "_message",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 74,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 74,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 74,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 75,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "_field",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 75,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 75,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 75,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 76,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "_type",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 76,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 76,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 76,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 77,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "_code",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 77,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 77,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 77,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 78,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "_metaData",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 78,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 79,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 79,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 79,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 80,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic __set_state helps to re-build messages variable exporting\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 72,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 72,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 71,
                    "last-line": 84,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "jsonSerialize",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 88,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 88,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 88,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 88,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 88,
                                        "char": 35
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 89,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 89,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 89,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 89,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 89,
                                        "char": 37
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 90,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 90,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 90,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 90,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 90,
                                        "char": 34
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "code",
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 91,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 91,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "code",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 91,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 91,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 91,
                                        "char": 34
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "metaData",
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 92,
                                            "char": 22
                                        },
                                        "value": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 92,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "metaData",
                                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                                "line": 93,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                                            "line": 93,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 93,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 93,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 94,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Serializes the object for json_encode\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 86,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 86,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 85,
                    "last-line": 98,
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
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 99,
                            "char": 37
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
                                    "property": "code",
                                    "expr": {
                                        "type": "variable",
                                        "value": "code",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 101,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 101,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 103,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 103,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 104,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 100,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 100,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 100,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 99,
                    "last-line": 108,
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
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 109,
                            "char": 39
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
                                    "property": "field",
                                    "expr": {
                                        "type": "variable",
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 111,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 111,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 113,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 113,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 114,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 110,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 110,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 110,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 109,
                    "last-line": 118,
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
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 119,
                            "char": 47
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
                                    "property": "message",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 121,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 121,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 123,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 123,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 124,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 120,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 120,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 120,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 119,
                    "last-line": 128,
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
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 129,
                            "char": 48
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
                                    "property": "metaData",
                                    "expr": {
                                        "type": "variable",
                                        "value": "metaData",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 131,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 131,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 133,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 133,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 134,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 130,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 130,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 130,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 129,
                    "last-line": 138,
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
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 139,
                            "char": 41
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
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                                        "line": 141,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 141,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 143,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 143,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Messages\/Message.zep",
                            "line": 144,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                                    "line": 140,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/Message.zep",
                                "line": 140,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Message.zep",
                        "line": 140,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Message.zep",
                    "line": 139,
                    "last-line": 145,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Messages\/Message.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Messages\/Message.zep",
        "line": 21,
        "char": 5
    }
]