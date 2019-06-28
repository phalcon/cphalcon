[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                "line": 17,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Exception",
                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                "line": 18,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                "line": 19,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "RuntimeException",
                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                "line": 20,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-7 Stream\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "Stream",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                "line": 26,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handle",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 30,
                        "char": 28
                    },
                    "docblock": "**\n     * @var resource | null\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "stream",
                    "docblock": "**\n     * @var resource | string\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "warning",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 40,
                        "char": 30
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 47,
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
                            "name": "stream",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 48,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "mode",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "rb",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 48,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 48,
                            "char": 62
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 50,
                                    "char": 14
                                },
                                "name": "setStream",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "stream",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 50,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 50,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "mode",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 50,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 50,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 50,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 51,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stream constructor.\n     *\n     * @param mixed  $stream\n     * @param string $mode\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 48,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__destruct",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 58,
                                    "char": 14
                                },
                                "name": "close",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 58,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Closes the stream when the destructed.\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 56,
                    "last-line": 73,
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
                            "type": "try-catch",
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "likely",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 77,
                                                "char": 28
                                            },
                                            "name": "isReadable",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 77,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 77,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "likely",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 78,
                                                        "char": 32
                                                    },
                                                    "name": "isSeekable",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 78,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 78,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 79,
                                                            "char": 26
                                                        },
                                                        "name": "rewind",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 79,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 80,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 82,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 82,
                                                    "char": 29
                                                },
                                                "name": "getContents",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 82,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 83,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 84,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 86,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 86,
                                "char": 16
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 87,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads all data from the stream into a string, from the beginning to end.\n     *\n     * This method MUST attempt to seek to the beginning of the stream before\n     * reading data and read the stream until the end is reached.\n     *\n     * Warning: This could attempt to load a large amount of data into memory.\n     *\n     * This method MUST NOT raise an exception in order to conform with PHP's\n     * string casting operations.\n     *\n     * @see http:\/\/php.net\/manual\/en\/language.oop5.magic.php#object.tostring\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 75,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 75,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 74,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "close",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "handle",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 94,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 96,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 96,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 96,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 96,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 96,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 96,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 96,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handle",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 97,
                                                    "char": 31
                                                },
                                                "name": "detach",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 97,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 97,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 99,
                                    "char": 18
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "fclose",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "handle",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 99,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 99,
                                                "char": 26
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 99,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 100,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 101,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Closes the stream and any underlying resources.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 92,
                    "last-line": 109,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "detach",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "handle",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 112,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 114,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handle",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 114,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 114,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 114,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 114,
                                    "char": 40
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "handle",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 115,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 115,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 117,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "handle",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 117,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Separates any underlying resources from the stream.\n     *\n     * After the stream has been detached, the stream is in an unusable state.\n     *\n     * @return resource | null\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "resource",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 110,
                                "char": 42
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 111,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 111,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 110,
                    "last-line": 122,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "eof",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 125,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "handle",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 125,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 125,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 125,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "feof",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 126,
                                                        "char": 30
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 126,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 126,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 126,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 126,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 127,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 129,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 129,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 130,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns true if the stream is at the end of the stream.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 124,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 124,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 123,
                    "last-line": 134,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContents",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 137,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 139,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 139,
                                    "char": 14
                                },
                                "name": "checkHandle",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 139,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 140,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 140,
                                    "char": 14
                                },
                                "name": "checkReadable",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 140,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 142,
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
                                        "name": "stream_get_contents",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 142,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 142,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 142,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 142,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 142,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 142,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 144,
                            "char": 10
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 144,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 144,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 144,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 144,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Could not read from the file\/stream",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 145,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 145,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 145,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 146,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 148,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 148,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 149,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the remaining contents in a string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 136,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 136,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 135,
                    "last-line": 160,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMetadata",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 161,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 161,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "metadata",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 163,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 165,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 165,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 165,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 165,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 165,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 165,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 165,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 166,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 167,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 169,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "metadata",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "stream_get_meta_data",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 169,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 169,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 169,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 169,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 169,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 169,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 171,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 171,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 171,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 171,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 171,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "metadata",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 172,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 173,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 175,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Arr",
                                "dynamic": 0,
                                "name": "get",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "metadata",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 175,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 175,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 175,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 175,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "empty-array",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 175,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 175,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 175,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 176,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get stream metadata as an associative array or retrieve a specific key.\n     *\n     * The keys returned are identical to the keys returned from PHP's\n     * stream_get_meta_data() function.\n     *\n     * @param mixed|null $key\n     *\n     * @return array|mixed|null\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 161,
                    "last-line": 180,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSize",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "stats",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 183,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 185,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 185,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 185,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 185,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 185,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 185,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 185,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "stats",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "fstat",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                                "line": 186,
                                                                "char": 36
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "handle",
                                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                                "line": 186,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 186,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 186,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 186,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 186,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 188,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "likely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 188,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "stats",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 188,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 188,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 188,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Arr",
                                                "dynamic": 0,
                                                "name": "get",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "stats",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 189,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 189,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "size",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 189,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 189,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 189,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 189,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 189,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 190,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 191,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 193,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 193,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 194,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the size of the stream if known.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 181,
                                "char": 39
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 182,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 182,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 181,
                    "last-line": 198,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isReadable",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "mode",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 201,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 203,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mode",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 203,
                                                "char": 34
                                            },
                                            "name": "getMetadata",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "mode",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 203,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 203,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 203,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 203,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 203,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 205,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 205,
                                    "char": 24
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "strpbrk",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 205,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 205,
                                            "char": 38
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "r+",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 205,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 205,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 205,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 205,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 206,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns whether or not the stream is readable.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 200,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 200,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 199,
                    "last-line": 210,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isSeekable",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "bool",
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 213,
                                        "char": 28
                                    },
                                    "name": "getMetadata",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "seekable",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 213,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 213,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 213,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 213,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 214,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns whether or not the stream is seekable.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 212,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 212,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 211,
                    "last-line": 218,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isWritable",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "mode",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 221,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 223,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mode",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 223,
                                                "char": 34
                                            },
                                            "name": "getMetadata",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "mode",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 223,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 223,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 223,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 223,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 223,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 225,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 225,
                                    "char": 24
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "strpbrk",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 225,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 225,
                                            "char": 38
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "xwca+",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 225,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 225,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 225,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 225,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 226,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns whether or not the stream is writable.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 220,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 220,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 219,
                    "last-line": 234,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "read",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "length",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 235,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 237,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 239,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 239,
                                    "char": 14
                                },
                                "name": "checkHandle",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 239,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 240,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 240,
                                    "char": 14
                                },
                                "name": "checkReadable",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 240,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 242,
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
                                        "name": "fread",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 242,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 242,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 242,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 242,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 242,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 242,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 242,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 242,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 244,
                            "char": 10
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 244,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 244,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 244,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 244,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Could not read from the file\/stream",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 245,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 245,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 245,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 246,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 248,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 248,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 249,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Read data from the stream.\n     *\n     * @param int $length\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 236,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 236,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 235,
                    "last-line": 256,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rewind",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 259,
                                    "char": 14
                                },
                                "name": "seek",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 259,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 259,
                                        "char": 21
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 259,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 260,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Seek to the beginning of the stream.\n     *\n     * If the stream is not seekable, this method will raise an exception;\n     * otherwise, it will perform a seek(0).\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 258,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 257,
                    "last-line": 267,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "seek",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 268,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "whence",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 268,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 268,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "seeker",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 270,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 272,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 272,
                                    "char": 14
                                },
                                "name": "checkHandle",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 272,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 273,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 273,
                                    "char": 14
                                },
                                "name": "checkSeekable",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 273,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 275,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "seeker",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "fseek",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 275,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 275,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 275,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 275,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "offset",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 275,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 275,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "whence",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 275,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 275,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 275,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 275,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 277,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 277,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "seeker",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 277,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 277,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 277,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Could not seek on the file pointer",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 278,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 278,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 278,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 279,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 280,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Seek to a position in the stream.\n     *\n     * @param int $offset\n     * @param int $whence\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 269,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 268,
                    "last-line": 287,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStream",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "stream",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 288,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "mode",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "rb",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 288,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 288,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "handle",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 290,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 292,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handle",
                                    "expr": {
                                        "type": "variable",
                                        "value": "stream",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 292,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 292,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 293,
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
                                            "value": "stream",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 293,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 293,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 293,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 293,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 293,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "set_error_handler",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "closure",
                                                    "left": [
                                                        {
                                                            "type": "parameter",
                                                            "name": "error",
                                                            "const": 0,
                                                            "data-type": "variable",
                                                            "mandatory": 0,
                                                            "reference": 0,
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 295,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "right": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "warning",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                                        "line": 296,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                                    "line": 296,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 297,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 298,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 298,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 298,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 300,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handle",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "fopen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "stream",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 300,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 300,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "mode",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 300,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 300,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 300,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 300,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 302,
                                    "char": 33
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "restore_error_handler",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 302,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 303,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 305,
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 305,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "warning",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 305,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 305,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 305,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 305,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "resource",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 305,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 305,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 305,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "string",
                                                "value": "stream",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 305,
                                                "char": 78
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "get_resource_type",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "handle",
                                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                            "line": 305,
                                                            "char": 104
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 305,
                                                        "char": 104
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 305,
                                                "char": 105
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 305,
                                            "char": 105
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 305,
                                        "char": 105
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 305,
                                    "char": 107
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 305,
                                "char": 107
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The stream provided is not valid (string\/resource) or could not be opened.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 308,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 308,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 308,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 309,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 311,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "handle",
                                    "expr": {
                                        "type": "variable",
                                        "value": "handle",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 311,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 311,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "stream",
                                    "expr": {
                                        "type": "variable",
                                        "value": "stream",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 312,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 312,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 313,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the stream - existing instance\n     *\n     * @param mixed  $stream\n     * @param string $mode\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 289,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 295,
                    "last-line": 319,
                    "char": 24
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "tell",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 322,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 324,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 324,
                                    "char": 14
                                },
                                "name": "checkHandle",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 324,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 326,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "position",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "ftell",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 326,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 326,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 326,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 326,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 326,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 326,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 328,
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
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 328,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 328,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "int",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 328,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 328,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 328,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Could not retrieve the pointer position",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 329,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 329,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 329,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 330,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 332,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "position",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 332,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 333,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current position of the file read\/write pointer\n     *\n     * @return int\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 321,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 321,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 320,
                    "last-line": 341,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "write",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 342,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "bytes",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 344,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 346,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 346,
                                    "char": 14
                                },
                                "name": "checkHandle",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 346,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 347,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 347,
                                    "char": 14
                                },
                                "name": "checkWritable",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 347,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 349,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "bytes",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "fwrite",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 349,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                        "line": 349,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 349,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 349,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 349,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 349,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 349,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 349,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 351,
                            "char": 10
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 351,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "bytes",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 351,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 351,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 351,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Could not write to the file\/stream",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 352,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 352,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 352,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 353,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 355,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "bytes",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 355,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 356,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Write data to the stream.\n     *\n     * @param string $data\n     *\n     * @return int\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 343,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 343,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 342,
                    "last-line": 360,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkHandle",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 363,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 363,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 363,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 363,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 363,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 363,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "A valid resource is required.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 364,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 364,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 364,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 365,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 366,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a handle is available and throws an exception otherwise\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 362,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 361,
                    "last-line": 370,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkReadable",
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 373,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 373,
                                            "char": 35
                                        },
                                        "name": "isReadable",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 373,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 373,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 373,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The resource is not readable.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 374,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 374,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 374,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 375,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 376,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a handle is readable and throws an exception otherwise\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 372,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 371,
                    "last-line": 380,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkSeekable",
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 383,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 383,
                                            "char": 35
                                        },
                                        "name": "isSeekable",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 383,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 383,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 383,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The resource is not seekable.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 384,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 384,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 384,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 385,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 386,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a handle is seekable and throws an exception otherwise\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 382,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 381,
                    "last-line": 390,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkWritable",
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 393,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                            "line": 393,
                                            "char": 35
                                        },
                                        "name": "isWritable",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 393,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 393,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                "line": 393,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The resource is not writable.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                    "line": 394,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                                "line": 394,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                        "line": 394,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                                    "line": 395,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                            "line": 396,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a handle is writeable and throws an exception otherwise\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                        "line": 392,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
                    "line": 391,
                    "last-line": 397,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Message\/Stream.zep",
        "line": 25,
        "char": 5
    }
]