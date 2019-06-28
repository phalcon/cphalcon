[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Response",
                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                "line": 17,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ResponseInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                "line": 18,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ResponseFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                "line": 19,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-17 ResponseFactory\n *",
        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "ResponseFactory",
        "abstract": 0,
        "final": 1,
        "implements": [
            {
                "type": "variable",
                "value": "ResponseFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
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
                    "name": "createResponse",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "200",
                                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                "line": 37,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                            "line": 37,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "reasonPhrase",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                "line": 37,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                            "line": 37,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "list",
                                    "left": {
                                        "type": "new",
                                        "class": "Response",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                        "line": 39,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                    "line": 39,
                                    "char": 33
                                },
                                "name": "withStatus",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "code",
                                            "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                            "line": 39,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                        "line": 39,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "reasonPhrase",
                                            "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                            "line": 39,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                        "line": 39,
                                        "char": 63
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                "line": 39,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new response.\n     *\n     * @param int    $code         The HTTP status code. Defaults to 200.\n     * @param string $reasonPhrase The reason phrase to associate with the status\n     *                             code in the generated response. If none is\n     *                             provided, implementations MAY use the defaults\n     *                             as suggested in the HTTP specification.\n     *\n     * @return ResponseInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                    "line": 38,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                                "line": 38,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                        "line": 38,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
                    "line": 37,
                    "last-line": 41,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
            "line": 24,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/ResponseFactory.zep",
        "line": 24,
        "char": 11
    }
]