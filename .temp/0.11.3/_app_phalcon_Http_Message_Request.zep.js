[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Stream\\Input",
                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                "line": 17,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\AbstractRequest",
                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\RequestInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                "line": 19,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                "line": 20,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                "line": 21,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-7 Request\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Request",
        "abstract": 0,
        "final": 1,
        "extends": "AbstractRequest",
        "implements": [
            {
                "type": "variable",
                "value": "RequestInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                "line": 27,
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
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "GET",
                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                "line": 37,
                                "char": 28
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                            "line": 37,
                            "char": 28
                        },
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                "line": 38,
                                "char": 23
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                            "line": 38,
                            "char": 23
                        },
                        {
                            "type": "parameter",
                            "name": "body",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "php:\/\/memory",
                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                "line": 39,
                                "char": 32
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                            "line": 39,
                            "char": 32
                        },
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                "line": 41,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                            "line": 41,
                            "char": 5
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
                                        "type": "string",
                                        "value": "php:\/\/input",
                                        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                        "line": 42,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "body",
                                        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                        "line": 42,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                    "line": 42,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                "line": 42,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "body",
                                            "expr": {
                                                "type": "new",
                                                "class": "Input",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                "line": 43,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                            "line": 43,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                    "line": 44,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                            "line": 46,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "uri",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                            "line": 46,
                                            "char": 34
                                        },
                                        "name": "processUri",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                    "line": 46,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                "line": 46,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                        "line": 46,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                    "line": 46,
                                    "char": 50
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "headers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                            "line": 47,
                                            "char": 34
                                        },
                                        "name": "processHeaders",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "headers",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                    "line": 47,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                "line": 47,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                        "line": 47,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                    "line": 47,
                                    "char": 58
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "method",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                            "line": 48,
                                            "char": 34
                                        },
                                        "name": "processMethod",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                    "line": 48,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                "line": 48,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                        "line": 48,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                    "line": 48,
                                    "char": 56
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "body",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                            "line": 49,
                                            "char": 34
                                        },
                                        "name": "processBody",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "body",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                    "line": 49,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                "line": 49,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "w+b",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                    "line": 49,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                                "line": 49,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                        "line": 49,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                                    "line": 49,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                            "line": 50,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Request constructor.\n     *\n     * @param string                          $method\n     * @param UriInterface|string|null        $uri\n     * @param StreamInterface|resource|string $body\n     * @param array                           $headers\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
                    "line": 36,
                    "last-line": 51,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
            "line": 26,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/Request.zep",
        "line": 26,
        "char": 11
    }
]