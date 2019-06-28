[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Attributes.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html",
        "file": "\/app\/phalcon\/Html\/Attributes.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Html\/Attributes.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Attributes\\RenderInterface",
                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Html\/Attributes.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag",
                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                "line": 15,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Html\/Attributes.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class helps to work with HTML Attributes\n *",
        "file": "\/app\/phalcon\/Html\/Attributes.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Attributes",
        "abstract": 0,
        "final": 0,
        "extends": "Collection",
        "implements": [
            {
                "type": "variable",
                "value": "RenderInterface",
                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                "line": 21,
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
                    "name": "render",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Tag",
                                "dynamic": 0,
                                "name": "renderAttributes",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "",
                                            "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                            "line": 27,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                        "line": 27,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                                "line": 27,
                                                "char": 45
                                            },
                                            "name": "toArray",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                            "line": 27,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                        "line": 27,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                "line": 27,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Html\/Attributes.zep",
                            "line": 28,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Render attributes as HTML attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                "line": 26,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Attributes.zep",
                        "line": 26,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Attributes.zep",
                    "line": 25,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__toString",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                    "line": 35,
                                    "char": 21
                                },
                                "name": "render",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                "line": 35,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Html\/Attributes.zep",
                            "line": 36,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias of the render method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Attributes.zep",
                                "line": 34,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Attributes.zep",
                        "line": 34,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Attributes.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Attributes.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Attributes.zep",
        "line": 20,
        "char": 5
    }
]