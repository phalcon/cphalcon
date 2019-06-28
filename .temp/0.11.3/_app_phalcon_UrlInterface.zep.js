[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/UrlInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/UrlInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\UrlInterface\n *",
        "file": "\/app\/phalcon\/UrlInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "UrlInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 24,
                                "char": 35
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/UrlInterface.zep",
                            "line": 24,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "args",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 24,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/UrlInterface.zep",
                            "line": 24,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 24,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/UrlInterface.zep",
                            "line": 24,
                            "char": 67
                        }
                    ],
                    "docblock": "**\n     * Generates a URL\n     *\n     * @param string|array uri\n     * @param array|object args Optional arguments to be appended to the query string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 24,
                                "char": 78
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/UrlInterface.zep",
                        "line": 24,
                        "char": 78
                    },
                    "file": "\/app\/phalcon\/UrlInterface.zep",
                    "line": 24,
                    "last-line": 28,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBasePath",
                    "docblock": "**\n     * Returns a base path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 29,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/UrlInterface.zep",
                        "line": 29,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/UrlInterface.zep",
                    "line": 29,
                    "last-line": 33,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBaseUri",
                    "docblock": "**\n     * Returns the prefix for all the generated urls. By default \/\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 34,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/UrlInterface.zep",
                        "line": 34,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/UrlInterface.zep",
                    "line": 34,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBasePath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "basePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/UrlInterface.zep",
                            "line": 39,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets a base paths for all the generated paths\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UrlInterface",
                                    "file": "\/app\/phalcon\/UrlInterface.zep",
                                    "line": 39,
                                    "char": 68
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 39,
                                "char": 68
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/UrlInterface.zep",
                        "line": 39,
                        "char": 68
                    },
                    "file": "\/app\/phalcon\/UrlInterface.zep",
                    "line": 39,
                    "last-line": 43,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBaseUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "baseUri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/UrlInterface.zep",
                            "line": 44,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Sets a prefix to all the urls generated\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UrlInterface",
                                    "file": "\/app\/phalcon\/UrlInterface.zep",
                                    "line": 44,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 44,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/UrlInterface.zep",
                        "line": 44,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/UrlInterface.zep",
                    "line": 44,
                    "last-line": 48,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "path",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 49,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/UrlInterface.zep",
                            "line": 49,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Generates a local path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/UrlInterface.zep",
                                "line": 49,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/UrlInterface.zep",
                        "line": 49,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/UrlInterface.zep",
                    "line": 49,
                    "last-line": 50,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/UrlInterface.zep",
            "line": 50,
            "char": 1
        },
        "file": "\/app\/phalcon\/UrlInterface.zep",
        "line": 0,
        "char": 0
    }
]