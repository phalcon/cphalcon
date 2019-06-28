[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter\\Sanitize",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Filter\\Sanitize\\Alpha\n *\n * Sanitizes a value to an alpha value\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Alpha",
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
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                            "line": 23,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "preg_replace",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\/[^A-Za-z]\/",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                                            "line": 25,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                                        "line": 25,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                                            "line": 25,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                                        "line": 25,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "input",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                                            "line": 25,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                                        "line": 25,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                                "line": 25,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                            "line": 26,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var mixed input The text to sanitize\n     *",
                    "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alpha.zep",
        "line": 18,
        "char": 5
    }
]