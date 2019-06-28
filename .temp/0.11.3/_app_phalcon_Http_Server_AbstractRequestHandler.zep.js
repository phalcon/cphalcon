[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Server",
        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ResponseInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ServerRequestInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Server\\RequestHandlerInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                "line": 15,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Handles a server request and produces a response.\n *\n * An HTTP request handler process an HTTP request in order to produce an\n * HTTP response.\n *",
        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
        "line": 23,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractRequestHandler",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "RequestHandlerInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                "line": 24,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "handle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "request",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ServerRequestInterface",
                                "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                                "line": 30,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                            "line": 30,
                            "char": 69
                        }
                    ],
                    "docblock": "**\n     * Handles a request and produces a response.\n     *\n     * May call other collaborating code to generate the response.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                                    "line": 30,
                                    "char": 93
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                                "line": 30,
                                "char": 93
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                        "line": 30,
                        "char": 93
                    },
                    "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
                    "line": 30,
                    "last-line": 31,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
            "line": 23,
            "char": 14
        },
        "file": "\/app\/phalcon\/Http\/Server\/AbstractRequestHandler.zep",
        "line": 23,
        "char": 14
    }
]