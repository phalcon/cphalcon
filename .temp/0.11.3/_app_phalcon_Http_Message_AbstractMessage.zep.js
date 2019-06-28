[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                "line": 17,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\AbstractCommon",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                "line": 18,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                "line": 19,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Stream",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                "line": 20,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                "line": 21,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                "line": 22,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 26,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Message methods\n *",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 27,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractMessage",
        "abstract": 1,
        "final": 0,
        "extends": "AbstractCommon",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "body",
                    "docblock": "**\n     * Gets the body of the message.\n     *\n     * @var <StreamInterface>\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 34,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 38,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "headers",
                    "docblock": "**\n     * @var <Collection>\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "protocolVersion",
                    "default": {
                        "type": "string",
                        "value": "1.1",
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 51,
                        "char": 37
                    },
                    "docblock": "**\n     * Retrieves the HTTP protocol version as a string.\n     *\n     * The string MUST contain only the HTTP version number (e.g., '1.1',\n     * '1.0').\n     *\n     * @return string HTTP protocol version.\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 51,
                            "char": 43
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 61,
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
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 62,
                            "char": 25
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 76,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 77,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 79,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 79,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 79,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 81,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 81,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "headers",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 81,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 81,
                                    "char": 30
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 81,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 81,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "empty-array",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 81,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 81,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 81,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 82,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieves a message header value by the given case-insensitive name.\n     *\n     * This method returns an array of all the header values of the given\n     * case-insensitive header name.\n     *\n     * If the header does not appear in the message, this method MUST return an\n     * empty array.\n     *\n     * @param string $name\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 78,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 78,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 77,
                    "last-line": 101,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHeaderLine",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 102,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "header",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 104,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 106,
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
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 106,
                                            "char": 27
                                        },
                                        "name": "getHeader",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 106,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 106,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 106,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 106,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 108,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "implode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "char",
                                            "value": ",",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 108,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 108,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "header",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 108,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 108,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 108,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 109,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieves a comma-separated string of the values for a single header.\n     *\n     * This method returns all of the header values of the given\n     * case-insensitive header name as a string concatenated together using\n     * a comma.\n     *\n     * NOTE: Not all header values may be appropriately represented using\n     * comma concatenation. For such headers, use getHeader() instead\n     * and supply your own delimiter when concatenating.\n     *\n     * If the header does not appear in the message, this method MUST return\n     * an empty string.\n     *\n     * @param string $name\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 103,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 103,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 102,
                    "last-line": 133,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHeaders",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 136,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "headers",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 136,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 136,
                                    "char": 30
                                },
                                "name": "toArray",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 136,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 137,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieves all message header values.\n     *\n     * The keys represent the header name as it will be sent over the wire, and\n     * each value is an array of strings associated with the header.\n     *\n     *     \/\/ Represent the headers as a string\n     *     foreach ($message->getHeaders() as $name => $values) {\n     *         echo $name . ': ' . implode(', ', $values);\n     *     }\n     *\n     *     \/\/ Emit headers iteratively:\n     *     foreach ($message->getHeaders() as $name => $values) {\n     *         foreach ($values as $value) {\n     *             header(sprintf('%s: %s', $name, $value), false);\n     *         }\n     *     }\n     *\n     * While header names are not case-sensitive, getHeaders() will preserve the\n     * exact case in which headers were originally specified.\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 134,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 146,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 148,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "headers",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 148,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 148,
                                    "char": 30
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 148,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 148,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 148,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 149,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a header exists by the given case-insensitive name.\n     *\n     * @param string $name\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 147,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 147,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 146,
                    "last-line": 167,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withAddedHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 168,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 168,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "existing",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 170,
                                    "char": 21
                                },
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 170,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 172,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 172,
                                    "char": 14
                                },
                                "name": "checkHeaderName",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 172,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 172,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 172,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 174,
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
                                        "type": "clone",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 174,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 174,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 174,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 174,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 174,
                                    "char": 43
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "existing",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 175,
                                            "char": 32
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 175,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 175,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 175,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 175,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 175,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 175,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 176,
                                            "char": 29
                                        },
                                        "name": "getHeaderValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 176,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 176,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 176,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 176,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "existing",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 177,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 177,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 177,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 177,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 177,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 177,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 179,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 179,
                                    "char": 17
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 179,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 179,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 179,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 179,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 179,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 181,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 181,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 181,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 181,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 181,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 181,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 181,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 182,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified header appended with the given\n     * value.\n     *\n     * Existing values for the specified header will be maintained. The new\n     * value(s) will be appended to the existing list. If the header did not\n     * exist previously, it will be added.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * new header and\/or value.\n     *\n     * @param string          $name\n     * @param string|string[] $value\n     *\n     * @return self\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 169,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 169,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 168,
                    "last-line": 198,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withBody",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "body",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "StreamInterface",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 199,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 199,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "newBody",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 201,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 203,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newBody",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 203,
                                            "char": 28
                                        },
                                        "name": "processBody",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "body",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 203,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 203,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "w+b",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 203,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 203,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 203,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 203,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 205,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 205,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "newBody",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 205,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 205,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "body",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 205,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 205,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 205,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 206,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified message body.\n     *\n     * The body MUST be a StreamInterface object.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return a new instance that has the\n     * new body stream.\n     *\n     * @param StreamInterface $body\n     *\n     * @return self\n     * @throws InvalidArgumentException When the body is not valid.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 200,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 200,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 199,
                    "last-line": 225,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 226,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 226,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 228,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 230,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 230,
                                    "char": 14
                                },
                                "name": "checkHeaderName",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 230,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 230,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 230,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 232,
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
                                        "type": "clone",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 232,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 232,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 232,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 232,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 232,
                                    "char": 42
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 233,
                                            "char": 28
                                        },
                                        "name": "getHeaderValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 233,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 233,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 233,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 233,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 235,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 235,
                                    "char": 17
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 235,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 235,
                                        "char": 26
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 235,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 235,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 235,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 237,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 237,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 237,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 237,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 237,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 237,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 237,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 238,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the provided value replacing the specified\n     * header.\n     *\n     * While header names are case-insensitive, the casing of the header will\n     * be preserved by this function, and returned from getHeaders().\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * new and\/or updated header and value.\n     *\n     * @param string          $name\n     * @param string|string[] $value\n     *\n     * @return self\n     * @throws InvalidArgumentException for invalid header names or values.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 227,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 227,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 226,
                    "last-line": 253,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withProtocolVersion",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "version",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 254,
                            "char": 52
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
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 256,
                                    "char": 14
                                },
                                "name": "processProtocol",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 256,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 256,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 256,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 258,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 258,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 258,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 258,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "protocolVersion",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 258,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 258,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 258,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 259,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified HTTP protocol version.\n     *\n     * The version string MUST contain only the HTTP version number (e.g.,\n     * '1.1', '1.0').\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * new protocol version.\n     *\n     * @param string $version\n     *\n     * @return self\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 255,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 255,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 254,
                    "last-line": 273,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withoutHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 274,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 276,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 278,
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
                                        "type": "clone",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 278,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 278,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 278,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 278,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 278,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 280,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "headers",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 280,
                                    "char": 17
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 280,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 280,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 280,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 282,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 282,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 282,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 282,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 282,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 282,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 282,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 283,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance without the specified header.\n     *\n     * Header resolution MUST be done without case-sensitivity.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that removes\n     * the named header.\n     *\n     * @param string $name\n     *\n     * @return self\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 275,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 275,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 274,
                    "last-line": 293,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkHeaderHost",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 294,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 294,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 296,
                                    "char": 17
                                },
                                {
                                    "variable": "host",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 296,
                                    "char": 23
                                },
                                {
                                    "variable": "hostArray",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 296,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 297,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "header",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 297,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 299,
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
                                            "type": "and",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 299,
                                                    "char": 33
                                                },
                                                "name": "has",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "host",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 299,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 299,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 299,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "not",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                                "line": 300,
                                                                "char": 25
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "uri",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                                "line": 300,
                                                                "char": 29
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 300,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 300,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 300,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 300,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 300,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 301,
                                                "char": 16
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 301,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "uri",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 301,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 301,
                                                    "char": 28
                                                },
                                                "name": "getHost",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 301,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 301,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 301,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 301,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 301,
                                "char": 40
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
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 303,
                                                    "char": 34
                                                },
                                                "name": "getUriHost",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                                "line": 303,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "uri",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                                "line": 303,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 303,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 303,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 303,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 303,
                                            "char": 56
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hostArray",
                                            "expr": {
                                                "type": "variable",
                                                "value": "host",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 304,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 304,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 305,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "host",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 305,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 305,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 305,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 305,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 305,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "hostArray",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "host",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                                    "line": 306,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                                "line": 306,
                                                                "char": 38
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 306,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 306,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 307,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 309,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 309,
                                            "char": 24
                                        },
                                        "name": "remove",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "host",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 309,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 309,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 309,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 311,
                                    "char": 15
                                },
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
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 311,
                                                    "char": 45
                                                },
                                                "name": "toArray",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 311,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 311,
                                            "char": 55
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "header",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 312,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 312,
                                            "char": 36
                                        },
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "header",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "Host",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 313,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "hostArray",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 313,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 313,
                                            "char": 41
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "header",
                                            "expr": {
                                                "type": "add",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "header",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 314,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "cast",
                                                    "left": "array",
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 314,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 314,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 314,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 314,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 316,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 316,
                                            "char": 24
                                        },
                                        "name": "clear",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 316,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 317,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 317,
                                            "char": 24
                                        },
                                        "name": "init",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "header",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 317,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 317,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 317,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 318,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 320,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 320,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 321,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Ensure Host is the first header.\n     *\n     * @see: http:\/\/tools.ietf.org\/html\/rfc7230#section-5.4\n     *\n     * @param Collection $collection\n     *\n     * @return Collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 295,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 295,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 295,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 294,
                    "last-line": 329,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkHeaderName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 330,
                            "char": 54
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
                                        "type": "or",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 332,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 332,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 332,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 332,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "fcall",
                                                "name": "preg_match",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\/^[a-zA-Z0-9'`#$%&*+.^_|~!-]+$\/",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 333,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 333,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 333,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 333,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 333,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 333,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 333,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 333,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 333,
                                "char": 65
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
                                                        "value": "Invalid header name ",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 335,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 336,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 336,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 336,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 336,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 337,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 338,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check the name of the header. Throw exception if not valid\n     *\n     * @see http:\/\/tools.ietf.org\/html\/rfc7230#section-3.2\n     *\n     * @param $name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 331,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 330,
                    "last-line": 386,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkHeaderValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 387,
                            "char": 56
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
                                            "type": "not-identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 389,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 389,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 389,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 389,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 389,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "is_numeric",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 389,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 389,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 389,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 389,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 389,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 389,
                                    "char": 77
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 389,
                                "char": 77
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
                                                    "value": "Invalid header value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 390,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 390,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 390,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 391,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 393,
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
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 393,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 393,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 393,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 395,
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
                                            "type": "fcall",
                                            "name": "preg_match",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "#(?:(?:(?<!\\r)\\n)|(?:\\r(?!\\n))|(?:\\r\\n(?![ \\t])))#",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 395,
                                                        "char": 83
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 395,
                                                    "char": 83
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 395,
                                                        "char": 90
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 395,
                                                    "char": 90
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 395,
                                            "char": 93
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "preg_match",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "\/[^\\x09\\x0a\\x0d\\x20-\\x7E\\x80-\\xFE]\/",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 396,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 396,
                                                    "char": 59
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 396,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 396,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 396,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 396,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 396,
                                    "char": 69
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 396,
                                "char": 69
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
                                                    "value": "Invalid header value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 397,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 397,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 397,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 398,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 399,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Validates a header value\n     *\n     * Most HTTP header field values are defined using common syntax\n     * components (token, quoted-string, and comment) separated by\n     * whitespace or specific delimiting characters.  Delimiters are chosen\n     * from the set of US-ASCII visual characters not allowed in a token\n     * (DQUOTE and '(),\/:;<=>?@[\\]{}').\n     *\n     *     token          = 1*tchar\n     *\n     *     tchar          = '!' \/ '#' \/ '$' \/ '%' \/ '&' \/ ''' \/ '*'\n     *                    \/ '+' \/ '-' \/ '.' \/ '^' \/ '_' \/ '`' \/ '|' \/ '~'\n     *                    \/ DIGIT \/ ALPHA\n     *                    ; any VCHAR, except delimiters\n     *\n     * A string of text is parsed as a single value if it is quoted using\n     * double-quote marks.\n     *\n     *     quoted-string  = DQUOTE *( qdtext \/ quoted-pair ) DQUOTE\n     *     qdtext         = HTAB \/ SP \/%x21 \/ %x23-5B \/ %x5D-7E \/ obs-text\n     *     obs-text       = %x80-FF\n     *\n     * Comments can be included in some HTTP header fields by surrounding\n     * the comment text with parentheses.  Comments are only allowed in\n     * fields containing 'comment' as part of their field value definition.\n     *\n     *     comment        = '(' *( ctext \/ quoted-pair \/ comment ) ')'\n     *     ctext          = HTAB \/ SP \/ %x21-27 \/ %x2A-5B \/ %x5D-7E \/ obs-text\n     *\n     * The backslash octet ('\\') can be used as a single-octet quoting\n     * mechanism within quoted-string and comment constructs.  Recipients\n     * that process the value of a quoted-string MUST handle a quoted-pair\n     * as if it were replaced by the octet following the backslash.\n     *\n     *     quoted-pair    = '\\' ( HTAB \/ SP \/ VCHAR \/ obs-text )\n     *\n     * A sender SHOULD NOT generate a quoted-pair in a quoted-string except\n     * where necessary to quote DQUOTE and backslash octets occurring within\n     * that string.  A sender SHOULD NOT generate a quoted-pair in a comment\n     * except where necessary to quote parentheses ['(' and ')'] and\n     * backslash octets occurring within that comment.\n     *\n     * @see https:\/\/tools.ietf.org\/html\/rfc7230#section-3.2.6\n     *\n     * @param $value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 388,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 387,
                    "last-line": 407,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getHeaderValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 408,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 410,
                                    "char": 18
                                },
                                {
                                    "variable": "valueArray",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 410,
                                    "char": 30
                                },
                                {
                                    "variable": "valueData",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 410,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 412,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "valueArray",
                                    "expr": {
                                        "type": "variable",
                                        "value": "values",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 412,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 412,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 413,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "values",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 413,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 413,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 413,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 413,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 413,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "valueArray",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "values",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 414,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 414,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 414,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 414,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 415,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 417,
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
                                            "value": "valueArray",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 417,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 417,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 417,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 417,
                                "char": 39
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
                                                        "value": "Invalid header value: must be a string or ",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 419,
                                                        "char": 60
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array of strings; cannot be an empty array",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 421,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 421,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 421,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 421,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 422,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 424,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "valueData",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 424,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 424,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 425,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "valueArray",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 425,
                                "char": 33
                            },
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 426,
                                            "char": 18
                                        },
                                        "name": "checkHeaderValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 426,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 426,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 426,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 428,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "valueData",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 428,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 428,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 428,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 429,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 431,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "valueData",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 431,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 432,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the header values checked for validity\n     *\n     * @param $values\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 409,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 409,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 408,
                    "last-line": 440,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getUriHost",
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
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 441,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 441,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "host",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 443,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 445,
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
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 445,
                                            "char": 24
                                        },
                                        "name": "getHost",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 445,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 445,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 447,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 447,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 447,
                                            "char": 34
                                        },
                                        "name": "getPort",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 447,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 447,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 447,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "host",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": ":",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 448,
                                                    "char": 26
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "uri",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 448,
                                                        "char": 32
                                                    },
                                                    "name": "getPort",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 448,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 448,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 448,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 449,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 451,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "host",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 451,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 452,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the host and if applicable the port\n     *\n     * @param UriInterface $uri\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 442,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 442,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 441,
                    "last-line": 460,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "populateHeaderCollection",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 461,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 463,
                                    "char": 23
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 463,
                                    "char": 29
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 463,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 465,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 465,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 465,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 466,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "headers",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 466,
                                "char": 36
                            },
                            "key": "name",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 467,
                                            "char": 18
                                        },
                                        "name": "checkHeaderName",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 467,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 467,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 467,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 469,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "name",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 469,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 469,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 469,
                                            "char": 38
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 470,
                                                    "char": 30
                                                },
                                                "name": "getHeaderValue",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 470,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 470,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 470,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 470,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 472,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 472,
                                            "char": 24
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 472,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 472,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 472,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 472,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 472,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 473,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 475,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 475,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 476,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Populates the header collection\n     *\n     * @param array $headers\n     *\n     * @return Collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 462,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 462,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 462,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 461,
                    "last-line": 485,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "processBody",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "body",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "php:\/\/memory",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 486,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 486,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "mode",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "r+b",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 486,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 486,
                            "char": 85
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
                                                    "value": "body",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 488,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 488,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 488,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 488,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "body",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 488,
                                                "char": 62
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "StreamInterface",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 488,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 488,
                                            "char": 79
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 488,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 488,
                                    "char": 81
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 488,
                                "char": 81
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "body",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 489,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 490,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 492,
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
                                            "type": "not-identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "body",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 492,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 492,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 492,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 492,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "body",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 492,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 492,
                                                "char": 62
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "resource",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 492,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 492,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 492,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 492,
                                    "char": 74
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 492,
                                "char": 74
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
                                                    "value": "Invalid stream passed as a parameter",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 495,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 495,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 495,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 496,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 498,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Stream",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "body",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 498,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 498,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "mode",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 498,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 498,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 498,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 499,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set a valid stream\n     *\n     * @param StreamInterface|resource|string $body\n     * @param string                          $mode\n     *\n     * @return StreamInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "StreamInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 487,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 487,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 487,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 486,
                    "last-line": 507,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "processHeaders",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 508,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 510,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 512,
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
                                            "value": "headers",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 512,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 512,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 512,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 512,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 512,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 513,
                                                    "char": 35
                                                },
                                                "name": "populateHeaderCollection",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "headers",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 513,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 513,
                                                        "char": 68
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 513,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 513,
                                            "char": 69
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 514,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 514,
                                                    "char": 35
                                                },
                                                "name": "checkHeaderHost",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "collection",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 514,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 514,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 514,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 514,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 515,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
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
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "headers",
                                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                                "line": 516,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 516,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 516,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 516,
                                                        "char": 54
                                                    },
                                                    "right": {
                                                        "type": "instanceof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "headers",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 516,
                                                            "char": 73
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "Collection",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 516,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 516,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 516,
                                                    "char": 85
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 516,
                                                "char": 87
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 516,
                                            "char": 87
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 516,
                                        "char": 87
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
                                                            "value": "Headers needs to be either an array or instance of Phalcon\\\\Collection\\\\Collection",
                                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                            "line": 519,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 519,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 519,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 520,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 522,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "variable",
                                                "value": "headers",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 522,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 522,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 523,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 525,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 525,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 526,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the headers\n     *\n     * @param $headers\n     *\n     * @return Collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 509,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 509,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 509,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 508,
                    "last-line": 534,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "processProtocol",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "protocol",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 535,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 535,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "protocols",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 537,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 539,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "protocols",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "1.0",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 540,
                                                    "char": 17
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 540,
                                                    "char": 20
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 540,
                                                "char": 20
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "1.1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 541,
                                                    "char": 17
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 541,
                                                    "char": 20
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 541,
                                                "char": 20
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "2.0",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 542,
                                                    "char": 17
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 542,
                                                    "char": 20
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 542,
                                                "char": 20
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "3.0",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 543,
                                                    "char": 17
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 544,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 544,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 544,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 544,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 546,
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
                                            "type": "empty",
                                            "left": {
                                                "type": "list",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "protocol",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 546,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 546,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 546,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "protocol",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 546,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 546,
                                                "char": 59
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 546,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 546,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 546,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 546,
                                    "char": 69
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 546,
                                "char": 69
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
                                                    "value": "Invalid protocol value",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 547,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 547,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 547,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 548,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 550,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "protocols",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 550,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "protocol",
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 550,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                            "line": 550,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 550,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 550,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 550,
                                "char": 48
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
                                                        "value": "Unsupported protocol ",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 552,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "protocol",
                                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                        "line": 553,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                    "line": 553,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                                "line": 553,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                        "line": 553,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                    "line": 554,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 556,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "protocol",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 556,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                            "line": 557,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the protocol\n     *\n     * @param string $protocol\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                                "line": 536,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                        "line": 536,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
                    "line": 535,
                    "last-line": 558,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
            "line": 27,
            "char": 14
        },
        "file": "\/app\/phalcon\/Http\/Message\/AbstractMessage.zep",
        "line": 27,
        "char": 14
    }
]