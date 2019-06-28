[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate\\Interpolator",
        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Interpolator\\InterpolatorInterface",
                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                "line": 13,
                "char": 57
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
        "line": 15,
        "char": 5
    },
    {
        "type": "class",
        "name": "AssociativeArray",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "InterpolatorInterface",
                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                "line": 16,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "replacePlaceholders",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "translation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                            "line": 20,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                "line": 20,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                            "line": 20,
                            "char": 85
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                    "line": 22,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                    "line": 22,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                            "line": 24,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "placeholders",
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                "line": 24,
                                "char": 40
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "translation",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "str_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "%",
                                                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                                    "line": 26,
                                                                    "char": 19
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                                    "line": 26,
                                                                    "char": 25
                                                                },
                                                                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                                "line": 26,
                                                                "char": 25
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "%",
                                                                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                                "line": 26,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                            "line": 26,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                        "line": 26,
                                                        "char": 28
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                            "line": 27,
                                                            "char": 22
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                        "line": 27,
                                                        "char": 22
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "translation",
                                                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                            "line": 29,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                        "line": 29,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                                "line": 29,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                            "line": 29,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                    "line": 30,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                            "line": 32,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "translation",
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                "line": 32,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                            "line": 33,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Replaces placeholders by the values passed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                                "line": 21,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                        "line": 21,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
                    "line": 20,
                    "last-line": 34,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
            "line": 15,
            "char": 5
        },
        "file": "\/app\/phalcon\/Translate\/Interpolator\/AssociativeArray.zep",
        "line": 15,
        "char": 5
    }
]