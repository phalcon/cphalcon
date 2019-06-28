[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter\\Sanitize",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Filter\\Sanitize\\FloatVal\n *\n * Sanitizes a value to float\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "FloatVal",
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
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                            "line": 23,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "double",
                                "right": {
                                    "type": "fcall",
                                    "name": "filter_var",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "input",
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                                "line": 25,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                            "line": 25,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "constant",
                                                "value": "FILTER_SANITIZE_NUMBER_FLOAT",
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                                "line": 25,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                            "line": 25,
                                            "char": 71
                                        },
                                        {
                                            "parameter": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "flags",
                                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                                            "line": 25,
                                                            "char": 79
                                                        },
                                                        "value": {
                                                            "type": "constant",
                                                            "value": "FILTER_FLAG_ALLOW_FRACTION",
                                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                                            "line": 25,
                                                            "char": 107
                                                        },
                                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                                        "line": 25,
                                                        "char": 107
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                                "line": 25,
                                                "char": 108
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                            "line": 25,
                                            "char": 108
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                    "line": 25,
                                    "char": 109
                                },
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                                "line": 25,
                                "char": 109
                            },
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                            "line": 26,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var mixed input The text to sanitize\n     *",
                    "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Sanitize\/FloatVal.zep",
        "line": 18,
        "char": 5
    }
]