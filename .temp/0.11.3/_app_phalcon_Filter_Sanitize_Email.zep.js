[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter\\Sanitize",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Filter\\Sanitize\\Email\n *\n * Sanitizes an email string\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Email",
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
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                            "line": 23,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "filter_var",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "input",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                                            "line": 26,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                                        "line": 26,
                                        "char": 18
                                    },
                                    {
                                        "parameter": {
                                            "type": "constant",
                                            "value": "FILTER_SANITIZE_EMAIL",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                                            "line": 27,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                                        "line": 27,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "constant",
                                            "value": "FILTER_FLAG_EMAIL_UNICODE",
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                                            "line": 29,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                                        "line": 29,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                                "line": 29,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                            "line": 30,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var mixed input The text to sanitize\n     *",
                    "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
                    "line": 23,
                    "last-line": 31,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Sanitize\/Email.zep",
        "line": 18,
        "char": 5
    }
]