[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Server",
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ResponseInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ServerRequestInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Server\\MiddlewareInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                "line": 15,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Server\\RequestHandlerInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                "line": 16,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Participant in processing a server request and response.\n *\n * An HTTP middleware component participates in processing an HTTP message:\n * by acting on the request, generating the response, or forwarding the\n * request to a subsequent middleware and possibly acting on its response.\n *",
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 25,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractMiddleware",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "MiddlewareInterface",
                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                "line": 26,
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
                    "name": "process",
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
                                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                                "line": 35,
                                "char": 40
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                            "line": 35,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "RequestHandlerInterface",
                                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                                "line": 36,
                                "char": 41
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                            "line": 37,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Process an incoming server request.\n     *\n     * Processes an incoming server request in order to produce a response.\n     * If unable to produce the response itself, it may delegate to the provided\n     * request handler to do so.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                                    "line": 37,
                                    "char": 29
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                                "line": 37,
                                "char": 29
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                        "line": 37,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
                    "line": 34,
                    "last-line": 38,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
            "line": 25,
            "char": 14
        },
        "file": "\/app\/phalcon\/Http\/Server\/AbstractMiddleware.zep",
        "line": 25,
        "char": 14
    }
]