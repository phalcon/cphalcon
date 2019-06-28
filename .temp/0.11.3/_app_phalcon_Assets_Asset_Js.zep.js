[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Assets\\Asset",
        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\Asset",
                "alias": "AssetBase",
                "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents Javascript assets\n *",
        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Js",
        "abstract": 0,
        "final": 0,
        "extends": "AssetBase",
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
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                            "line": 24,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                "line": 25,
                                "char": 26
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                            "line": 25,
                            "char": 26
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
                                "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                "line": 26,
                                "char": 27
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                            "line": 26,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                "line": 27,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                            "line": 27,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "version",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                "line": 28,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                            "line": 28,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "autoVersion",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                "line": 30,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                            "line": 30,
                            "char": 5
                        }
                    ],
                    "statements": [
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
                                            "value": "js",
                                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                            "line": 32,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                        "line": 32,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                            "line": 32,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                        "line": 32,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "local",
                                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                            "line": 32,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                        "line": 32,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "filter",
                                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                            "line": 32,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                        "line": 32,
                                        "char": 52
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                            "line": 32,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                        "line": 32,
                                        "char": 64
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "version",
                                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                            "line": 32,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                        "line": 32,
                                        "char": 73
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "autoVersion",
                                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                            "line": 32,
                                            "char": 86
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                        "line": 32,
                                        "char": 86
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                                "line": 32,
                                "char": 87
                            },
                            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                            "line": 33,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Assets\\Asset\\Js constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                        "line": 31,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
                    "line": 23,
                    "last-line": 34,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Assets\/Asset\/Js.zep",
        "line": 18,
        "char": 5
    }
]