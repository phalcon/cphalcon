[
    {
        "type": "comment",
        "value": "**\n* This file is part of the Phalcon Framework.\n*\n* (c) Phalcon Team <team@phalconphp.com>\n*\n* For the full copyright and license information, please view the LICENSE.txt\n* file that was distributed with this source code.\n*\n* Implementation of this file has been influenced by Zend Diactoros\n* @link    https:\/\/github.com\/zendframework\/zend-diactoros\n* @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n*",
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 17,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\AbstractRequest",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 19,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Stream\\Input",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 20,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\ServerRequestInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 21,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 22,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UploadedFileInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 23,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 24,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 28,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-7 ServerRequest\n *",
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 29,
        "char": 5
    },
    {
        "type": "class",
        "name": "ServerRequest",
        "abstract": 0,
        "final": 1,
        "extends": "AbstractRequest",
        "implements": [
            {
                "type": "variable",
                "value": "ServerRequestInterface",
                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                "line": 30,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "attributes",
                    "docblock": "**\n     * @var Collection\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 45,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "cookieParams",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 46,
                        "char": 31
                    },
                    "docblock": "**\n     * Retrieve cookies.\n     *\n     * Retrieves cookies sent by the client to the server.\n     *\n     * The data MUST be compatible with the structure of the $_COOKIE\n     * superglobal.\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 46,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 61,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "parsedBody",
                    "docblock": "**\n     * Retrieve any parameters provided in the request body.\n     *\n     * If the request Content-Type is either application\/x-www-form-urlencoded\n     * or multipart\/form-data, and the request method is POST, this method MUST\n     * return the contents of $_POST.\n     *\n     * Otherwise, this method may return any results of deserializing\n     * the request body content; as parsing returns structured content, the\n     * potential types MUST be arrays or objects only. A null value indicates\n     * the absence of body content.\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 62,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 75,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "queryParams",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 76,
                        "char": 30
                    },
                    "docblock": "**\n     * Retrieve query string arguments.\n     *\n     * Retrieves the deserialized query string arguments, if any.\n     *\n     * Note: the query params might not be in sync with the URI or server\n     * params. If you need to ensure you are only getting the original\n     * values, you may need to parse the query string from\n     * `getUri()->getQuery()` or from the `QUERY_STRING` server param.\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 76,
                            "char": 36
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 86,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "serverParams",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 87,
                        "char": 31
                    },
                    "docblock": "**\n     * Retrieve server parameters.\n     *\n     * Retrieves data related to the incoming request environment,\n     * typically derived from PHP's $_SERVER superglobal. The data IS NOT\n     * REQUIRED to originate from $_SERVER.\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 87,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 99,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "uploadedFiles",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 100,
                        "char": 32
                    },
                    "docblock": "**\n     * Retrieve normalized file upload data.\n     *\n     * This method returns upload metadata in a normalized tree, with each leaf\n     * an instance of Psr\\Http\\Message\\UploadedFileInterface.\n     *\n     * These values MAY be prepared from $_FILES or the message body during\n     * instantiation, or MAY be injected via withUploadedFiles().\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 100,
                            "char": 38
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 115,
                    "char": 6
                }
            ],
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
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 117,
                                "char": 28
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 117,
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
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 118,
                                "char": 23
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 118,
                            "char": 23
                        },
                        {
                            "type": "parameter",
                            "name": "serverParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 119,
                                "char": 32
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 119,
                            "char": 32
                        },
                        {
                            "type": "parameter",
                            "name": "body",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "php:\/\/input",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 120,
                                "char": 31
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 120,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "headers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 121,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 121,
                            "char": 25
                        },
                        {
                            "type": "parameter",
                            "name": "cookies",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 122,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 122,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "queryParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 123,
                                "char": 31
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 123,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "uploadFiles",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 124,
                                "char": 31
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 124,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "parsedBody",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 125,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 125,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "protocol",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "1.1",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 127,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 127,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 128,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "body",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 128,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 128,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 128,
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
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 129,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 129,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 130,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 132,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 132,
                                    "char": 14
                                },
                                "name": "checkUploadedFiles",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uploadFiles",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 132,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 132,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 132,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 134,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "protocolVersion",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 134,
                                            "char": 42
                                        },
                                        "name": "processProtocol",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "protocol",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 134,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 134,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 134,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 134,
                                    "char": 68
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
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 135,
                                            "char": 42
                                        },
                                        "name": "processMethod",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 135,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 135,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 135,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 135,
                                    "char": 64
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
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 136,
                                            "char": 42
                                        },
                                        "name": "processHeaders",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "headers",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 136,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 136,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 136,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 136,
                                    "char": 66
                                },
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
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 137,
                                            "char": 42
                                        },
                                        "name": "processUri",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 137,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 137,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 137,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 137,
                                    "char": 58
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
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 138,
                                            "char": 42
                                        },
                                        "name": "processBody",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "body",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 138,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 138,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "w+b",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 138,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 138,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 138,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 138,
                                    "char": 65
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "uploadedFiles",
                                    "expr": {
                                        "type": "variable",
                                        "value": "uploadFiles",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 139,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 139,
                                    "char": 48
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "parsedBody",
                                    "expr": {
                                        "type": "variable",
                                        "value": "parsedBody",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 140,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 140,
                                    "char": 47
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "serverParams",
                                    "expr": {
                                        "type": "variable",
                                        "value": "serverParams",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 141,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 141,
                                    "char": 49
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "cookieParams",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cookies",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 142,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 142,
                                    "char": 44
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "queryParams",
                                    "expr": {
                                        "type": "variable",
                                        "value": "queryParams",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 143,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 143,
                                    "char": 48
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "attributes",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 144,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 144,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 145,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * ServerRequest constructor.\n     *\n     * @param string                   $method\n     * @param UriInterface|string|null $uri\n     * @param array                    $serverParams\n     * @param StreamInterface|string   $body\n     * @param array                    $headers\n     * @param array                    $cookies\n     * @param array                    $queryParams\n     * @param array                    $uploadFiles\n     * @param null|array|object        $parsedBody\n     * @param string                   $protocol\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 116,
                    "last-line": 161,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 162,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 162,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 162,
                            "char": 67
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
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 164,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 164,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 164,
                                    "char": 33
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 164,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 164,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 164,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 164,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 164,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 165,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieve a single derived request attribute.\n     *\n     * Retrieves a single derived request attribute as described in\n     * getAttributes(). If the attribute has not been previously set, returns\n     * the default value as provided.\n     *\n     * This method obviates the need for a hasAttribute() method, as it allows\n     * specifying a default value to return if the attribute is not found.\n     *\n     * @param string        $name\n     * @param mixed|null    $defaultValue\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 163,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 162,
                    "last-line": 177,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAttributes",
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
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 180,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 180,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 180,
                                    "char": 33
                                },
                                "name": "toArray",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 180,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 181,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieve attributes derived from the request.\n     *\n     * The request 'attributes' may be used to allow injection of any\n     * parameters derived from the request: e.g., the results of path\n     * match operations; the results of decrypting cookies; the results of\n     * deserializing non-form-encoded message bodies; etc. Attributes\n     * will be application and request specific, and CAN be mutable.\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 179,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 179,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 178,
                    "last-line": 197,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 198,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 198,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 200,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 202,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "attributes",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 202,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 202,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 202,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 202,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 202,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 204,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "attributes",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 204,
                                    "char": 20
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 204,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 204,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 204,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 204,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 204,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 206,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 206,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 206,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 206,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 206,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 206,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 206,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 207,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified derived request attribute.\n     *\n     * This method allows setting a single derived request attribute as\n     * described in getAttributes().\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * updated attribute.\n     *\n     * @param string $name\n     * @param mixed  $value\n     *\n     * @return ServerRequest\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequest",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 199,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 199,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 199,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 198,
                    "last-line": 226,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withCookieParams",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cookies",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 227,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 229,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cookies",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 229,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 229,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "cookieParams",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 229,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 229,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 229,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 230,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified cookies.\n     *\n     * The data IS NOT REQUIRED to come from the $_COOKIE superglobal, but MUST\n     * be compatible with the structure of $_COOKIE. Typically, this data will\n     * be injected at instantiation.\n     *\n     * This method MUST NOT update the related Cookie header of the request\n     * instance, nor related values in the server params.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * updated cookie values.\n     *\n     * @param array $cookies\n     *\n     * @return ServerRequest\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequest",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 228,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 228,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 228,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 227,
                    "last-line": 260,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withParsedBody",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 261,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 263,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 263,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 263,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "parsedBody",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 263,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 263,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 263,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 264,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified body parameters.\n     *\n     * These MAY be injected during instantiation.\n     *\n     * If the request Content-Type is either application\/x-www-form-urlencoded\n     * or multipart\/form-data, and the request method is POST, use this method\n     * ONLY to inject the contents of $_POST.\n     *\n     * The data IS NOT REQUIRED to come from $_POST, but MUST be the results of\n     * deserializing the request body content. Deserialization\/parsing returns\n     * structured data, and, as such, this method ONLY accepts arrays or\n     * objects, or a null value if nothing was available to parse.\n     *\n     * As an example, if content negotiation determines that the request data\n     * is a JSON payload, this method could be used to create a request\n     * instance with the deserialized parameters.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * updated body parameters.\n     *\n     * @param array|object|null $data\n     *\n     * @return ServerRequest\n     * @throws InvalidArgumentException if an unsupported argument type is\n     *     provided.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequest",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 262,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 262,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 262,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 261,
                    "last-line": 287,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withQueryParams",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "query",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 288,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 290,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "query",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 290,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 290,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "queryParams",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 290,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 290,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 290,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 291,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified query string arguments.\n     *\n     * These values SHOULD remain immutable over the course of the incoming\n     * request. They MAY be injected during instantiation, such as from PHP's\n     * $_GET superglobal, or MAY be derived from some other value such as the\n     * URI. In cases where the arguments are parsed from the URI, the data\n     * MUST be compatible with what PHP's parse_str() would return for\n     * purposes of how duplicate query parameters are handled, and how nested\n     * sets are handled.\n     *\n     * Setting query string arguments MUST NOT change the URI stored by the\n     * request, nor the values in the server params.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * updated query string arguments.\n     *\n     * @param array $query\n     *\n     * @return ServerRequest\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequest",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 289,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 289,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 289,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 288,
                    "last-line": 305,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withUploadedFiles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uploadedFiles",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 306,
                            "char": 58
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
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 308,
                                    "char": 14
                                },
                                "name": "checkUploadedFiles",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uploadedFiles",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 308,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 308,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 308,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 310,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 310,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uploadedFiles",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 310,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 310,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "uploadedFiles",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 310,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 310,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 310,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 311,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new instance with the specified uploaded files.\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that has the\n     * updated body parameters.\n     *\n     * @param array $uploadedFiles\n     *\n     * @return ServerRequest\n     * @throws InvalidArgumentException if an invalid structure is provided.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequest",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 307,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 307,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 307,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 306,
                    "last-line": 326,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withoutAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 327,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 329,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 331,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "attributes",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 331,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 331,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 331,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 331,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 331,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 332,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "attributes",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 332,
                                    "char": 20
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 332,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 332,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 332,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 334,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 334,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 334,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 334,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 334,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 334,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 334,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 335,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance that removes the specified derived request attribute.\n     *\n     * This method allows removing a single derived request attribute as\n     * described in getAttributes().\n     *\n     * This method MUST be implemented in such a way as to retain the\n     * immutability of the message, and MUST return an instance that removes\n     * the attribute.\n     *\n     * @param string $name\n     *\n     * @return ServerRequest\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServerRequest",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 328,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 328,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 328,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 327,
                    "last-line": 341,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkUploadedFiles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "files",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 342,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 344,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 346,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "files",
                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                "line": 346,
                                "char": 27
                            },
                            "value": "file",
                            "reverse": 0,
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 347,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 347,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 347,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 347,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                        "line": 347,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 348,
                                                    "char": 22
                                                },
                                                "name": "checkUploadedFiles",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                            "line": 348,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                        "line": 348,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 348,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 349,
                                            "char": 13
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
                                                                        "value": "file",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                        "line": 350,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                    "line": 350,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "object",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                    "line": 350,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                "line": 350,
                                                                "char": 55
                                                            },
                                                            "right": {
                                                                "type": "instanceof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "file",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                    "line": 350,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "UploadedFileInterface",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                    "line": 350,
                                                                    "char": 94
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                "line": 350,
                                                                "char": 94
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                            "line": 350,
                                                            "char": 94
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                        "line": 350,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 350,
                                                    "char": 96
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                "line": 350,
                                                "char": 96
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
                                                                    "value": "Invalid uploaded file",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                    "line": 351,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                                "line": 351,
                                                                "char": 77
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                        "line": 351,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                                    "line": 352,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                            "line": 353,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                                    "line": 354,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                            "line": 355,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the uploaded files\n     *\n     * @param array $files\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                        "line": 343,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
                    "line": 342,
                    "last-line": 356,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
            "line": 29,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/ServerRequest.zep",
        "line": 29,
        "char": 11
    }
]