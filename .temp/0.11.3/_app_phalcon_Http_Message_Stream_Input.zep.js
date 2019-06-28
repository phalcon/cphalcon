[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message\\Stream",
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Stream",
                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Describes a data stream from \"php:\/\/input\"\n *\n * Typically, an instance will wrap a PHP stream; this interface provides\n * a wrapper around the most common operations, including serialization of\n * the entire stream to a string.\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Input",
        "abstract": 0,
        "final": 0,
        "extends": "Stream",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "data",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                        "line": 31,
                        "char": 20
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "eof",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                        "line": 36,
                        "char": 24
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                    "line": 40,
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
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "php:\/\/input",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 43,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 43,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "rb",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 43,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 43,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 43,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 44,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Input constructor.\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                    "line": 41,
                    "last-line": 58,
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
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 61,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "eof",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 61,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 61,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 61,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 62,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 62,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 62,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 63,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 65,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 65,
                                    "char": 14
                                },
                                "name": "getContents",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 65,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 67,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 67,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 67,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 67,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 68,
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
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 60,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                        "line": 60,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                    "line": 59,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContents",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "length",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "-1",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 80,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 80,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 82,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 84,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 84,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "eof",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 84,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 84,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 84,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 85,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 85,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 85,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 86,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 88,
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
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                        "line": 88,
                                                        "char": 51
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "handle",
                                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                        "line": 88,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                    "line": 88,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 88,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                    "line": 88,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 88,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 88,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 88,
                                    "char": 67
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 89,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 89,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 91,
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
                                                "type": "int",
                                                "value": "-1",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 91,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "length",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 91,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 91,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 91,
                                                "char": 44
                                            },
                                            "name": "eof",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 91,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 91,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 91,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 91,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "eof",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 92,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 92,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 95,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 95,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 95,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 95,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 96,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the remaining contents in a string\n     *\n     * @throws RuntimeException if unable to read.\n     * @throws RuntimeException if error occurs while reading.\n     *\n     * @param int $length\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 81,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                    "line": 80,
                    "last-line": 100,
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
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 103,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 104,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns whether or not the stream is writeable.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 102,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                        "line": 102,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                    "line": 101,
                    "last-line": 112,
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
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 113,
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
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 115,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 117,
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
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "parent",
                                        "dynamic": 0,
                                        "name": "read",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                    "line": 117,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 117,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 117,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 117,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 119,
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
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 119,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 119,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eof",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 119,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 119,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 119,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 119,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "data",
                                            "expr": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 120,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 120,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 121,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 123,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                        "line": 123,
                                        "char": 26
                                    },
                                    "name": "eof",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 123,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 123,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "eof",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                                "line": 124,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                            "line": 124,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                    "line": 125,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 127,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 127,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                            "line": 128,
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
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                                "line": 114,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                        "line": 114,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
                    "line": 113,
                    "last-line": 129,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
            "line": 26,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Input.zep",
        "line": 26,
        "char": 5
    }
]