[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate\\Interpolator",
        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Interpolator\\InterpolatorInterface",
                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                "line": 13,
                "char": 57
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
        "line": 15,
        "char": 5
    },
    {
        "type": "class",
        "name": "IndexedArray",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "InterpolatorInterface",
                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
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
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
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
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                "line": 20,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                            "line": 20,
                            "char": 85
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                            "line": 22,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                        "line": 22,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                "line": 22,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_unshift",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "placeholders",
                                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                    "line": 23,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                "line": 23,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "translation",
                                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                    "line": 23,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                "line": 23,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                        "line": 23,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                    "line": 25,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "call_user_func_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "sprintf",
                                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                    "line": 25,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                "line": 25,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "placeholders",
                                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                    "line": 25,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                                "line": 25,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                        "line": 25,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                    "line": 26,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                            "line": 28,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "translation",
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                "line": 28,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                            "line": 29,
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
                                "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                                "line": 21,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                        "line": 21,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
                    "line": 20,
                    "last-line": 30,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
            "line": 15,
            "char": 5
        },
        "file": "\/app\/phalcon\/Translate\/Interpolator\/IndexedArray.zep",
        "line": 15,
        "char": 5
    }
]