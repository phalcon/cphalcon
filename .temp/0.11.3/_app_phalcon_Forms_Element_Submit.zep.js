[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Forms\\Element",
        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag",
                "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Forms\\Element",
                "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                "line": 14,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Component INPUT[type=submit] for forms\n *",
        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Submit",
        "abstract": 0,
        "final": 0,
        "extends": "Element",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                "line": 24,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                            "line": 24,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Tag",
                                "dynamic": 0,
                                "name": "submitButton",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                                "line": 30,
                                                "char": 18
                                            },
                                            "name": "prepareAttributes",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                                        "line": 30,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                                    "line": 30,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                            "line": 31,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                        "line": 31,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                "line": 31,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                            "line": 32,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders the element widget\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                                "line": 25,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                        "line": 25,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
                    "line": 24,
                    "last-line": 33,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Forms\/Element\/Submit.zep",
        "line": 19,
        "char": 5
    }
]