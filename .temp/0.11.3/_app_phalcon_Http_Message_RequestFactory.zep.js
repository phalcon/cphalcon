[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Request",
                "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                "line": 17,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\RequestInterface",
                "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                "line": 18,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\RequestFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                "line": 19,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                "line": 20,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-17 RequestFactory\n *",
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "RequestFactory",
        "abstract": 0,
        "final": 1,
        "implements": [
            {
                "type": "variable",
                "value": "RequestFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                "line": 26,
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
                    "name": "createRequest",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                            "line": 35,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                            "line": 35,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Request",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                                            "line": 37,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                                        "line": 37,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                                            "line": 37,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                                        "line": 37,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                                "line": 37,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                            "line": 38,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new request.\n     *\n     * @param string                   $method\n     * @param UriInterface|string|null $uri\n     *\n     * @return RequestInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RequestInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                                    "line": 36,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                                "line": 36,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                        "line": 36,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
            "line": 25,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/RequestFactory.zep",
        "line": 25,
        "char": 11
    }
]