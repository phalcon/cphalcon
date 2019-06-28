[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Assets\\Inline",
        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Inline",
                "alias": "InlineBase",
                "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                "line": 13,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents an inlined CSS\n *",
        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Css",
        "abstract": 0,
        "final": 0,
        "extends": "InlineBase",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                            "line": 23,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                "line": 23,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                            "line": 23,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                "line": 23,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                            "line": 23,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "attributes",
                                    "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                    "line": 25,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                    "line": 25,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                "line": 25,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "attributes",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "type",
                                                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                                            "line": 27,
                                                            "char": 21
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "text\/css",
                                                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                                            "line": 28,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                                        "line": 28,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                                "line": 28,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                            "line": 28,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                    "line": 29,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                            "line": 31,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "css",
                                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                            "line": 31,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                        "line": 31,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                            "line": 31,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                        "line": 31,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "filter",
                                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                            "line": 31,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                        "line": 31,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                            "line": 31,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                        "line": 31,
                                        "char": 61
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                                "line": 31,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                            "line": 32,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Assets\\Inline\\Css constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                        "line": 24,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
                    "line": 23,
                    "last-line": 33,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Assets\/Inline\/Css.zep",
        "line": 18,
        "char": 5
    }
]