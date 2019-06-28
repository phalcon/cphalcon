[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\View\\Engine",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                "line": 14,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ViewBaseInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                "line": 15,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * All the template engine adapters must inherit this class. This provides\n * basic interfacing between the engine and the Phalcon\\Mvc\\View component.\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
        "line": 21,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractEngine",
        "abstract": 1,
        "final": 0,
        "extends": "Injectable",
        "implements": [
            {
                "type": "variable",
                "value": "EngineInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                "line": 22,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "view",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                    "line": 27,
                    "char": 6
                }
            ],
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
                            "name": "view",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ViewBaseInterface",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 28,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 28,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 28,
                                "char": 81
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 28,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 28,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "view",
                                    "expr": {
                                        "type": "variable",
                                        "value": "view",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 30,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                    "line": 30,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 31,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 31,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                    "line": 31,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 32,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\View\\Engine constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                    "line": 28,
                    "last-line": 36,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContent",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 39,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "view",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 39,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                    "line": 39,
                                    "char": 27
                                },
                                "name": "getContent",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 39,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns cached output on another view stage\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 38,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                        "line": 38,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                    "line": 37,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getView",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                    "line": 47,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                    "line": 47,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 47,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 48,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the view component related to the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ViewBaseInterface",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                    "line": 46,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 46,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                        "line": 46,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                    "line": 45,
                    "last-line": 54,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "partial",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "partialPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 55,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 55,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 55,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 57,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "view",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 57,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                    "line": 57,
                                    "char": 27
                                },
                                "name": "partial",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "partialPath",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                            "line": 57,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 57,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                            "line": 57,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                        "line": 57,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 57,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                            "line": 58,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a partial inside another view\n     *\n     * @param array params\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                                "line": 56,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                        "line": 56,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
                    "line": 55,
                    "last-line": 59,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
            "line": 21,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/AbstractEngine.zep",
        "line": 21,
        "char": 14
    }
]