[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html\\Helper",
        "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Helper\\Close\n *\n * Creates a closing tag\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Close",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractHelper",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__invoke",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tag",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                            "line": 25,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "<\/",
                                        "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                                        "line": 27,
                                        "char": 19
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "tag",
                                        "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                                        "line": 27,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                                    "line": 27,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": ">",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                                    "line": 27,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                                "line": 27,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                            "line": 28,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param string $tag The tag\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                                "line": 26,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                        "line": 26,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Helper\/Close.zep",
        "line": 18,
        "char": 5
    }
]