[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations",
        "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Parses docblocks returning an array with the found annotations\n *",
        "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ReaderInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "parse",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                            "line": 21,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Reads annotations from the class docblocks, its methods and\/or properties\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                                "line": 21,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                        "line": 21,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                    "line": 21,
                    "last-line": 25,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "parseDocBlock",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "docBlock",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                            "line": 26,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                                "line": 26,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                            "line": 26,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "line",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                                "line": 26,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                            "line": 26,
                            "char": 83
                        }
                    ],
                    "docblock": "**\n     * Parses a raw docblock returning the annotations found\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                                "line": 26,
                                "char": 93
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                        "line": 26,
                        "char": 93
                    },
                    "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
                    "line": 26,
                    "last-line": 27,
                    "char": 26
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
            "line": 27,
            "char": 1
        },
        "file": "\/app\/phalcon\/Annotations\/ReaderInterface.zep",
        "line": 0,
        "char": 0
    }
]