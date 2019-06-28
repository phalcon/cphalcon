[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html\\Helper",
        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Helper\\AbstractHelper",
                "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Helper\\Address\n *\n * Creates an element\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Element",
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
                            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                            "line": 27,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                            "line": 27,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                "line": 27,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                            "line": 27,
                            "char": 78
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
                                    "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                    "line": 29,
                                    "char": 21
                                },
                                "name": "renderFullElement",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "tag",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                            "line": 29,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                        "line": 29,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                            "line": 29,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                        "line": 29,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                            "line": 29,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                        "line": 29,
                                        "char": 61
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                "line": 29,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                            "line": 30,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var string tag        The tag name\n     * @var string text       The text for the anchor\n     * @var array  attributes Any additional attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                                "line": 28,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                        "line": 28,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
                    "line": 27,
                    "last-line": 31,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Helper\/Element.zep",
        "line": 20,
        "char": 5
    }
]