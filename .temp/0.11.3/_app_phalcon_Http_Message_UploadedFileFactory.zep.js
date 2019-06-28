[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\UploadedFile",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                "line": 17,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\StreamInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                "line": 18,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UploadedFileInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                "line": 19,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Http\\Message\\UploadedFileFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                "line": 20,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-17 UploadedFileFactory\n *",
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "UploadedFileFactory",
        "abstract": 0,
        "final": 1,
        "implements": [
            {
                "type": "variable",
                "value": "UploadedFileFactoryInterface",
                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
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
                    "name": "createUploadedFile",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "stream",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "StreamInterface",
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                "line": 46,
                                "char": 32
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                            "line": 46,
                            "char": 33
                        },
                        {
                            "type": "parameter",
                            "name": "size",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                "line": 47,
                                "char": 24
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                            "line": 47,
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
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                "line": 48,
                                "char": 22
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                            "line": 48,
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
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                "line": 49,
                                "char": 37
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                            "line": 49,
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
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                "line": 51,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                            "line": 51,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "UploadedFile",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "stream",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                            "line": 54,
                                            "char": 19
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                        "line": 54,
                                        "char": 19
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "size",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                            "line": 55,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                        "line": 55,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                            "line": 56,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                        "line": 56,
                                        "char": 18
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "clientFilename",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                            "line": 57,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                        "line": 57,
                                        "char": 27
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "clientMediaType",
                                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                            "line": 59,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                        "line": 59,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                "line": 59,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                            "line": 60,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new uploaded file.\n     *\n     * If a size is not provided it will be determined by checking the size of\n     * the stream.\n     *\n     * @link http:\/\/php.net\/manual\/features.file-upload.post-method.php\n     * @link http:\/\/php.net\/manual\/features.file-upload.errors.php\n     *\n     * @param StreamInterface $stream          The underlying stream representing the\n     *                                         uploaded file content.\n     * @param int             $size            The size of the file in bytes.\n     * @param int             $error           The PHP file upload error.\n     * @param string          $clientFilename  The filename as provided by the client, if any.\n     * @param string          $clientMediaType The media type as provided by the client, if any.\n     *\n     * @throws \\InvalidArgumentException If the file resource is not readable.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UploadedFileInterface",
                                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                    "line": 52,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                                "line": 52,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                        "line": 52,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
                    "line": 45,
                    "last-line": 61,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
            "line": 25,
            "char": 11
        },
        "file": "\/app\/phalcon\/Http\/Message\/UploadedFileFactory.zep",
        "line": 25,
        "char": 11
    }
]