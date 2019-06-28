[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Request",
        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Http\\Request\\FileInterface\n *\n * Interface for Phalcon\\Http\\Request\\File\n *\n *",
        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "interface",
        "name": "FileInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "docblock": "**\n     * Returns the real name of the uploaded file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                                "line": 24,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                        "line": 24,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                    "line": 24,
                    "last-line": 28,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRealType",
                    "docblock": "**\n     * Gets the real mime type of the upload file using finfo\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                                "line": 29,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                        "line": 29,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                    "line": 29,
                    "last-line": 33,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSize",
                    "docblock": "**\n     * Returns the file size of the uploaded file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                                "line": 34,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                        "line": 34,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                    "line": 34,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTempName",
                    "docblock": "**\n     * Returns the temporal name of the uploaded file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                                "line": 39,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                        "line": 39,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                    "line": 39,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "docblock": "**\n     * Returns the mime type reported by the browser\n     * This mime type is not completely secure, use getRealType() instead\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                                "line": 45,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                        "line": 45,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                    "line": 45,
                    "last-line": 49,
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
                            "name": "destination",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                            "line": 50,
                            "char": 47
                        }
                    ],
                    "docblock": "**\n     * Move the temporary file to a destination\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                                "line": 50,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                        "line": 50,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
                    "line": 50,
                    "last-line": 51,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
            "line": 51,
            "char": 1
        },
        "file": "\/app\/phalcon\/Http\/Request\/FileInterface.zep",
        "line": 0,
        "char": 0
    }
]