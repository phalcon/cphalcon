[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html\\Helper",
        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Exception",
                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                "line": 13,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Helper\\Img\n *\n * Creates am img tag\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Img",
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
                            "name": "src",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                            "line": 29,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                "line": 29,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                            "line": 29,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "overrides",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                    "line": 31,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                            "line": 33,
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
                                                    "value": "src",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                                    "line": 33,
                                                    "char": 30
                                                },
                                                "value": {
                                                    "type": "variable",
                                                    "value": "src",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                                    "line": 33,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                                "line": 33,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                        "line": 33,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                    "line": 33,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                            "line": 38,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "attributes",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                    "line": 38,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "src",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                    "line": 38,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                "line": 38,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                            "line": 40,
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
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                                    "line": 40,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                                "line": 40,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                                    "line": 40,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                                "line": 40,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                        "line": 40,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                    "line": 40,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                            "line": 42,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                    "line": 42,
                                    "char": 21
                                },
                                "name": "selfClose",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "img",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                            "line": 42,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                        "line": 42,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "overrides",
                                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                            "line": 42,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                        "line": 42,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                "line": 42,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                            "line": 43,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param string $src\n     * @param array  $attributes Any additional attributes\n     *\n     * @return string\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                                "line": 30,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                        "line": 30,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
                    "line": 29,
                    "last-line": 44,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Helper\/Img.zep",
        "line": 20,
        "char": 5
    }
]