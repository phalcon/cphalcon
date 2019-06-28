[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                "line": 17,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\AbstractMessage",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                "line": 19,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Uri",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                "line": 20,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                "line": 21,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Request methods\n *",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 26,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractRequest",
        "abstract": 1,
        "final": 0,
        "extends": "AbstractMessage",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "method",
                    "default": {
                        "type": "string",
                        "value": "GET",
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                        "line": 33,
                        "char": 28
                    },
                    "docblock": "**\n     * Retrieves the HTTP method of the request.\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 33,
                            "char": 34
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "requestTarget",
                    "docblock": "**\n     * The request-target, if it has been provided or calculated.\n     *\n     * @var null|string\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "uri",
                    "docblock": "**\n     * Retrieves the URI instance.\n     *\n     * This method MUST return a UriInterface instance.\n     *\n     * @see http:\/\/tools.ietf.org\/html\/rfc3986#section-4.3\n     *\n     * @var UriInterface\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 51,
                            "char": 25
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 65,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRequestTarget",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "requestTarget",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 68,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 70,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "requestTarget",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 70,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "requestTarget",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 70,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 70,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 70,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 72,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 72,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "requestTarget",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 72,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 72,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 72,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "requestTarget",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 73,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "uri",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 73,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 73,
                                                    "char": 43
                                                },
                                                "name": "getPath",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 73,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 73,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 75,
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
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                                "line": 75,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "uri",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                                "line": 75,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                            "line": 75,
                                                            "char": 42
                                                        },
                                                        "name": "getQuery",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 75,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 75,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 75,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 75,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 75,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "requestTarget",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "?",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                            "line": 76,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                                    "line": 76,
                                                                    "char": 46
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "uri",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                                    "line": 76,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                                "line": 76,
                                                                "char": 51
                                                            },
                                                            "name": "getQuery",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                            "line": 76,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 76,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 76,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 77,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 79,
                                    "char": 14
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
                                                    "value": "requestTarget",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 79,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 79,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 79,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 79,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "requestTarget",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "\/",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 80,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 80,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 81,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 84,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "requestTarget",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 84,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 85,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieves the message's request target.\n     *\n     * Retrieves the message's request-target either as it will appear (for\n     * clients), as it appeared at request (for servers), or as it was\n     * specified for the instance (see withRequestTarget()).\n     *\n     * In most cases, this will be the origin-form of the composed URI, unless a\n     * value was provided to the concrete implementation (see\n     * withRequestTarget() below).\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 66,
                    "last-line": 103,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 104,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 106,
                                    "char": 14
                                },
                                "name": "processMethod",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 106,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 106,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 106,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 108,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 108,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 108,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 108,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 108,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 108,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 108,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 109,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the provided HTTP method.\n     *\n     * While HTTP method names are typically all uppercase characters, HTTP\n     * method names are case-sensitive and thus implementations SHOULD NOT\n     * modify the given string.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * changed request method.\n     *\n     * @param string $method\n     *\n     * @return object\n     * @throws InvalidArgumentException for invalid HTTP methods.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 105,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                        "line": 105,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 104,
                    "last-line": 129,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withRequestTarget",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "requestTarget",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 130,
                            "char": 56
                        }
                    ],
                    "statements": [
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
                                                "value": "\/\\s\/",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 132,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 132,
                                            "char": 36
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "requestTarget",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 132,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 132,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 132,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 132,
                                "char": 53
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
                                                    "type": "string",
                                                    "value": "Invalid request target: cannot contain whitespace",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 135,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 135,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 135,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 136,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 138,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 138,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "requestTarget",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 138,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 138,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "requestTarget",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 138,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 138,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 138,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 139,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specific request-target.\n     *\n     * If the request needs a non-origin-form request-target \u2014 e.g., for\n     * specifying an absolute-form, authority-form, or asterisk-form \u2014\n     * this method may be used to create an instance with the specified\n     * request-target, verbatim.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * changed request target.\n     *\n     * @see http:\/\/tools.ietf.org\/html\/rfc7230#section-5.3 (for the various\n     *     request-target forms allowed in request messages)\n     *\n     * @param mixed $requestTarget\n     *\n     * @return object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 131,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                        "line": 131,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 130,
                    "last-line": 173,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "UriInterface",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 174,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 174,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "preserveHost",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 174,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 174,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 176,
                                    "char": 20
                                },
                                {
                                    "variable": "newInstance",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 176,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 178,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "preserveHost",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "variable",
                                            "value": "preserveHost",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 178,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 178,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 178,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "headers",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 179,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 179,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 179,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 179,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 179,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newInstance",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 180,
                                            "char": 37
                                        },
                                        "name": "cloneInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 180,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 180,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 180,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 180,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 180,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 180,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 182,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "variable",
                                        "value": "preserveHost",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 182,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 182,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 182,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "headers",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 183,
                                                    "char": 32
                                                },
                                                "name": "checkHeaderHost",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "headers",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                            "line": 183,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 183,
                                                        "char": 56
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 183,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 183,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 185,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "newInstance",
                                            "property": "headers",
                                            "expr": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 185,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 185,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 186,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 188,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "newInstance",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 188,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 189,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an instance with the provided URI.\n     *\n     * This method MUST update the Host header of the returned request by\n     * default if the URI contains a host component. If the URI does not\n     * contain a host component, any pre-existing Host header MUST be carried\n     * over to the returned request.\n     *\n     * You can opt-in to preserving the original state of the Host header by\n     * setting `$preserveHost` to `true`. When `$preserveHost` is set to\n     * `true`, this method interacts with the Host header in the following\n     * ways:\n     *\n     * - If the Host header is missing or empty, and the new URI contains\n     *   a host component, this method MUST update the Host header in the\n     *   returned request.\n     * - If the Host header is missing or empty, and the new URI does not\n     * contain a host component, this method MUST NOT update the Host header in\n     * the returned request.\n     * - If a Host header is present and non-empty, this method MUST NOT update\n     *   the Host header in the returned request.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * new UriInterface instance.\n     *\n     * @see http:\/\/tools.ietf.org\/html\/rfc3986#section-4.3\n     *\n     * @param UriInterface $uri\n     * @param bool         $preserveHost\n     *\n     * @return object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 175,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 174,
                    "last-line": 197,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "processMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 198,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 198,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "methods",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 200,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 202,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "methods",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "GET",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 203,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 203,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 203,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "CONNECT",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 204,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 204,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 204,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "DELETE",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 205,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 205,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 205,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "HEAD",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 206,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 206,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 206,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "OPTIONS",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 207,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 207,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 207,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "PATCH",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 208,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 208,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 208,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "POST",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 209,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 209,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 209,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "PUT",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 210,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 210,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 210,
                                                "char": 24
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "TRACE",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 211,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 212,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 212,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 212,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 212,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 214,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "list",
                                        "left": {
                                            "type": "and",
                                            "left": {
                                                "type": "and",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "empty",
                                                        "left": {
                                                            "type": "list",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "method",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                                "line": 214,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                            "line": 214,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 214,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 214,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "method",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                            "line": 215,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 215,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 215,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 215,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 215,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "methods",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 216,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "method",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 216,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 216,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 216,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 216,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 216,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 216,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 216,
                                "char": 36
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
                                                        "value": "Invalid or unsupported method ",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 218,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "method",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                        "line": 219,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 219,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 219,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 219,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 220,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 222,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "method",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 222,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 223,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check the method\n     *\n     * @param string $method\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 199,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                        "line": 199,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 198,
                    "last-line": 231,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "processUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 232,
                            "char": 48
                        }
                    ],
                    "statements": [
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
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 234,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 234,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 234,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 234,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "uri",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 234,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "UriInterface",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 234,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 234,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 234,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 234,
                                    "char": 76
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 234,
                                "char": 76
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "uri",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 235,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 236,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 238,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 238,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 238,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 238,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 238,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 238,
                                "char": 41
                            },
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
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                    "line": 239,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                                "line": 239,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 239,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 240,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 242,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 242,
                                    "char": 19
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 242,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 242,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "new",
                                        "class": "Uri",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 243,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 244,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 246,
                            "char": 13
                        },
                        {
                            "type": "throw",
                            "expr": {
                                "type": "new",
                                "class": "InvalidArgumentException",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Invalid uri passed as a parameter",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                            "line": 248,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                        "line": 248,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 248,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                            "line": 249,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a valid Uri\n     *\n     * @param UriInterface|string|null $uri\n     *\n     * @return UriInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UriInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                    "line": 233,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                                "line": 233,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                        "line": 233,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
                    "line": 232,
                    "last-line": 250,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
            "line": 26,
            "char": 14
        },
        "file": "\/app\/phalcon\/Http\/Message\/AbstractRequest.zep",
        "line": 26,
        "char": 14
    }
]