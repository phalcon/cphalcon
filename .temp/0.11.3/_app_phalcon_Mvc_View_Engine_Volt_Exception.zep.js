[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\View\\Engine\\Volt",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Exception",
                "alias": "BaseException",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                "line": 13,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Class for exceptions thrown by Phalcon\\Mvc\\View\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Exception",
        "abstract": 0,
        "final": 0,
        "extends": "BaseException",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "statement",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                    "line": 22,
                    "char": 10
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
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 22,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 22,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "statement",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 22,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 22,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 22,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 22,
                            "char": 86
                        },
                        {
                            "type": "parameter",
                            "name": "previous",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "\\Exception",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 22,
                                "char": 108
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 22,
                                "char": 116
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 22,
                            "char": 116
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
                                    "property": "statement",
                                    "expr": {
                                        "type": "variable",
                                        "value": "statement",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                        "line": 24,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                    "line": 24,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 26,
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
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                            "line": 26,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                        "line": 26,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "code",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                            "line": 26,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                        "line": 26,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "previous",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                            "line": 26,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                        "line": 26,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 26,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 27,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                    "line": 22,
                    "last-line": 31,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStatement",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "statement",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                    "line": 34,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 36,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "statement",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                            "line": 36,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "statement",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                            "line": 36,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                        "line": 36,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                    "line": 36,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 38,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "statement",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                        "line": 38,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                    "line": 38,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                    "line": 38,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 38,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "statement",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                                "line": 39,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                            "line": 39,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                    "line": 40,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 42,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "statement",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 42,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                            "line": 43,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets currently parsed statement (if any).\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                                "line": 33,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
                    "line": 32,
                    "last-line": 44,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Volt\/Exception.zep",
        "line": 18,
        "char": 5
    }
]