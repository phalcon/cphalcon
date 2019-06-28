[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Stream",
                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                "line": 18,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                "line": 19,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                "line": 20,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-17 StreamFactory\n *",
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "StreamFactory",
        "abstract": 0,
        "final": 1,
        "implements": [
            {
                "type": "variable",
                "value": "StreamFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                "line": 26,
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
                    "name": "createStream",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 36,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 36,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "handle",
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 38,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 40,
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
                                        "type": "fcall",
                                        "name": "fopen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "php:\/\/temp",
                                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                    "line": 40,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 40,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "r+b",
                                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                    "line": 40,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 40,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 40,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 40,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 41,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 41,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "handle",
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 41,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 41,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 41,
                                "char": 38
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
                                                    "value": "Cannot write to file.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                    "line": 42,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 42,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 42,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 43,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 45,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "fwrite",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 45,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 45,
                                        "char": 22
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 45,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 45,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 45,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 46,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "rewind",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 46,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 46,
                                        "char": 22
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 46,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 48,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 48,
                                    "char": 21
                                },
                                "name": "createStreamFromResource",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 48,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 48,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 48,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 49,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new stream from a string.\n     *\n     * The stream SHOULD be created with a temporary resource.\n     *\n     * @param string $content String content with which to populate the stream.\n     *\n     * @return StreamInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "StreamInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 37,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 37,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                        "line": 37,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                    "line": 36,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createStreamFromFile",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filename",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 66,
                            "char": 58
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
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 66,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 66,
                            "char": 78
                        }
                    ],
                    "statements": [
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
                                            "value": "filename",
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 68,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 68,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "mode",
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 68,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 68,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 68,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 69,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a stream from an existing file.\n     *\n     * The file MUST be opened using the given mode, which may be any mode\n     * supported by the `fopen` function.\n     *\n     * The `$filename` MAY be any string supported by `fopen()`.\n     *\n     * @param string $filename The filename or stream URI to use as basis of\n     *                         stream.\n     * @param string $mode     The mode with which to open the underlying\n     *                         filename\/stream.\n     *\n     * @return StreamInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "StreamInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 67,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                    "line": 66,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createStreamFromResource",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "phpResource",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 76,
                            "char": 61
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
                                                    "value": "phpResource",
                                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                    "line": 78,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 78,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "resource",
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 78,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 78,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "string",
                                                "value": "stream",
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 79,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "get_resource_type",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "phpResource",
                                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                            "line": 79,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                        "line": 79,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 79,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 79,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 79,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 79,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 79,
                                "char": 55
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
                                                    "value": "Invalid stream provided",
                                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                    "line": 80,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                                "line": 80,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 80,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 81,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 83,
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
                                            "value": "phpResource",
                                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                            "line": 83,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                        "line": 83,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 83,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new stream from an existing resource.\n     *\n     * The stream MUST be readable and may be writable.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "StreamInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                    "line": 77,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                                "line": 77,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                        "line": 77,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
                    "line": 76,
                    "last-line": 85,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
            "line": 25,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/StreamFactory.zep",
        "line": 25,
        "char": 11
    }
]