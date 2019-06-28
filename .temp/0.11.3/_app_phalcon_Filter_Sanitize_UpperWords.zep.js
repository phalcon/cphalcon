[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter\\Sanitize",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Filter\\Sanitize\\UpperWords\n *\n * Sanitizes a value to uppercase teh first character of each word\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "UpperWords",
        "abstract": 0,
        "final": 0,
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
                            "name": "input",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                            "line": 23,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                    "line": 25,
                                    "char": 19
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "function_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "mb_convert_case",
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                "line": 25,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                            "line": 25,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                    "line": 25,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                "line": 25,
                                "char": 54
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_convert_case",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "input",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                    "line": 26,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                "line": 26,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "MB_CASE_TITLE",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                    "line": 26,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                "line": 26,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "UTF-8",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                    "line": 26,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                "line": 26,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                        "line": 26,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                    "line": 27,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                            "line": 29,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "ucwords",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "utf8_decode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "input",
                                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                        "line": 29,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                                    "line": 29,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                            "line": 29,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                        "line": 29,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                                "line": 29,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                            "line": 30,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var mixed input The text to sanitize\n     *",
                    "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
                    "line": 23,
                    "last-line": 31,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Sanitize\/UpperWords.zep",
        "line": 18,
        "char": 5
    }
]