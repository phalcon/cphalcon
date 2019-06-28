[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter\\Sanitize",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Filter\\Sanitize\\Alnum\n *\n * Sanitizes a value to an alphanumeric value\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Alnum",
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
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
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
                                            "value": "\/[^A-Za-z0-9]\/",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                                            "line": 25,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                                        "line": 25,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                                            "line": 25,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                                        "line": 25,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "input",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                                            "line": 25,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                                        "line": 25,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                                "line": 25,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                            "line": 26,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var mixed input The text to sanitize\n     *",
                    "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Alnum.zep",
        "line": 18,
        "char": 5
    }
]