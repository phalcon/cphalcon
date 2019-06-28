[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http",
        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "DateTime",
                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                "line": 13,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Response\\HeadersInterface",
                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                "line": 14,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Http\\Response\n *\n * Interface for Phalcon\\Http\\Response\n *",
        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
        "line": 21,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ResponseInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "appendContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 26,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Appends a string to the HTTP response body\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 26,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 26,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 26,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContent",
                    "docblock": "**\n     * Gets the HTTP response body\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 31,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 31,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStatusCode",
                    "docblock": "**\n     * Returns the status code\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 36,
                                "char": 44
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 36,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 36,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHeaders",
                    "docblock": "**\n     * Returns headers set by the user\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "HeadersInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 41,
                                    "char": 55
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 41,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 41,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 41,
                    "last-line": 45,
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
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 46,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Checks if a header exists\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 46,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 46,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isSent",
                    "docblock": "**\n     * Checks if the response was already sent\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 51,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 51,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "redirect",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "location",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 56,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 56,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "externalRedirect",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 56,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 56,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "statusCode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "302",
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 56,
                                "char": 98
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 56,
                            "char": 98
                        }
                    ],
                    "docblock": "**\n     * Redirect by HTTP to another action or URL\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 56,
                                    "char": 122
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 56,
                                "char": 122
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 56,
                        "char": 122
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "resetHeaders",
                    "docblock": "**\n     * Resets all the established headers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 61,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 61,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 61,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 66,
                            "char": 46
                        }
                    ],
                    "docblock": "**\n     * Sets HTTP response body\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 66,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 66,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 66,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 66,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContentLength",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "contentLength",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 71,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Sets the response content-length\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 71,
                                    "char": 79
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 71,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 71,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 71,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContentType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "contentType",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 78,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "charset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 78,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 78,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Sets the response content-type mime, optionally the charset\n     *\n     * @param string charset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 78,
                                    "char": 94
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 78,
                                "char": 94
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 78,
                        "char": 94
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 78,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setExpires",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "datetime",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DateTime",
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 83,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 83,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets output expire time header\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 83,
                                    "char": 75
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 83,
                                "char": 75
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 83,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 83,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFileToSend",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 88,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "attachmentName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 88,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 88,
                            "char": 73
                        }
                    ],
                    "docblock": "**\n     * Sets an attached file to be sent at the end of the request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 88,
                                    "char": 97
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 88,
                                "char": 97
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 88,
                        "char": 97
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 88,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 93,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 93,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Overwrites a header in the response\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 93,
                                    "char": 73
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 93,
                                "char": 73
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 93,
                        "char": 73
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 93,
                    "last-line": 105,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setJsonContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 106,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Sets HTTP response body. The parameter is automatically converted to JSON\n     *\n     *```php\n     * $response->setJsonContent(\n     *     [\n     *         \"status\" => \"OK\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 106,
                                    "char": 67
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 106,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 106,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 106,
                    "last-line": 110,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setNotModified",
                    "docblock": "**\n     * Sends a Not-Modified response\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 111,
                                    "char": 60
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 111,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 111,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 111,
                    "last-line": 115,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRawHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "header",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 116,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Send a raw header to the response\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 116,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 116,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 116,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 116,
                    "last-line": 120,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStatusCode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 121,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 121,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                            "line": 121,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Sets the HTTP response code\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 121,
                                    "char": 90
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 121,
                                "char": 90
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 121,
                        "char": 90
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 121,
                    "last-line": 125,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "send",
                    "docblock": "**\n     * Prints out HTTP response to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 126,
                                    "char": 50
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 126,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 126,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 126,
                    "last-line": 130,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sendCookies",
                    "docblock": "**\n     * Sends cookies to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 131,
                                    "char": 57
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 131,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 131,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 131,
                    "last-line": 135,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sendHeaders",
                    "docblock": "**\n     * Sends headers to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                    "line": 136,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 136,
                                "char": 58
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                                "line": 136,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                        "line": 136,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
                    "line": 136,
                    "last-line": 137,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
            "line": 137,
            "char": 1
        },
        "file": "\/app\/phalcon\/Http\/ResponseInterface.zep",
        "line": 0,
        "char": 0
    }
]