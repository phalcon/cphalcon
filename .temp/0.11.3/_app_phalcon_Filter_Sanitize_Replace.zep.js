[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter\\Sanitize",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Filter\\Sanitize\\Replace\n *\n * Sanitizes a value replacing parts of a string\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Replace",
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
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                            "line": 23,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "from",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                            "line": 23,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "to",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                            "line": 23,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "str_replace",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "from",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                                            "line": 25,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                                        "line": 25,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "to",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                                            "line": 25,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                                        "line": 25,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "input",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                                            "line": 25,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                                        "line": 25,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                                "line": 25,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                            "line": 26,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var mixed input The text to sanitize\n     *",
                    "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Replace.zep",
        "line": 18,
        "char": 5
    }
]