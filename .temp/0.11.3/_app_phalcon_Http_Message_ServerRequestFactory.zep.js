[
    {
        "type": "comment",
        "value": "**\n* This file is part of the Phalcon Framework.\n*\n* (c) Phalcon Team <team@phalconphp.com>\n*\n* For the full copyright and license information, please view the LICENSE.txt\n* file that was distributed with this source code.\n*\n* Implementation of this file has been influenced by Zend Diactoros\n* @link    https:\/\/github.com\/zendframework\/zend-diactoros\n* @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n*",
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 17,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 18,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 19,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\ServerRequest",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 20,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\UploadedFile",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 21,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Uri",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 22,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ServerRequestFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 23,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ServerRequestInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 24,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 25,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 25,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 26,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UploadedFileInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 26,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 30,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-17 ServerRequestFactory\n *",
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 31,
        "char": 5
    },
    {
        "type": "class",
        "name": "ServerRequestFactory",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ServerRequestFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                "line": 32,
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
                    "name": "createServerRequest",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 55,
                            "char": 22
                        },
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 56,
                            "char": 16
                        },
                        {
                            "type": "parameter",
                            "name": "serverParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 58,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 58,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "ServerRequest",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 60,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 60,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 60,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 60,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "serverParams",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 60,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 60,
                                        "char": 59
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 60,
                                "char": 60
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new server request.\n     *\n     * Note that server-params are taken precisely as given - no\n     * parsing\/processing of the given values is performed, and, in particular,\n     * no attempt is made to determine the HTTP method or URI, which must be\n     * provided explicitly.\n     *\n     * @param string              $method       The HTTP method associated with\n     *                                          the request.\n     * @param UriInterface|string $uri          The URI associated with the\n     *                                          request. If the value is a\n     *                                          string, the factory MUST create\n     *                                          a UriInterface instance based\n     *                                          on it.\n     * @param array               $serverParams Array of SAPI parameters with\n     *                                          which to seed the generated\n     *                                          request instance.\n     *\n     * @return ServerRequestInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequestInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 58,
                                    "char": 35
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 58,
                                "char": 35
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 58,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 54,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "load",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 82,
                                "char": 28
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 82,
                            "char": 28
                        },
                        {
                            "type": "parameter",
                            "name": "get",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 83,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 83,
                            "char": 25
                        },
                        {
                            "type": "parameter",
                            "name": "post",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 84,
                                "char": 26
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 84,
                            "char": 26
                        },
                        {
                            "type": "parameter",
                            "name": "cookies",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 85,
                                "char": 29
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 85,
                            "char": 29
                        },
                        {
                            "type": "parameter",
                            "name": "files",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 87,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 87,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cookies",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 88,
                                    "char": 20
                                },
                                {
                                    "variable": "filesCollection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 88,
                                    "char": 37
                                },
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 88,
                                    "char": 46
                                },
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 88,
                                    "char": 54
                                },
                                {
                                    "variable": "protocol",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 88,
                                    "char": 64
                                },
                                {
                                    "variable": "serverCollection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 88,
                                    "char": 82
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 90,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "server",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 90,
                                            "char": 37
                                        },
                                        "name": "checkNullArray",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 90,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 90,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "_SERVER",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 90,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 90,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 90,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 90,
                                    "char": 69
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "files",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 91,
                                            "char": 37
                                        },
                                        "name": "checkNullArray",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "files",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 91,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 91,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "_FILES",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 91,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 91,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 91,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 91,
                                    "char": 67
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cookies",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 92,
                                            "char": 37
                                        },
                                        "name": "checkNullArray",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cookies",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 92,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 92,
                                                "char": 60
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "_COOKIE",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 92,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 92,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 92,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 92,
                                    "char": 70
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "get",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 93,
                                            "char": 37
                                        },
                                        "name": "checkNullArray",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "get",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 93,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 93,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "_GET",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 93,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 93,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 93,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 93,
                                    "char": 63
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "post",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 94,
                                            "char": 37
                                        },
                                        "name": "checkNullArray",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "post",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 94,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 94,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "_POST",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 94,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 94,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 94,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 94,
                                    "char": 65
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "serverCollection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 95,
                                            "char": 37
                                        },
                                        "name": "parseServer",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 95,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 95,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 95,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 95,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "method",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serverCollection",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 96,
                                            "char": 49
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "REQUEST_METHOD",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 96,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 96,
                                                "char": 68
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "GET",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 96,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 96,
                                                "char": 73
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 96,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 96,
                                    "char": 74
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "protocol",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serverCollection",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 97,
                                            "char": 49
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "SERVER_PROTOCOL",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 97,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 97,
                                                "char": 69
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "1.1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 97,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 97,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 97,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 97,
                                    "char": 75
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 98,
                                            "char": 37
                                        },
                                        "name": "parseHeaders",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "serverCollection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 98,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 98,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 98,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 98,
                                    "char": 68
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filesCollection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 99,
                                            "char": 37
                                        },
                                        "name": "parseUploadedFiles",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "files",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 99,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 99,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 99,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 99,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 101,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "list",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "cookies",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 101,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 101,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 101,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 101,
                                                "char": 48
                                            },
                                            "name": "has",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "cookie",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 101,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 101,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 101,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 101,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 101,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 101,
                                "char": 62
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "cookies",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 102,
                                                    "char": 32
                                                },
                                                "name": "parseCookieHeader",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "headers",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 102,
                                                                "char": 59
                                                            },
                                                            "name": "get",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "cookie",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 102,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 102,
                                                                    "char": 70
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 102,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 102,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 102,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 102,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 103,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 105,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "ServerRequest",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 106,
                                            "char": 19
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 106,
                                        "char": 19
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 107,
                                                "char": 18
                                            },
                                            "name": "parseUri",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "serverCollection",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 107,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 107,
                                                    "char": 44
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "headers",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 107,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 107,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 107,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 107,
                                        "char": 54
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "serverCollection",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 108,
                                                "char": 30
                                            },
                                            "name": "toArray",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 108,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 108,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "php:\/\/input",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 109,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 109,
                                        "char": 24
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 110,
                                                "char": 21
                                            },
                                            "name": "toArray",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 110,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 110,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cookies",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 111,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 111,
                                        "char": 20
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "get",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 112,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 112,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "filesCollection",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 113,
                                                "char": 29
                                            },
                                            "name": "toArray",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 113,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 113,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "post",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 114,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 114,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "protocol",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 116,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 116,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 116,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 117,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a request from the supplied superglobal values.\n     *\n     * If any argument is not supplied, the corresponding superglobal value will\n     * be used.\n     *\n     * The ServerRequest created is then passed to the fromServer() method in\n     * order to marshal the request URI and headers.\n     *\n     * @param array $server  $_SERVER superglobal\n     * @param array $get     $_GET superglobal\n     * @param array $post    $_POST superglobal\n     * @param array $cookies $_COOKIE superglobal\n     * @param array $files   $_FILES superglobal\n     *\n     * @return ServerRequest\n     * @see fromServer()\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequest",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 87,
                                    "char": 26
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 87,
                                "char": 26
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 87,
                        "char": 26
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 81,
                    "last-line": 123,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getHeaders",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "fcall",
                                    "name": "function_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "apache_request_headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 126,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 126,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 126,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 126,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "apache_request_headers",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 127,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 128,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 130,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 130,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 131,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the apache_request_headers if it exists\n     *\n     * @return array|false\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 124,
                    "last-line": 140,
                    "char": 22
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "calculateUriHost",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 141,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 141,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 141,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 141,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "host",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 143,
                                    "char": 17
                                },
                                {
                                    "variable": "port",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 143,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 144,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "defaults",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 144,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 146,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "defaults",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 146,
                                                    "char": 25
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 146,
                                                "char": 25
                                            },
                                            {
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 146,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 146,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 146,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 146,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 148,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 148,
                                        "char": 26
                                    },
                                    "name": "getHeader",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 148,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 148,
                                            "char": 44
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "host",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 148,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 148,
                                            "char": 50
                                        },
                                        {
                                            "parameter": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 148,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 148,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 148,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 148,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "host",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 149,
                                                    "char": 29
                                                },
                                                "name": "getHeader",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "headers",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 149,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 149,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "host",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 149,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 149,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 149,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 149,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 150,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 150,
                                            "char": 25
                                        },
                                        "name": "calculateUriHostFromHeader",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "host",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 150,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 150,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 150,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 151,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 153,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 153,
                                            "char": 29
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "SERVER_NAME",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 153,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 153,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 153,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 153,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 153,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaults",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 154,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 155,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 157,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "host",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 157,
                                            "char": 27
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "SERVER_NAME",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 157,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 157,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 157,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 157,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "port",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 158,
                                            "char": 27
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "SERVER_PORT",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 158,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 158,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 158,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 158,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 158,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 158,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 160,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "host",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 160,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 160,
                                        "char": 21
                                    },
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "port",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 160,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 160,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 160,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 161,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Calculates the host and port from the headers or the server superglobal\n     *\n     * @param Collection $server\n     * @param Collection $headers\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 142,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 142,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 141,
                    "last-line": 169,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "calculateUriHostFromHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "host",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 170,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 172,
                                    "char": 20
                                },
                                {
                                    "variable": "port",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 172,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 174,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "port",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 174,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 174,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 177,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "fcall",
                                    "name": "preg_match",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "|:(\\d+)$|",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 177,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 177,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "host",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 177,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 177,
                                            "char": 47
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "matches",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 177,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 177,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 177,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 177,
                                "char": 58
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "host",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "host",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 178,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 178,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 178,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 178,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mul",
                                                            "left": {
                                                                "type": "int",
                                                                "value": "-1",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 178,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "add",
                                                                    "left": {
                                                                        "type": "fcall",
                                                                        "name": "strlen",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "matches",
                                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                        "line": 178,
                                                                                        "char": 60
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "int",
                                                                                        "value": "1",
                                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                        "line": 178,
                                                                                        "char": 62
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                    "line": 178,
                                                                                    "char": 63
                                                                                },
                                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                "line": 178,
                                                                                "char": 63
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 178,
                                                                        "char": 65
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 178,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 178,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 178,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 178,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 178,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 178,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 178,
                                            "char": 70
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "port",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "matches",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 179,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 179,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 179,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 179,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 179,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 180,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 182,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "host",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 182,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 182,
                                        "char": 21
                                    },
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "port",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 182,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 182,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 182,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 183,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the host and calculate the port if present from the header\n     *\n     * @param string $host\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 171,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 171,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 170,
                    "last-line": 192,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "calculateUriPath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 193,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 193,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "iisRewrite",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 195,
                                    "char": 23
                                },
                                {
                                    "variable": "origPathInfo",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 195,
                                    "char": 37
                                },
                                {
                                    "variable": "requestUri",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 195,
                                    "char": 49
                                },
                                {
                                    "variable": "unencodedUrl",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 195,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 199,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "iisRewrite",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 199,
                                            "char": 35
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "IIS_WasUrlRewritten",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 199,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 199,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 199,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 199,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 199,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 199,
                                    "char": 66
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "unencodedUrl",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 200,
                                            "char": 35
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "UNENCODED_URL",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 200,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 200,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 200,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 200,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 200,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 200,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 202,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 202,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "iisRewrite",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 202,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 202,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "unencodedUrl",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 202,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 202,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 202,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 202,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 202,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 202,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 202,
                                "char": 64
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "unencodedUrl",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 203,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 204,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 209,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "requestUri",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 209,
                                            "char": 33
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "REQUEST_URI",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 209,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 209,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 209,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 209,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 209,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 209,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 211,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 211,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "requestUri",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 211,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 211,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 211,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_replace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "#^[^\/:]+:\/\/[^\/]+#",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 212,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 212,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 212,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 212,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "requestUri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 212,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 212,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 212,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 213,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 218,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "origPathInfo",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 218,
                                            "char": 35
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "ORIG_PATH_INFO",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 218,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 218,
                                                "char": 54
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 218,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 218,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 218,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 218,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 219,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "list",
                                        "left": {
                                            "type": "variable",
                                            "value": "origPathInfo",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 219,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 219,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 219,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 219,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "\/",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 220,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 221,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 223,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "origPathInfo",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 223,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 224,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the path from the request from IIS7\/Rewrite, REQUEST_URL or\n     * ORIG_PATH_INFO\n     *\n     * @param Collection $server\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 194,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 194,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 193,
                    "last-line": 232,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "calculateUriQuery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 233,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 233,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "ltrim",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "server",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 235,
                                                "char": 29
                                            },
                                            "name": "get",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "QUERY_STRING",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 235,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 235,
                                                    "char": 46
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 235,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 235,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 235,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 235,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "?",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 235,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 235,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 235,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 236,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the query string from the server array\n     *\n     * @param Collection $server\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 234,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 234,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 233,
                    "last-line": 245,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "calculateUriScheme",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 246,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 246,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 246,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 246,
                            "char": 82
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "header",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 248,
                                    "char": 19
                                },
                                {
                                    "variable": "isHttps",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 248,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 249,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "scheme",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 249,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 252,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "scheme",
                                    "expr": {
                                        "type": "string",
                                        "value": "https",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 252,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 252,
                                    "char": 28
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "isHttps",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 253,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 253,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 254,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "server",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 254,
                                        "char": 26
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "HTTPS",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 254,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 254,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 254,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 254,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "isHttps",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "server",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 255,
                                                        "char": 43
                                                    },
                                                    "name": "get",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "HTTPS",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 255,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 255,
                                                            "char": 53
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "on",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 255,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 255,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 255,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 255,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 255,
                                            "char": 58
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "isHttps",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "string",
                                                    "value": "off",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 256,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "strtolower",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "isHttps",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 256,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 256,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 256,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 256,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 256,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 257,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 259,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "header",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 259,
                                            "char": 27
                                        },
                                        "name": "getHeader",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "headers",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 259,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 259,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "x-forwarded-proto",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 259,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 259,
                                                "char": 64
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "https",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 259,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 259,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 259,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 259,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 260,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "variable",
                                                "value": "isHttps",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 260,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 260,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "string",
                                                "value": "https",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 260,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "header",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 260,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 260,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 260,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 260,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 260,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "scheme",
                                            "expr": {
                                                "type": "string",
                                                "value": "http",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 261,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 261,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 262,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 264,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "scheme",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 264,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 265,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Calculates the scheme from the server variables\n     *\n     * @param Collection $server\n     * @param Collection $headers\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 247,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 247,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 246,
                    "last-line": 270,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkNullArray",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "source",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 271,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "super",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 271,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 273,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 273,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 273,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 273,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "super",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 274,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 275,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 277,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "source",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 277,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 278,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the source if it null and returns the super, otherwise the source\n     * array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 272,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 272,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 271,
                    "last-line": 288,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "createUploadedFile",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 289,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 291,
                                    "char": 17
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 291,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 293,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "or",
                                            "left": {
                                                "type": "not",
                                                "left": {
                                                    "type": "isset",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 293,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "tmp_name",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 293,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 293,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 293,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 293,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "not",
                                                "left": {
                                                    "type": "isset",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 293,
                                                            "char": 58
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "size",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 293,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 293,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 293,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 293,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 293,
                                            "char": 66
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "file",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 293,
                                                        "char": 79
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "error",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 293,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 293,
                                                    "char": 86
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 293,
                                                "char": 86
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 293,
                                            "char": 86
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 293,
                                        "char": 86
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 293,
                                    "char": 88
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 293,
                                "char": 88
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "The file array must contain tmp_name, size and error; ",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 295,
                                                        "char": 72
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "one or more are missing",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 297,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 297,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 297,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 297,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 298,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 300,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 300,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 300,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 300,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 300,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 300,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 300,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 300,
                                            "char": 50
                                        },
                                        "extra": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 300,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 300,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 300,
                                    "char": 56
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "type",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 301,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 301,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 301,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 301,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 301,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 301,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 301,
                                            "char": 50
                                        },
                                        "extra": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 301,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 301,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 301,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 303,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "UploadedFile",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 304,
                                                "char": 17
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "tmp_name",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 304,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 304,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 304,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 305,
                                                "char": 17
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "size",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 305,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 305,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 305,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 306,
                                                "char": 17
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "error",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 306,
                                                "char": 23
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 306,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 306,
                                        "char": 24
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 307,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 307,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 309,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 309,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 309,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 310,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create an UploadedFile object from an $_FILES array element\n     *\n     * @param array $file The $_FILES element\n     *\n     * @return UploadedFile\n     *\n     * @throws InvalidArgumentException If one of the elements is missing\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UploadedFile",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 290,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 290,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 290,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 289,
                    "last-line": 320,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 321,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 321,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 321,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 321,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 321,
                            "char": 90
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 323,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 325,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 325,
                                            "char": 29
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 325,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 325,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "defaultValue",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 325,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 325,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 325,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 325,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 327,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 327,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 327,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 327,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 327,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "implode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": ",",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 328,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 328,
                                                        "char": 34
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 328,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 328,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 328,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 328,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 329,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 331,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 331,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 332,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a header\n     *\n     * @param Collection $headers\n     * @param string     $name\n     * @param mixed|null $defaultValue\n     *\n     * @return mixed|string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 322,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 322,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 321,
                    "last-line": 341,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "parseCookieHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cookieHeader",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 342,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cookies",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 344,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 346,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cookies",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 346,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 346,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 347,
                            "char": 17
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "parse_str",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "strtr",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "cookieHeader",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 349,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 349,
                                                    "char": 29
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "&",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 351,
                                                                    "char": 23
                                                                },
                                                                "value": {
                                                                    "type": "string",
                                                                    "value": "%26",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 351,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 351,
                                                                "char": 28
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "+",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 352,
                                                                    "char": 23
                                                                },
                                                                "value": {
                                                                    "type": "string",
                                                                    "value": "%2B",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 352,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 352,
                                                                "char": 28
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": ";",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 353,
                                                                    "char": 23
                                                                },
                                                                "value": {
                                                                    "type": "string",
                                                                    "value": "&",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 354,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 354,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 355,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 355,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 355,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 355,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cookies",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 357,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 357,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 357,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 359,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "cookies",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 359,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 360,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Parse a cookie header according to RFC 6265.\n     *\n     * @param string $cookieHeader A string cookie header value.\n     *\n     * @return array key\/value cookie pairs.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 343,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 343,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 342,
                    "last-line": 368,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "parseHeaders",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 369,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 369,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 371,
                                    "char": 20
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 371,
                                    "char": 25
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 371,
                                    "char": 31
                                },
                                {
                                    "variable": "serverArray",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 371,
                                    "char": 44
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 371,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 376,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 376,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 376,
                                    "char": 43
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "serverArray",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "server",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 377,
                                            "char": 34
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 377,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 377,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 379,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "serverArray",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 379,
                                "char": 39
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "likely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 380,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 380,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 380,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 380,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "strpos",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 385,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 385,
                                                                "char": 39
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "REDIRECT_",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 385,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 385,
                                                                "char": 50
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 385,
                                                        "char": 54
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 385,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 385,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 385,
                                                "char": 58
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "key",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "substr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "key",
                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                            "line": 386,
                                                                            "char": 41
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 386,
                                                                        "char": 41
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "int",
                                                                            "value": "9",
                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                            "line": 386,
                                                                            "char": 44
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 386,
                                                                        "char": 44
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 386,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 386,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 391,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "list",
                                                            "left": {
                                                                "type": "identical",
                                                                "left": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 391,
                                                                    "char": 41
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "server",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 391,
                                                                        "char": 50
                                                                    },
                                                                    "name": "has",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "key",
                                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                "line": 391,
                                                                                "char": 58
                                                                            },
                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                            "line": 391,
                                                                            "char": 58
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 391,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 391,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 391,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 391,
                                                        "char": 61
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 393,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 394,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 396,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "likely",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "strpos",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 396,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 396,
                                                                "char": 37
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "HTTP_",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 396,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 396,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 396,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 396,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 396,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 396,
                                                "char": 52
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "name",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_replace",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "_",
                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                            "line": 398,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 398,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "-",
                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                            "line": 399,
                                                                            "char": 26
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 399,
                                                                        "char": 26
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "fcall",
                                                                            "name": "strtolower",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "fcall",
                                                                                        "name": "substr",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "variable",
                                                                                                    "value": "key",
                                                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                                    "line": 400,
                                                                                                    "char": 46
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                                "line": 400,
                                                                                                "char": 46
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "int",
                                                                                                    "value": "5",
                                                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                                    "line": 400,
                                                                                                    "char": 49
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                                "line": 400,
                                                                                                "char": 49
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                        "line": 400,
                                                                                        "char": 50
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                    "line": 400,
                                                                                    "char": 50
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                            "line": 401,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 401,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 401,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 401,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 403,
                                                    "char": 27
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "headers",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 403,
                                                            "char": 29
                                                        },
                                                        "name": "set",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 403,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 403,
                                                                "char": 38
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 403,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 403,
                                                                "char": 45
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 403,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 404,
                                                    "char": 28
                                                },
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 405,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 407,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "strpos",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 407,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 407,
                                                                "char": 39
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "CONTENT_",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 407,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 407,
                                                                "char": 49
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 407,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 407,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 407,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 407,
                                                "char": 57
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "name",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "content-",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 408,
                                                                    "char": 41
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "strtolower",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "fcall",
                                                                                "name": "substr",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "key",
                                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                            "line": 408,
                                                                                            "char": 64
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                        "line": 408,
                                                                                        "char": 64
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "int",
                                                                                            "value": "8",
                                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                            "line": 408,
                                                                                            "char": 67
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                        "line": 408,
                                                                                        "char": 67
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                                "line": 408,
                                                                                "char": 68
                                                                            },
                                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                            "line": 408,
                                                                            "char": 68
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 408,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 408,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 408,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 410,
                                                    "char": 27
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "headers",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 410,
                                                            "char": 29
                                                        },
                                                        "name": "set",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 410,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 410,
                                                                "char": 38
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 410,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 410,
                                                                "char": 45
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 410,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 411,
                                                    "char": 28
                                                },
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 412,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 413,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 414,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 416,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "headers",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 416,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 417,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Processes headers from SAPI\n     *\n     * @param Collection $server\n     *\n     * @return Collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 370,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 370,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 370,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 369,
                    "last-line": 427,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "parseServer",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 428,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 430,
                                    "char": 23
                                },
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 430,
                                    "char": 32
                                },
                                {
                                    "variable": "headersCollection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 430,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 432,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 432,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 432,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 432,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 432,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 433,
                                            "char": 31
                                        },
                                        "name": "getHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 433,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 433,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 435,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 435,
                                                    "char": 34
                                                },
                                                "name": "has",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "HTTP_AUTHORIZATION",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 435,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 435,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 435,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 435,
                                            "char": 60
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 435,
                                                "char": 70
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 435,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 435,
                                            "char": 79
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 435,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 435,
                                    "char": 81
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 435,
                                "char": 81
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "headersCollection",
                                            "expr": {
                                                "type": "new",
                                                "class": "Collection",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "headers",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 436,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 436,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 436,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 436,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 438,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "likely",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "headersCollection",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 438,
                                                "char": 41
                                            },
                                            "name": "has",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "Authorization",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 438,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 438,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 438,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 438,
                                        "char": 61
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 439,
                                                    "char": 28
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "HTTP_AUTHORIZATION",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 440,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 440,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "headersCollection",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 441,
                                                                "char": 39
                                                            },
                                                            "name": "get",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "Authorization",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 441,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 441,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 442,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 442,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 442,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 443,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 444,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 446,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 446,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 447,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Parse the $_SERVER array amd return it back after looking for the\n     * authorization header\n     *\n     * @param array $server Either verbatim, or with an added\n     *                      HTTP_AUTHORIZATION header.\n     *\n     * @return Collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 429,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 429,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 429,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 428,
                    "last-line": 456,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "parseUploadedFiles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "files",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 457,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 459,
                                    "char": 23
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 459,
                                    "char": 29
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 459,
                                    "char": 34
                                },
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 459,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 461,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 461,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 461,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 466,
                            "char": 12
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "files",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 466,
                                "char": 33
                            },
                            "key": "key",
                            "value": "file",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "key",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 467,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 467,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 467,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 472,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 472,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 472,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 472,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 472,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "instanceof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "file",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 472,
                                                        "char": 66
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "UploadedFileInterface",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 472,
                                                        "char": 89
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 472,
                                                    "char": 89
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 472,
                                                "char": 89
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 472,
                                            "char": 91
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 472,
                                        "char": 91
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 473,
                                                    "char": 28
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 473,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 473,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 473,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 473,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 473,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 474,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 475,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 480,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "likely",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 480,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 480,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 480,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 480,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "isset",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 480,
                                                            "char": 59
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "tmp_name",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 480,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 480,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 480,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 480,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 480,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 480,
                                        "char": 71
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 481,
                                                    "char": 28
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 481,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 481,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 481,
                                                                "char": 43
                                                            },
                                                            "name": "createUploadedFile",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "file",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 481,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 481,
                                                                    "char": 67
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 481,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 481,
                                                        "char": 68
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 481,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 482,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 483,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 488,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 488,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 488,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 488,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 488,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 488,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "data",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 489,
                                                            "char": 33
                                                        },
                                                        "name": "parseUploadedFiles",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "file",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 489,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 489,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 489,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 489,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 491,
                                            "char": 26
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 491,
                                                    "char": 28
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 491,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 491,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "data",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 491,
                                                                "char": 43
                                                            },
                                                            "name": "toArray",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 491,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 491,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 491,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 492,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 493,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 494,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 496,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 496,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 497,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Traverses a $_FILES and creates UploadedFile objects from it. It is used\n     * recursively\n     *\n     * @param array $files\n     *\n     * @return Collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 458,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 458,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 458,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 457,
                    "last-line": 506,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "parseUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "server",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 507,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 507,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 507,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 507,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 509,
                                    "char": 17
                                },
                                {
                                    "variable": "query",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 509,
                                    "char": 24
                                },
                                {
                                    "variable": "scheme",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 509,
                                    "char": 32
                                },
                                {
                                    "variable": "split",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 509,
                                    "char": 39
                                },
                                {
                                    "variable": "uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 509,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 511,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uri",
                                    "expr": {
                                        "type": "new",
                                        "class": "Uri",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 511,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 511,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 516,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "scheme",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 516,
                                            "char": 27
                                        },
                                        "name": "calculateUriScheme",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 516,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 516,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "headers",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 516,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 516,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 516,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 516,
                                    "char": 63
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uri",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 517,
                                            "char": 26
                                        },
                                        "name": "withScheme",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "scheme",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 517,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 517,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 517,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 517,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 522,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "split",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 522,
                                            "char": 26
                                        },
                                        "name": "calculateUriHost",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 522,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 522,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "headers",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 522,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 522,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 522,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 522,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 523,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "empty",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "split",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 523,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 523,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 523,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 523,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 523,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 523,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 523,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "uri",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 524,
                                                    "char": 27
                                                },
                                                "name": "withHost",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "split",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 524,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 524,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 524,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 524,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 524,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 524,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 525,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "split",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 525,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 525,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 525,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 525,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 525,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 525,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 525,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "uri",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "uri",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 526,
                                                            "char": 31
                                                        },
                                                        "name": "withPort",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "split",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 526,
                                                                        "char": 46
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                        "line": 526,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                    "line": 526,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 526,
                                                                "char": 49
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 526,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 526,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 527,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 528,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 533,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "path",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 533,
                                            "char": 26
                                        },
                                        "name": "calculateUriPath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 533,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 533,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 533,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 533,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "split",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "#",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 534,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 534,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 534,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 534,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 534,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 534,
                                    "char": 37
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "path",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "?",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 535,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 535,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "split",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 535,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 535,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 535,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 535,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 535,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 535,
                                    "char": 41
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uri",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 536,
                                            "char": 25
                                        },
                                        "name": "withPath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "path",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 536,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 536,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 536,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 536,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 536,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 536,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 538,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "split",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 538,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 538,
                                                "char": 32
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 538,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 538,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 538,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 538,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "uri",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 539,
                                                    "char": 27
                                                },
                                                "name": "withFragment",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "split",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 539,
                                                                "char": 46
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                                "line": 539,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                            "line": 539,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                        "line": 539,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 539,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 539,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 540,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 545,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "query",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 545,
                                            "char": 26
                                        },
                                        "name": "calculateUriQuery",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "server",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 545,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 545,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 545,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 545,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uri",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                            "line": 546,
                                            "char": 25
                                        },
                                        "name": "withQuery",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "query",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                    "line": 546,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                                "line": 546,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                        "line": 546,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 546,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 548,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "uri",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 548,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                            "line": 549,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Calculates the Uri from the server superglobal or the headers\n     *\n     * @param Collection $server\n     * @param Collection $headers\n     *\n     * @return Uri\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                    "line": 508,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                                "line": 508,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                        "line": 508,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
                    "line": 507,
                    "last-line": 550,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
            "line": 31,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequestFactory.zep",
        "line": 31,
        "char": 5
    }
]