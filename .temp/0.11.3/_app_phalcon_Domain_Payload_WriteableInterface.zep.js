[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by phalcon-api and AuraPHP\n * @link    https:\/\/github.com\/phalcon\/phalcon-api\n * @license https:\/\/github.com\/phalcon\/phalcon-api\/blob\/master\/LICENSE\n * @link    https:\/\/github.com\/auraphp\/Aura.Payload\n * @license https:\/\/github.com\/auraphp\/Aura.Payload\/blob\/3.x\/LICENSE\n *\n * @see Original inspiration for the https:\/\/github.com\/phalcon\/phalcon-api\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Domain\\Payload",
        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Domain\\Payload\\PayloadInterface",
                "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                "line": 21,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This interface is used for consumers (write)\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
        "line": 26,
        "char": 9
    },
    {
        "type": "interface",
        "name": "WriteableInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStatus",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "status",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                            "line": 33,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Sets the status of this payload.\n     *\n     * @param mixed $status The status for this payload.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                    "line": 33,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                "line": 33,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                        "line": 33,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                    "line": 33,
                    "last-line": 41,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setInput",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "input",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                            "line": 42,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     *\n     * Sets the input received by the domain layer.\n     *\n     * @param mixed $input The input received by the domain layer.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                    "line": 42,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                "line": 42,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                        "line": 42,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                    "line": 42,
                    "last-line": 48,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOutput",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "output",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                            "line": 49,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Sets the output produced from the domain layer.\n     *\n     * @param mixed $output The output produced from the domain layer.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                    "line": 49,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                "line": 49,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                        "line": 49,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                    "line": 49,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMessages",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "messages",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                            "line": 56,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets the messages produced by the domain layer.\n     *\n     * @param mixed $messages The messages produced by the domain layer.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                    "line": 56,
                                    "char": 68
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                "line": 56,
                                "char": 68
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                        "line": 56,
                        "char": 68
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                    "line": 56,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setExtras",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "extras",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                            "line": 63,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Sets arbitrary extra values produced by the domain layer.\n     *\n     * @param mixed $extras Arbitrary extra values produced by the domain layer.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                    "line": 63,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                                "line": 63,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                        "line": 63,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
                    "line": 63,
                    "last-line": 64,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
            "line": 64,
            "char": 1
        },
        "file": "\/app\/phalcon\/Domain\/Payload\/WriteableInterface.zep",
        "line": 0,
        "char": 0
    }
]