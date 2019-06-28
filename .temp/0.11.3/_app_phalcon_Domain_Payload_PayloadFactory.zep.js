[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by phalcon-api and AuraPHP\n * @link    https:\/\/github.com\/phalcon\/phalcon-api\n * @license https:\/\/github.com\/phalcon\/phalcon-api\/blob\/master\/LICENSE\n * @link    https:\/\/github.com\/auraphp\/Aura.Payload\n * @license https:\/\/github.com\/auraphp\/Aura.Payload\/blob\/3.x\/LICENSE\n *\n * @see Original inspiration for the https:\/\/github.com\/phalcon\/phalcon-api\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Domain\\Payload",
        "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Domain\\Payload\\Payload",
                "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                "line": 21,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Domain\\Payload\\PayloadInterface",
                "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                "line": 22,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
        "line": 26,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Factory to create payload objects\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
        "line": 27,
        "char": 5
    },
    {
        "type": "class",
        "name": "PayloadFactory",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Payload",
                                "dynamic": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                                "line": 34,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                            "line": 35,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Instantiate a new object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                                    "line": 33,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                                "line": 33,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
                    "line": 32,
                    "last-line": 36,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
            "line": 27,
            "char": 5
        },
        "file": "\/app\/phalcon\/Domain\/Payload\/PayloadFactory.zep",
        "line": 27,
        "char": 5
    }
]