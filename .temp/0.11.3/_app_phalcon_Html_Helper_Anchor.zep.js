[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html\\Helper",
        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Helper\\AbstractHelper",
                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Helper\\Anchor\n *\n * Creates an anchor\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Anchor",
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
                            "name": "href",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 27,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 27,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                "line": 27,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 27,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "overrides",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                    "line": 29,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 31,
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
                                                    "value": "href",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                                    "line": 31,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "variable",
                                                    "value": "href",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                                    "line": 31,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                                "line": 31,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                        "line": 31,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                    "line": 31,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 36,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "attributes",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                    "line": 36,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "href",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                    "line": 36,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                "line": 36,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 38,
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
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "overrides",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                                    "line": 38,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                                "line": 38,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                                    "line": 38,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                                "line": 38,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                        "line": 38,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                    "line": 38,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 40,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                    "line": 40,
                                    "char": 21
                                },
                                "name": "renderFullElement",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "a",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                            "line": 40,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                        "line": 40,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                            "line": 40,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                        "line": 40,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "overrides",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                            "line": 40,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                        "line": 40,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                "line": 40,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                            "line": 41,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var string href       The href tag\n     * @var string text       The text for the anchor\n     * @var array  attributes Any additional attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                                "line": 28,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                        "line": 28,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
                    "line": 27,
                    "last-line": 42,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Helper\/Anchor.zep",
        "line": 20,
        "char": 5
    }
]