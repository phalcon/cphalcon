[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html\\Helper",
        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Helper\\AbstractHelper",
                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Helper\\Form\n *\n * Creates a form opening tag\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Form",
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
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                "line": 25,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                            "line": 25,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "overrides",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                    "line": 27,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                            "line": 29,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "overrides",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                    "line": 30,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "post",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                    "line": 30,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                "line": 30,
                                                "char": 27
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "enctype",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                    "line": 31,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "multipart\/form-data",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                    "line": 32,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                "line": 32,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                        "line": 32,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                    "line": 32,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                            "line": 34,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "overrides",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                            "line": 34,
                                            "char": 30
                                        },
                                        "name": "orderAttributes",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "overrides",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                    "line": 34,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                "line": 34,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                    "line": 34,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                                "line": 34,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                        "line": 34,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                    "line": 34,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                            "line": 36,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                    "line": 36,
                                    "char": 21
                                },
                                "name": "renderElement",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "form",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                            "line": 36,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                        "line": 36,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "overrides",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                            "line": 36,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                        "line": 36,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                "line": 36,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                            "line": 37,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var array  attributes Any additional attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                                "line": 26,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                        "line": 26,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
                    "line": 25,
                    "last-line": 38,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Helper\/Form.zep",
        "line": 20,
        "char": 5
    }
]