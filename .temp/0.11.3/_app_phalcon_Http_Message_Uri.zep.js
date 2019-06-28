[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                "line": 17,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Str",
                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                "line": 18,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                "line": 19,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\AbstractCommon",
                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                "line": 20,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                "line": 21,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-7 Uri\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Uri",
        "abstract": 0,
        "final": 1,
        "extends": "AbstractCommon",
        "implements": [
            {
                "type": "variable",
                "value": "UriInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                "line": 27,
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
                    "name": "fragment",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 33,
                        "char": 25
                    },
                    "docblock": "**\n     * Returns the fragment of the URL\n     *\n     * @return string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 33,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "host",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 47,
                        "char": 21
                    },
                    "docblock": "**\n     * Retrieve the host component of the URI.\n     *\n     * If no host is present, this method MUST return an empty string.\n     *\n     * The value returned MUST be normalized to lowercase, per RFC 3986\n     * Section 3.2.2.\n     *\n     * @see http:\/\/tools.ietf.org\/html\/rfc3986#section-3.2.2\n     *\n     * @return string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 47,
                            "char": 27
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 51,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "pass",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 52,
                        "char": 20
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 58,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "path",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 59,
                        "char": 21
                    },
                    "docblock": "**\n     * Returns the path of the URL\n     *\n     * @return string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 59,
                            "char": 27
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 75,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "port",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 76,
                        "char": 25
                    },
                    "docblock": "**\n     * Retrieve the port component of the URI.\n     *\n     * If a port is present, and it is non-standard for the current scheme,\n     * this method MUST return it as an integer. If the port is the standard\n     * port used with the current scheme, this method SHOULD return null.\n     *\n     * If no port is present, and no scheme is present, this method MUST return\n     * a null value.\n     *\n     * If no port is present, but a scheme is present, this method MAY return\n     * the standard port for that scheme, but SHOULD return null.\n     *\n     * @return int|null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 76,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 82,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "query",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 83,
                        "char": 22
                    },
                    "docblock": "**\n     * Returns the query of the URL\n     *\n     * @return string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 83,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 99,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "scheme",
                    "default": {
                        "type": "string",
                        "value": "https",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 100,
                        "char": 28
                    },
                    "docblock": "**\n     * Retrieve the scheme component of the URI.\n     *\n     * If no scheme is present, this method MUST return an empty string.\n     *\n     * The value returned MUST be normalized to lowercase, per RFC 3986\n     * Section 3.1.\n     *\n     * The trailing \":\" character is not part of the scheme and MUST NOT be\n     * added.\n     *\n     * @see https:\/\/tools.ietf.org\/html\/rfc3986#section-3.1\n     *\n     * @return string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 100,
                            "char": 34
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 104,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "user",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 105,
                        "char": 20
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 111,
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
                            "name": "uri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 112,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 112,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "urlParts",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 114,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 116,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 116,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "uri",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 116,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 116,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 116,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "urlParts",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "parse_url",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "uri",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 117,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 117,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 117,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 117,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 119,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 119,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "urlParts",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 119,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 119,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 119,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "urlParts",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 120,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 120,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 121,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 123,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "fragment",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 123,
                                                    "char": 39
                                                },
                                                "name": "filterFragment",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 123,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 123,
                                                                    "char": 72
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "fragment",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 123,
                                                                        "char": 82
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 123,
                                                                    "char": 82
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 123,
                                                                        "char": 84
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 123,
                                                                    "char": 84
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 123,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 123,
                                                        "char": 85
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 123,
                                                "char": 86
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 123,
                                            "char": 86
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "host",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strtolower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 124,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 124,
                                                                    "char": 62
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "host",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 124,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 124,
                                                                    "char": 68
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 124,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 124,
                                                                    "char": 70
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 124,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 124,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 124,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 124,
                                            "char": 72
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "pass",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "rawurlencode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 125,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 125,
                                                                    "char": 64
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "pass",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 125,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 125,
                                                                    "char": 70
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 125,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 125,
                                                                    "char": 72
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 125,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 125,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 125,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 125,
                                            "char": 74
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "path",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 126,
                                                    "char": 39
                                                },
                                                "name": "filterPath",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 126,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 126,
                                                                    "char": 68
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "path",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 126,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 126,
                                                                    "char": 74
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 126,
                                                                        "char": 76
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 126,
                                                                    "char": 76
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 126,
                                                            "char": 77
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 126,
                                                        "char": 77
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 126,
                                                "char": 78
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 126,
                                            "char": 78
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "port",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 127,
                                                    "char": 39
                                                },
                                                "name": "filterPort",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 127,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 127,
                                                                    "char": 68
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "port",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 127,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 127,
                                                                    "char": 74
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "null",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 127,
                                                                        "char": 80
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 127,
                                                                    "char": 80
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 127,
                                                            "char": 81
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 127,
                                                        "char": 81
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 127,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 127,
                                            "char": 82
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "query",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 128,
                                                    "char": 39
                                                },
                                                "name": "filterQuery",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 128,
                                                                        "char": 69
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 128,
                                                                    "char": 69
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "query",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 128,
                                                                        "char": 76
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 128,
                                                                    "char": 76
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 128,
                                                                        "char": 78
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 128,
                                                                    "char": 78
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 128,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 128,
                                                        "char": 79
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 128,
                                                "char": 80
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 128,
                                            "char": 80
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "scheme",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 129,
                                                    "char": 39
                                                },
                                                "name": "filterScheme",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 129,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 129,
                                                                    "char": 70
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "scheme",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 129,
                                                                        "char": 78
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 129,
                                                                    "char": 78
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 129,
                                                                        "char": 80
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 129,
                                                                    "char": 80
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 129,
                                                            "char": 81
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 129,
                                                        "char": 81
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 129,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 129,
                                            "char": 82
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "user",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "rawurlencode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "get",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "urlParts",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 130,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 130,
                                                                    "char": 64
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "user",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 130,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 130,
                                                                    "char": 70
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 130,
                                                                        "char": 72
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 130,
                                                                    "char": 72
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 130,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 130,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 130,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 130,
                                            "char": 74
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 131,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 132,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Uri constructor.\n     *\n     * @param string $uri\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 112,
                    "last-line": 143,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__toString",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "authority",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 146,
                                    "char": 22
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 146,
                                    "char": 28
                                },
                                {
                                    "variable": "uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 146,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 148,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "authority",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 148,
                                            "char": 30
                                        },
                                        "name": "getAuthority",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 148,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 148,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "path",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 149,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 149,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 149,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 149,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 160,
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
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 160,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 160,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 160,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 160,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "starts_with",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "path",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 160,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 160,
                                                            "char": 60
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "\/",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 160,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 160,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 160,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 160,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 160,
                                            "char": 66
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 160,
                                                "char": 71
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "authority",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 160,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 160,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 160,
                                        "char": 82
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 160,
                                    "char": 84
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 160,
                                "char": 84
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "path",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "\/",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 161,
                                                    "char": 26
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 161,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 161,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 161,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 162,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 164,
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
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 164,
                                                            "char": 24
                                                        },
                                                        "name": "checkValue",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 164,
                                                                        "char": 41
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "scheme",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 164,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 164,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 164,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 164,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 164,
                                                                "char": 50
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": ":",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 164,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 164,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 165,
                                                        "char": 17
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 165,
                                                            "char": 24
                                                        },
                                                        "name": "checkValue",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "authority",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 165,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 165,
                                                                "char": 45
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/\/",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 165,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 165,
                                                                "char": 49
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 166,
                                                        "char": 17
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 166,
                                                    "char": 17
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 167,
                                                    "char": 17
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 167,
                                                "char": 17
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 167,
                                                    "char": 24
                                                },
                                                "name": "checkValue",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 167,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "query",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 167,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 167,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 167,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "?",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 167,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 167,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 168,
                                                "char": 17
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 168,
                                            "char": 17
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 168,
                                                "char": 24
                                            },
                                            "name": "checkValue",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 168,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "fragment",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 168,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 168,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 168,
                                                    "char": 50
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "#",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 168,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 168,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 168,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 168,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 168,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 170,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "uri",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 170,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 171,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the string representation as a URI reference.\n     *\n     * Depending on which components of the URI are present, the resulting\n     * string is either a full URI or relative reference according to RFC 3986,\n     * Section 4.1. The method concatenates the various components of the URI,\n     * using the appropriate delimiters\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 145,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 145,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 144,
                    "last-line": 177,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAuthority",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "authority",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 180,
                                    "char": 22
                                },
                                {
                                    "variable": "userInfo",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 180,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 186,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 186,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 186,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "host",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 186,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 186,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 186,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 186,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 187,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 188,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 190,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "authority",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 190,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "host",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 190,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 190,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 190,
                                    "char": 35
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "userInfo",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 191,
                                            "char": 30
                                        },
                                        "name": "getUserInfo",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 191,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 191,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 198,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 198,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "userInfo",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 198,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 198,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 198,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "authority",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "userInfo",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 199,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "@",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 199,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 199,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "authority",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 199,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 199,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 199,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 200,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 206,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 206,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 206,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "port",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 206,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 206,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 206,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 206,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "authority",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": ":",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 207,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 207,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "port",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 207,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 207,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 207,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 207,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 208,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 210,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "authority",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 210,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 211,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieve the authority component of the URI.\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 179,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 179,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 178,
                    "last-line": 227,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUserInfo",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 230,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "empty",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 230,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "pass",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 230,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 230,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 230,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 230,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 230,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 230,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 231,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "user",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 231,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 231,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": ":",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 231,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 231,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 231,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "pass",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 231,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 231,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 231,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 232,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 234,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 234,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "user",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 234,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 234,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 235,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieve the user information component of the URI.\n     *\n     * If no user information is present, this method MUST return an empty\n     * string.\n     *\n     * If a user is present in the URI, this will return that value;\n     * additionally, if the password is also present, it will be appended to the\n     * user value, with a colon (\":\") separating the values.\n     *\n     * The trailing \"@\" character is not part of the user information and MUST\n     * NOT be added.\n     *\n     * @return string The URI user information, in \"username[:password]\" format.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 229,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 229,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 228,
                    "last-line": 251,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withFragment",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fragment",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 252,
                            "char": 46
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 254,
                                    "char": 14
                                },
                                "name": "checkStringParameter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fragment",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 254,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 254,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 254,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 256,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fragment",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 256,
                                            "char": 29
                                        },
                                        "name": "filterFragment",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fragment",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 256,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 256,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 256,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 256,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 258,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fragment",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 258,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 258,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "fragment",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 258,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 258,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 258,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 259,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified URI fragment.\n     *\n     * This method MUST retain the state of the current instance, and return\n     * an instance that contains the specified URI fragment.\n     *\n     * Users can provide both encoded and decoded fragment characters.\n     * Implementations ensure the correct encoding as outlined in getFragment().\n     *\n     * An empty fragment value is equivalent to removing the fragment.\n     *\n     * @param string $fragment\n     *\n     * @return Uri\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 253,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 253,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 253,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 252,
                    "last-line": 283,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withPath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 284,
                            "char": 38
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 286,
                                    "char": 14
                                },
                                "name": "checkStringParameter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 286,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 286,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 286,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 288,
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
                                            "type": "not-identical",
                                            "left": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 288,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "strpos",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "path",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 288,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 288,
                                                        "char": 43
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "?",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 288,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 288,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 288,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 288,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 288,
                                                "char": 59
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "strpos",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "path",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 288,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 288,
                                                        "char": 72
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "#",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 288,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 288,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 288,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 288,
                                            "char": 76
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 288,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 288,
                                    "char": 78
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 288,
                                "char": 78
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
                                                    "value": "Path cannot contain a query string or fragment",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 291,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 291,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 291,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 292,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 294,
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
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 294,
                                            "char": 25
                                        },
                                        "name": "filterPath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 294,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 294,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 294,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 294,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 296,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 296,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 296,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 296,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 296,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 296,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 296,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 297,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified path.\n     *\n     * This method MUST retain the state of the current instance, and return\n     * an instance that contains the specified path.\n     *\n     * The path can either be empty or absolute (starting with a slash) or\n     * rootless (not starting with a slash). Implementations MUST support all\n     * three syntaxes.\n     *\n     * If an HTTP path is intended to be host-relative rather than path-relative\n     * then it must begin with a slash (\"\/\"). HTTP paths not starting with a\n     * slash are assumed to be relative to some base path known to the\n     * application or consumer.\n     *\n     * Users can provide both encoded and decoded path characters.\n     * Implementations ensure the correct encoding as outlined in getPath().\n     *\n     * @param string $path\n     *\n     * @return Uri\n     * @throws InvalidArgumentException for invalid paths.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 285,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 285,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 285,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 284,
                    "last-line": 315,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withPort",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "port",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 316,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 318,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "port",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 318,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 318,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 318,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "port",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 319,
                                                    "char": 29
                                                },
                                                "name": "filterPort",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "port",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 319,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 319,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 319,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 319,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 321,
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
                                                    "type": "not-identical",
                                                    "left": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 321,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "port",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 321,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 321,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "less",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "port",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 321,
                                                                "char": 49
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 321,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 321,
                                                            "char": 54
                                                        },
                                                        "right": {
                                                            "type": "greater",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "port",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 321,
                                                                "char": 61
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "65535",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 321,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 321,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 321,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 321,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 321,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 321,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 321,
                                        "char": 71
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
                                                            "value": "Method expects valid port (1-65535)",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 324,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 324,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 324,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 325,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 326,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 328,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 328,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "port",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 328,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 328,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "port",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 328,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 328,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 328,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 329,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified port.\n     *\n     * This method MUST retain the state of the current instance, and return\n     * an instance that contains the specified port.\n     *\n     * Implementations MUST raise an exception for ports outside the\n     * established TCP and UDP port ranges.\n     *\n     * A null value provided for the port is equivalent to removing the port\n     * information.\n     *\n     * @param int|null $port\n     *\n     * @return Uri\n     * @throws InvalidArgumentException for invalid ports.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 317,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 317,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 317,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 316,
                    "last-line": 346,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withQuery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "query",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 347,
                            "char": 40
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 349,
                                    "char": 14
                                },
                                "name": "checkStringParameter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "query",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 349,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 349,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 349,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 351,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 351,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "strpos",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "query",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 351,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 351,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "#",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 351,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 351,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 351,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 351,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 351,
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
                                                    "type": "string",
                                                    "value": "Query cannot contain a query fragment",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 354,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 354,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 354,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 355,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 357,
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
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 357,
                                            "char": 26
                                        },
                                        "name": "filterQuery",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "query",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 357,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 357,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 357,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 357,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 359,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 359,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "query",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 359,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 359,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "query",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 359,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 359,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 359,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 360,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified query string.\n     *\n     * This method MUST retain the state of the current instance, and return\n     * an instance that contains the specified query string.\n     *\n     * Users can provide both encoded and decoded query characters.\n     * Implementations ensure the correct encoding as outlined in getQuery().\n     *\n     * An empty query string value is equivalent to removing the query string.\n     *\n     * @param string $query\n     *\n     * @return Uri\n     * @throws InvalidArgumentException for invalid query strings.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 348,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 348,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 348,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 347,
                    "last-line": 378,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withScheme",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "scheme",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 379,
                            "char": 38
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 381,
                                    "char": 14
                                },
                                "name": "checkStringParameter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "scheme",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 381,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 381,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 381,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 383,
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
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 383,
                                            "char": 27
                                        },
                                        "name": "filterScheme",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "scheme",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 383,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 383,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 383,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 383,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 385,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 385,
                                    "char": 21
                                },
                                "name": "processWith",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "scheme",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 385,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 385,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "scheme",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 385,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 385,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 385,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 386,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified scheme.\n     *\n     * This method MUST retain the state of the current instance, and return\n     * an instance that contains the specified scheme.\n     *\n     * Implementations MUST support the schemes \"http\" and \"https\" case\n     * insensitively, and MAY accommodate other schemes if required.\n     *\n     * An empty scheme is equivalent to removing the scheme.\n     *\n     * @param string $scheme\n     *\n     * @return Uri\n     * @throws InvalidArgumentException for invalid schemes.\n     * @throws InvalidArgumentException for unsupported schemes.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 380,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 380,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 380,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 379,
                    "last-line": 395,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withUserInfo",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "user",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 396,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "password",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 396,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 396,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "newInstance",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 398,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 400,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 400,
                                    "char": 14
                                },
                                "name": "checkStringParameter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "user",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 400,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 400,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 400,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 402,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 402,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "password",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 402,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 402,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 402,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 403,
                                            "char": 18
                                        },
                                        "name": "checkStringParameter",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "user",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 403,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 403,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 403,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 404,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 406,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "user",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "rawurlencode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "user",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 406,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 406,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 406,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 406,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 408,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 408,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "password",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 408,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 408,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 408,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "password",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "rawurlencode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "password",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 409,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 409,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 409,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 409,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 410,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 415,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newInstance",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 415,
                                            "char": 38
                                        },
                                        "name": "cloneInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "user",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 415,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 415,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "user",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 415,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 415,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 415,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 415,
                                    "char": 64
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "newInstance",
                                    "property": "pass",
                                    "expr": {
                                        "type": "variable",
                                        "value": "password",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 416,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 416,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 418,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "newInstance",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 418,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 419,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified user information.\n     *\n     * @param string      $user\n     * @param string|null $password\n     *\n     * @return Uri\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 397,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 397,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 397,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 396,
                    "last-line": 434,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "withHost",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "host",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 435,
                            "char": 34
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 437,
                                    "char": 21
                                },
                                "name": "processWith",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "host",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 437,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 437,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "host",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 437,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 437,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 437,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 438,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an instance with the specified host.\n     *\n     * This method MUST retain the state of the current instance, and return\n     * an instance that contains the specified host.\n     *\n     * An empty host value is equivalent to removing the host.\n     *\n     * @param string $host\n     *\n     * @return Uri\n     * @throws InvalidArgumentException for invalid hostnames.\n     *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Uri",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 436,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 436,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 436,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 435,
                    "last-line": 449,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 451,
                            "char": 22
                        },
                        {
                            "type": "parameter",
                            "name": "prefix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 452,
                                "char": 26
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 452,
                            "char": 26
                        },
                        {
                            "type": "parameter",
                            "name": "suffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 454,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 454,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 456,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 456,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 456,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 456,
                                "char": 32
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
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "prefix",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 457,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 457,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 457,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "suffix",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 457,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 457,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 457,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 458,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 460,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 460,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 461,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * If the value passed is empty it returns it prefixed and suffixed with\n     * the passed parameters\n     *\n     * @param string $value\n     * @param string $prefix\n     * @param string $suffix\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 455,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 455,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 450,
                    "last-line": 479,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "filterFragment",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fragment",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 480,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "rawurlencode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fragment",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 482,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 482,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 482,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 483,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * If no fragment is present, this method MUST return an empty string.\n     *\n     * The leading \"#\" character is not part of the fragment and MUST NOT be\n     * added.\n     *\n     * The value returned MUST be percent-encoded, but MUST NOT double-encode\n     * any characters. To determine what characters to encode, please refer to\n     * RFC 3986, Sections 2 and 3.5.\n     *\n     * @see https:\/\/tools.ietf.org\/html\/rfc3986#section-2\n     * @see https:\/\/tools.ietf.org\/html\/rfc3986#section-3.5\n     *\n     * @param string $fragment\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 481,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 481,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 480,
                    "last-line": 511,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "filterPath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 512,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 514,
                                    "char": 20
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 514,
                                    "char": 25
                                },
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 514,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 516,
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
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 516,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 516,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 516,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 516,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "starts_with",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "path",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 516,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 516,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\/",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 516,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 516,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 516,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 516,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 516,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 516,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 516,
                                "char": 66
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "path",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 517,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 518,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 520,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "parts",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 520,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 520,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 520,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 520,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 520,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 520,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 521,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "parts",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 521,
                                "char": 35
                            },
                            "key": "key",
                            "value": "element",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "parts",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 522,
                                                    "char": 26
                                                }
                                            ],
                                            "expr": {
                                                "type": "fcall",
                                                "name": "rawurlencode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "element",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 522,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 522,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 522,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 522,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 523,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 525,
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
                                        "type": "fcall",
                                        "name": "implode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 525,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 525,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "parts",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 525,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 525,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 525,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 525,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 527,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "\/",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 527,
                                    "char": 18
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "ltrim",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 527,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 527,
                                            "char": 30
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "\/",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 527,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 527,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 527,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 527,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 528,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     *\n     * The path can either be empty or absolute (starting with a slash) or\n     * rootless (not starting with a slash). Implementations MUST support all\n     * three syntaxes.\n     *\n     * Normally, the empty path \"\" and absolute path \"\/\" are considered equal as\n     * defined in RFC 7230 Section 2.7.3. But this method MUST NOT automatically\n     * do this normalization because in contexts with a trimmed base path, e.g.\n     * the front controller, this difference becomes significant. It's the task\n     * of the user to handle both \"\" and \"\/\".\n     *\n     * The value returned MUST be percent-encoded, but MUST NOT double-encode\n     * any characters. To determine what characters to encode, please refer to\n     * RFC 3986, Sections 2 and 3.3.\n     *\n     * As an example, if the value should include a slash (\"\/\") not intended as\n     * delimiter between path segments, that value MUST be passed in encoded\n     * form (e.g., \"%2F\") to the instance.\n     *\n     * @see https:\/\/tools.ietf.org\/html\/rfc3986#section-2\n     * @see https:\/\/tools.ietf.org\/html\/rfc3986#section-3.3\n     *\n     * @param string $path\n     *\n     * @return string The URI path.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 513,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 513,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 512,
                    "last-line": 536,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "filterPort",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "port",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 537,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "ports",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 539,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 541,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ports",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "80",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 542,
                                                    "char": 17
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 542,
                                                    "char": 20
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 542,
                                                "char": 20
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "443",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 543,
                                                    "char": 17
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 544,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 544,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 544,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 544,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 546,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 546,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "port",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 546,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 546,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 546,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "port",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "port",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 547,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 547,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 547,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 548,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "ports",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 548,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "port",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 548,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 548,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 548,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 548,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "port",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 549,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 549,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 550,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 551,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 553,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "port",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 553,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 554,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the port. If it is a standard one (80,443) then it returns null\n     *\n     * @param $port\n     *\n     * @return int|null\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 538,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 538,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 537,
                    "last-line": 576,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "filterQuery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "query",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 577,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "index",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 579,
                                    "char": 18
                                },
                                {
                                    "variable": "part",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 579,
                                    "char": 24
                                },
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 579,
                                    "char": 31
                                },
                                {
                                    "variable": "split",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 579,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 581,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 581,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "query",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 581,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 581,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 581,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 582,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 583,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 585,
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
                                        "type": "fcall",
                                        "name": "ltrim",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "query",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 585,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 585,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "?",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 585,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 585,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 585,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 585,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "parts",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "&",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 586,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 586,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "query",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 586,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 586,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 586,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 586,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 588,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "parts",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 588,
                                "char": 34
                            },
                            "key": "index",
                            "value": "part",
                            "reverse": 0,
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 589,
                                                    "char": 30
                                                },
                                                "name": "splitQueryValue",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "part",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 589,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 589,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 589,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 589,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 590,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 590,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "split",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 590,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 590,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 590,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 590,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 590,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "parts",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "index",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 591,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "rawurlencode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "split",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 591,
                                                                        "char": 54
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 591,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 591,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 591,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 591,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 591,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 592,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 593,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 595,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "parts",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 595,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "rawurlencode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "split",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 595,
                                                                        "char": 50
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 595,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 595,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 595,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 595,
                                                        "char": 55
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "=",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 595,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 595,
                                                    "char": 59
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "rawurlencode",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "split",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 595,
                                                                    "char": 79
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 595,
                                                                    "char": 81
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 595,
                                                                "char": 82
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 595,
                                                            "char": 82
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 595,
                                                    "char": 83
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 595,
                                                "char": 83
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 595,
                                            "char": 83
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 596,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 598,
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
                                            "type": "string",
                                            "value": "&",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 598,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 598,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parts",
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 598,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 598,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 598,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 599,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * If no query string is present, this method MUST return an empty string.\n     *\n     * The leading \"?\" character is not part of the query and MUST NOT be\n     * added.\n     *\n     * The value returned MUST be percent-encoded, but MUST NOT double-encode\n     * any characters. To determine what characters to encode, please refer to\n     * RFC 3986, Sections 2 and 3.4.\n     *\n     * As an example, if a value in a key\/value pair of the query string should\n     * include an ampersand (\"&\") not intended as a delimiter between values,\n     * that value MUST be passed in encoded form (e.g., \"%26\") to the instance.\n     *\n     * @see https:\/\/tools.ietf.org\/html\/rfc3986#section-2\n     * @see https:\/\/tools.ietf.org\/html\/rfc3986#section-3.4\n     *\n     * @param string $query\n     *\n     * @return string The URI query string.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 578,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 578,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 577,
                    "last-line": 607,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "filterScheme",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "scheme",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 608,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "filtered",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 610,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 611,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "schemes",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 611,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 613,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filtered",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_replace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "#:(\/\/)?$#",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 613,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 613,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 613,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 613,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "mb_strtolower",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "scheme",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 613,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 613,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 613,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 613,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 613,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 613,
                                    "char": 72
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "schemes",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "http",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 615,
                                                    "char": 23
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 615,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 615,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "https",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 616,
                                                    "char": 23
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 617,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 617,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 617,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 617,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 619,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 619,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "filtered",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 619,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 619,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 619,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 620,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 621,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 623,
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
                                                "value": "schemes",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 623,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "filtered",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 623,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 623,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 623,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 623,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 623,
                                "char": 46
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
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "Unsupported scheme [",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 625,
                                                                        "char": 38
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "filtered",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 625,
                                                                        "char": 49
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 625,
                                                                    "char": 49
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "]. ",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 625,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 625,
                                                                "char": 55
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "Scheme must be one of [",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                "line": 626,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 626,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "implode",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": ", ",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 627,
                                                                        "char": 27
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 627,
                                                                    "char": 27
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "fcall",
                                                                        "name": "array_keys",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "schemes",
                                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                                    "line": 627,
                                                                                    "char": 47
                                                                                },
                                                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                                "line": 627,
                                                                                "char": 47
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                        "line": 627,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                                    "line": 627,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                            "line": 627,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 627,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "]",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                        "line": 628,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 628,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 628,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 628,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 629,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 631,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "scheme",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 631,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 632,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Filters the passed scheme - only allowed schemes\n     *\n     * @param string $scheme\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 609,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 609,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 608,
                    "last-line": 638,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "splitQueryValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 639,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 641,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 643,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "=",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 643,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 643,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "element",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 643,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 643,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                    "line": 643,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 643,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 643,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 643,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 644,
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
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 644,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 644,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 644,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                        "line": 644,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 644,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 644,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                                "line": 645,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                            "line": 645,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                    "line": 646,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 648,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 648,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                            "line": 649,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param string $element\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                                "line": 640,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                        "line": 640,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
                    "line": 639,
                    "last-line": 650,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
            "line": 26,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/Uri.zep",
        "line": 26,
        "char": 11
    }
]