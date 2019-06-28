[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Serializer",
        "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\AbstractSerializer",
                "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                "line": 13,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
        "line": 15,
        "char": 5
    },
    {
        "type": "class",
        "name": "None",
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
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                                    "line": 22,
                                    "char": 15
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "data",
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                                    "line": 22,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                                "line": 22,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                            "line": 23,
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
                                "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                                "line": 21,
                                "char": 2
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                        "line": 21,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                    "line": 20,
                    "last-line": 27,
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
                            "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                            "line": 28,
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
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                                        "line": 30,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                                    "line": 30,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                            "line": 31,
                            "char": 2
                        }
                    ],
                    "docblock": "**\n\t * Unserializes data\n\t *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                        "line": 29,
                        "char": 2
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 16
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
            "line": 15,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Serializer\/None.zep",
        "line": 15,
        "char": 5
    }
]