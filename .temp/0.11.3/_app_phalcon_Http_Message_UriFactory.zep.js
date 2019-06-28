[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                "line": 17,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                "line": 18,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Uri",
                "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                "line": 19,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-17 UriFactory\n *",
        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "UriFactory",
        "abstract": 0,
        "final": 1,
        "implements": [
            {
                "type": "variable",
                "value": "UriFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                "line": 25,
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
                    "name": "createUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                                "line": 30,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                            "line": 30,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Uri",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                                            "line": 32,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                                        "line": 32,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                                "line": 32,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                            "line": 33,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a Locator object with all the helpers defined in anonynous\n     * functions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UriInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                                    "line": 31,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                                "line": 31,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                        "line": 31,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
            "line": 24,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/UriFactory.zep",
        "line": 24,
        "char": 11
    }
]