[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html\\Helper",
        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Exception",
                "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                "line": 13,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Helper\\ElementRaw\n *\n * Creates an element raw\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "ElementRaw",
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
                            "name": "tag",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                            "line": 30,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                            "line": 30,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                "line": 30,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                            "line": 30,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                    "line": 32,
                                    "char": 21
                                },
                                "name": "renderFullElement",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "tag",
                                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                            "line": 32,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                        "line": 32,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                            "line": 32,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                        "line": 32,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                            "line": 32,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                        "line": 32,
                                        "char": 61
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                            "line": 32,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                        "line": 32,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                "line": 32,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                            "line": 33,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param string $tag        The tag for the anchor\n     * @param string $text       The text for the anchor\n     * @param array  $attributes Any additional attributes\n     *\n     * @return string\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                                "line": 31,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                        "line": 31,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Helper\/ElementRaw.zep",
        "line": 20,
        "char": 5
    }
]