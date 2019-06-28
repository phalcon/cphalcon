[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Number",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 17,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 18,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Str",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 19,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 20,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Stream",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 21,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 22,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UploadedFileInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 23,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "RuntimeException",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                "line": 24,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 28,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-7 UploadedFile\n *",
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 29,
        "char": 5
    },
    {
        "type": "class",
        "name": "UploadedFile",
        "abstract": 0,
        "final": 1,
        "implements": [
            {
                "type": "variable",
                "value": "UploadedFileInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
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
                    "name": "alreadyMoved",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 36,
                        "char": 33
                    },
                    "docblock": "**\n     * If the file has already been moved, we hold that status here\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 49,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "clientFilename",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 50,
                        "char": 35
                    },
                    "docblock": "**\n     * Retrieve the filename sent by the client.\n     *\n     * Do not trust the value returned by this method. A client could send\n     * a malicious filename with the intention to corrupt or hack your\n     * application.\n     *\n     * Implementations SHOULD return the value stored in the 'name' key of\n     * the file in the $_FILES array.\n     *\n     * @var string | null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 50,
                            "char": 41
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 63,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "clientMediaType",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 64,
                        "char": 36
                    },
                    "docblock": "**\n     * Retrieve the media type sent by the client.\n     *\n     * Do not trust the value returned by this method. A client could send\n     * a malicious media type with the intention to corrupt or hack your\n     * application.\n     *\n     * Implementations SHOULD return the value stored in the 'type' key of\n     * the file in the $_FILES array.\n     *\n     * @var string | null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 64,
                            "char": 42
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 80,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "error",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 81,
                        "char": 23
                    },
                    "docblock": "**\n     * Retrieve the error associated with the uploaded file.\n     *\n     * The return value MUST be one of PHP's UPLOAD_ERR_XXX constants.\n     *\n     * If the file was uploaded successfully, this method MUST return\n     * UPLOAD_ERR_OK.\n     *\n     * Implementations SHOULD return the value stored in the 'error' key of\n     * the file in the $_FILES array.\n     *\n     * @see http:\/\/php.net\/manual\/en\/features.file-upload.errors.php\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 81,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 87,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "fileName",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 88,
                        "char": 24
                    },
                    "docblock": "**\n     * If the stream is a string (file name) we store it here\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 98,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "size",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 99,
                        "char": 25
                    },
                    "docblock": "**\n     * Retrieve the file size.\n     *\n     * Implementations SHOULD return the value stored in the 'size' key of\n     * the file in the $_FILES array if available, as PHP calculates this based\n     * on the actual size transmitted.\n     *\n     * @var int | null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 99,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 105,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "stream",
                    "docblock": "**\n     * Holds the stream\/string for the uploaded file\n     *\n     * @var StreamInterface|string|null\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 116,
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
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 118,
                            "char": 19
                        },
                        {
                            "type": "parameter",
                            "name": "size",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 119,
                                "char": 24
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 119,
                            "char": 24
                        },
                        {
                            "type": "parameter",
                            "name": "error",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 120,
                                "char": 22
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 120,
                            "char": 22
                        },
                        {
                            "type": "parameter",
                            "name": "clientFilename",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 121,
                                "char": 37
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 121,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "clientMediaType",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 123,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 123,
                            "char": 5
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
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 128,
                                    "char": 14
                                },
                                "name": "checkStream",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "stream",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 128,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 128,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 128,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 128,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 128,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 133,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 133,
                                    "char": 14
                                },
                                "name": "checkError",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 133,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 133,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 133,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 135,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "size",
                                    "expr": {
                                        "type": "variable",
                                        "value": "size",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 135,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 135,
                                    "char": 41
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "clientFilename",
                                    "expr": {
                                        "type": "variable",
                                        "value": "clientFilename",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 136,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 136,
                                    "char": 51
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "clientMediaType",
                                    "expr": {
                                        "type": "variable",
                                        "value": "clientMediaType",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 137,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 137,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 138,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * UploadedFile constructor.\n     *\n     * @param StreamInterface|string|null $stream\n     * @param int|null                    $size\n     * @param int                         $error\n     * @param string|null                 $clientFilename\n     * @param string|null                 $clientMediaType\n     *",
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 117,
                    "last-line": 155,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStream",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 158,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 158,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 158,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 158,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 158,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 158,
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
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 160,
                                                        "char": 22
                                                    },
                                                    "name": "getErrorDescription",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 160,
                                                                    "char": 48
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "error",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 160,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 160,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 160,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 161,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 161,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 161,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 162,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 164,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 164,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "alreadyMoved",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 164,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 164,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 164,
                                "char": 40
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
                                                    "value": "The file has already been moved to the target location",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 167,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 167,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 167,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 168,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 170,
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
                                            "type": "instanceof",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 170,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "stream",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 170,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 170,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "StreamInterface",
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 170,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 170,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 170,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 170,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 170,
                                "char": 64
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "stream",
                                            "expr": {
                                                "type": "new",
                                                "class": "Stream",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 171,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "fileName",
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 171,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 171,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 171,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 171,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 171,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 172,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 174,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 174,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "stream",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 174,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 174,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 175,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieve a stream representing the uploaded file.\n     *\n     * This method MUST return a StreamInterface instance, representing the\n     * uploaded file. The purpose of this method is to allow utilizing native\n     * PHP stream functionality to manipulate the file upload, such as\n     * stream_copy_to_stream() (though the result will need to be decorated in\n     * a native PHP stream wrapper to work with such functions).\n     *\n     * If the moveTo() method has been called previously, this method MUST\n     * raise an exception.\n     *\n     * @return StreamInterface Stream representation of the uploaded file.\n     * @throws RuntimeException in cases when no stream is available or can be\n     *     created.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 157,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 157,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 156,
                    "last-line": 210,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "moveTo",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "targetPath",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 211,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sapi",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 213,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 215,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 215,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "alreadyMoved",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 215,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 215,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 215,
                                "char": 40
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
                                                    "value": "File has already been moved",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 216,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 216,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 216,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 217,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 219,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 219,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 219,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 219,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 219,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 219,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 219,
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
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 221,
                                                        "char": 22
                                                    },
                                                    "name": "getErrorDescription",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 221,
                                                                    "char": 48
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "error",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 221,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 221,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 221,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 222,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 222,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 222,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 223,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 228,
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
                                                    "type": "and",
                                                    "left": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "targetPath",
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 228,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 228,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "string",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 228,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 228,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "empty",
                                                            "left": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "targetPath",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 229,
                                                                    "char": 30
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 229,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 229,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 229,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 229,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "is_dir",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "dirname",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "targetPath",
                                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                            "line": 230,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                        "line": 230,
                                                                        "char": 38
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 230,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 230,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 230,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 230,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "is_writable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "dirname",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "targetPath",
                                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                        "line": 231,
                                                                        "char": 43
                                                                    },
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 231,
                                                                    "char": 43
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 231,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 231,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 231,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 231,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 231,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 231,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 231,
                                "char": 47
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
                                                    "value": "Target folder is empty string, not a folder or not writable",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 234,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 234,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 234,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 235,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 237,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sapi",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "constant",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "PHP_SAPI",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 237,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 237,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 237,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 237,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 239,
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
                                                "type": "or",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "sapi",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 239,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 239,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 239,
                                                    "char": 35
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
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 240,
                                                                    "char": 24
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "fileName",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 240,
                                                                    "char": 33
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 240,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 240,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 240,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 240,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 240,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "starts_with",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sapi",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 241,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 241,
                                                        "char": 28
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "cli",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 241,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 241,
                                                        "char": 33
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 241,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 241,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "starts_with",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "sapi",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 242,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 242,
                                                    "char": 28
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "phpdbg",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 242,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 242,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 242,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 242,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 242,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 242,
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
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 243,
                                            "char": 18
                                        },
                                        "name": "storeFile",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "targetPath",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 243,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 243,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 243,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 244,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 245,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "move_uploaded_file",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 245,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "fileName",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 245,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 245,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 245,
                                                    "char": 58
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "targetPath",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 245,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 245,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 245,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 245,
                                        "char": 72
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
                                                            "value": "The file cannot be moved to the target folder",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 248,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 248,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 248,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 249,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 250,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 252,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "alreadyMoved",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 252,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 252,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 253,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Move the uploaded file to a new location.\n     *\n     * Use this method as an alternative to move_uploaded_file(). This method is\n     * guaranteed to work in both SAPI and non-SAPI environments.\n     * Implementations must determine which environment they are in, and use the\n     * appropriate method (move_uploaded_file(), rename(), or a stream\n     * operation) to perform the operation.\n     *\n     * $targetPath may be an absolute path, or a relative path. If it is a\n     * relative path, resolution should be the same as used by PHP's rename()\n     * function.\n     *\n     * The original file or stream MUST be removed on completion.\n     *\n     * If this method is called more than once, any subsequent calls MUST raise\n     * an exception.\n     *\n     * When used in an SAPI environment where $_FILES is populated, when writing\n     * files via moveTo(), is_uploaded_file() and move_uploaded_file() SHOULD be\n     * used to ensure permissions and upload status are verified correctly.\n     *\n     * If you wish to move to a stream, use getStream(), as SAPI operations\n     * cannot guarantee writing to stream destinations.\n     *\n     * @see http:\/\/php.net\/is_uploaded_file\n     * @see http:\/\/php.net\/move_uploaded_file\n     *\n     * @param string $targetPath Path to which to move the uploaded file.\n     *\n     * @throws InvalidArgumentException if the $targetPath specified is invalid.\n     * @throws RuntimeException on any error during the move operation, or on\n     *     the second or subsequent call to the method.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 212,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 211,
                    "last-line": 259,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkError",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "error",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 260,
                            "char": 42
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
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 262,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Number",
                                        "dynamic": 0,
                                        "name": "between",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "error",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 262,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 262,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 262,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 262,
                                                "char": 54
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "8",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 262,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 262,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 262,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 262,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 262,
                                "char": 59
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
                                                    "value": "Invalid error. Must be one of the UPLOAD_ERR_* constants",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 265,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 265,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 265,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 266,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 268,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "error",
                                    "expr": {
                                        "type": "variable",
                                        "value": "error",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 268,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 268,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 269,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the passed error code and if not in the range throws an exception\n     *\n     * @param int $error\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 261,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 260,
                    "last-line": 276,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "checkStream",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "stream",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 277,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "error",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 277,
                            "char": 55
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
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 279,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "error",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 279,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 279,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 279,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "list",
                                        "left": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 280,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 280,
                                        "char": 27
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "list",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "stream",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 281,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 281,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 281,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 281,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 281,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "fileName",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "stream",
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 282,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 282,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 283,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 284,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 284,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "list",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "stream",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 284,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 284,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "resource",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 284,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 284,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 284,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "stream",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Stream",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "stream",
                                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                            "line": 285,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                        "line": 285,
                                                                        "char": 57
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 285,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 285,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 286,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 287,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 287,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "list",
                                                "left": {
                                                    "type": "instanceof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "stream",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 287,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "StreamInterface",
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 287,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 287,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 287,
                                                "char": 57
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "stream",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "stream",
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 288,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 288,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 289,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 290,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 290,
                                            "char": 23
                                        },
                                        {
                                            "type": "default",
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
                                                                    "value": "Invalid stream or file passed",
                                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                    "line": 291,
                                                                    "char": 85
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                                "line": 291,
                                                                "char": 85
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 291,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 292,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 292,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 293,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 294,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the passed error code and if not in the range throws an exception\n     *\n     * @param StreamInterface|resource|string $stream\n     * @param int                             $error\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 278,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 277,
                    "last-line": 302,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getErrorDescription",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "error",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 303,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "errors",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 305,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 307,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "errors",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 308,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "There is no error, the file uploaded with success.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 308,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 308,
                                                "char": 67
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 309,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "The uploaded file exceeds the upload_max_filesize directive in php.ini.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 309,
                                                    "char": 88
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 309,
                                                "char": 88
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 310,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 310,
                                                    "char": 107
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 310,
                                                "char": 107
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "3",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 311,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "The uploaded file was only partially uploaded.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 311,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 311,
                                                "char": 63
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 312,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "No file was uploaded.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 312,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 312,
                                                "char": 38
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "6",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 313,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "Missing a temporary folder.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 313,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 313,
                                                "char": 44
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "7",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 314,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "Failed to write file to disk.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 314,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 314,
                                                "char": 46
                                            },
                                            {
                                                "key": {
                                                    "type": "int",
                                                    "value": "8",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 315,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "A PHP extension stopped the file upload.",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 316,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 316,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 316,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 316,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 318,
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
                                            "value": "errors",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 318,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 318,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 318,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 318,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Unknown upload error",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 318,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 318,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 318,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 319,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a description string depending on the upload error code passed\n     *\n     * @param int $error\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 304,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 304,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 303,
                    "last-line": 325,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "storeFile",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "targetPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 326,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 328,
                                    "char": 17
                                },
                                {
                                    "variable": "handle",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 328,
                                    "char": 25
                                },
                                {
                                    "variable": "stream",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 328,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 330,
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
                                                    "type": "variable",
                                                    "value": "targetPath",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 330,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 330,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "w+b",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 330,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 330,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 330,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 330,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 331,
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
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 331,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "handle",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 331,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 331,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 331,
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
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 332,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 332,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 332,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 333,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 335,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "stream",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 335,
                                            "char": 27
                                        },
                                        "name": "getStream",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 335,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 335,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 337,
                            "char": 14
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "stream",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 337,
                                    "char": 16
                                },
                                "name": "rewind",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 337,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 339,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 339,
                                    "char": 22
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "stream",
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 339,
                                        "char": 31
                                    },
                                    "name": "eof",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 339,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 339,
                                "char": 38
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
                                                    "value": "stream",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 340,
                                                    "char": 31
                                                },
                                                "name": "read",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "2048",
                                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                            "line": 340,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                        "line": 340,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 340,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 340,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 342,
                                    "char": 18
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
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 342,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 342,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                    "line": 342,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                                "line": 342,
                                                "char": 32
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 342,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                    "line": 343,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 345,
                            "char": 14
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
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                            "line": 345,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                        "line": 345,
                                        "char": 22
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                                "line": 345,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                            "line": 346,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Store a file in the new location (stream)\n     *\n     * @param string $targetPath\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                        "line": 327,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
                    "line": 326,
                    "last-line": 347,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
            "line": 29,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFile.zep",
        "line": 29,
        "char": 11
    }
]