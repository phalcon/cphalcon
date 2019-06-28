[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Exception.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Exception.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Throwable",
                "file": "\/app\/phalcon\/Exception.zep",
                "line": 13,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Exception.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Exception\n *\n * All framework exceptions should use or extend this exception\n *",
        "file": "\/app\/phalcon\/Exception.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Exception",
        "abstract": 0,
        "final": 0,
        "extends": "\\Exception",
        "implements": [
            {
                "type": "variable",
                "value": "Throwable",
                "file": "\/app\/phalcon\/Exception.zep",
                "line": 21,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "containerServiceNotFound",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "service",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Exception.zep",
                            "line": 22,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "A dependency injection container is required to access ",
                                    "file": "\/app\/phalcon\/Exception.zep",
                                    "line": 24,
                                    "char": 72
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "service",
                                    "file": "\/app\/phalcon\/Exception.zep",
                                    "line": 24,
                                    "char": 81
                                },
                                "file": "\/app\/phalcon\/Exception.zep",
                                "line": 24,
                                "char": 81
                            },
                            "file": "\/app\/phalcon\/Exception.zep",
                            "line": 25,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Exception.zep",
                                "line": 23,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Exception.zep",
                        "line": 23,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Exception.zep",
                    "line": 22,
                    "last-line": 26,
                    "char": 26
                }
            ],
            "file": "\/app\/phalcon\/Exception.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Exception.zep",
        "line": 20,
        "char": 5
    }
]