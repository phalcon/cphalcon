[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by phalcon-api and AuraPHP\n * @link    https:\/\/github.com\/phalcon\/phalcon-api\n * @license https:\/\/github.com\/phalcon\/phalcon-api\/blob\/master\/LICENSE\n * @link    https:\/\/github.com\/auraphp\/Aura.Payload\n * @license https:\/\/github.com\/auraphp\/Aura.Payload\/blob\/3.x\/LICENSE\n *\n * @see Original inspiration for the https:\/\/github.com\/phalcon\/phalcon-api\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Domain\\Payload",
        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This interface is used for consumers (read only)\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
        "line": 24,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ReadableInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStatus",
                    "docblock": "**\n     * Gets the status of this payload.\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                                "line": 31,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                        "line": 31,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                    "line": 31,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getInput",
                    "docblock": "**\n     * Gets the input received by the domain layer.\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                                "line": 38,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                        "line": 38,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                    "line": 38,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOutput",
                    "docblock": "**\n     * Gets the output produced from the domain layer.\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                                "line": 45,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                        "line": 45,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                    "line": 45,
                    "last-line": 51,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "docblock": "**\n     * Gets the messages produced by the domain layer.\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                                "line": 52,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                        "line": 52,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                    "line": 52,
                    "last-line": 58,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getExtras",
                    "docblock": "**\n     * Gets arbitrary extra values produced by the domain layer.\n     *\n     * @param mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                                "line": 59,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                        "line": 59,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
                    "line": 59,
                    "last-line": 60,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
            "line": 60,
            "char": 1
        },
        "file": "\/app\/phalcon\/Domain\/Payload\/ReadableInterface.zep",
        "line": 0,
        "char": 0
    }
]