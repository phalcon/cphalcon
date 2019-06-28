[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Serializer",
        "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Serializable",
                "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                "line": 13,
                "char": 17
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "interface",
        "name": "SerializerInterface",
        "extends": [
            {
                "type": "variable",
                "value": "Serializable",
                "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                "line": 16,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getData",
                    "docblock": "**\n     * @var mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                                "line": 20,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                        "line": 20,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                    "line": 20,
                    "last-line": 24,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                            "line": 25,
                            "char": 37
                        }
                    ],
                    "docblock": "**\n     * @param $data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                        "line": 25,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
                    "line": 25,
                    "last-line": 26,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
            "line": 26,
            "char": 1
        },
        "file": "\/app\/phalcon\/Storage\/Serializer\/SerializerInterface.zep",
        "line": 0,
        "char": 0
    }
]