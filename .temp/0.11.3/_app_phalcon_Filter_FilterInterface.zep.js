[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter",
        "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Lazy loads, stores and exposes sanitizer objects\n *",
        "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "FilterInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sanitize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
                            "line": 21,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "sanitizers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
                            "line": 21,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "noRecursive",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
                                "line": 21,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
                            "line": 21,
                            "char": 81
                        }
                    ],
                    "docblock": "**\n     * Sanitizes a value with a specified single or set of sanitizers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
                                "line": 21,
                                "char": 89
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
                        "line": 21,
                        "char": 89
                    },
                    "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
                    "line": 21,
                    "last-line": 22,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
            "line": 22,
            "char": 1
        },
        "file": "\/app\/phalcon\/Filter\/FilterInterface.zep",
        "line": 0,
        "char": 0
    }
]