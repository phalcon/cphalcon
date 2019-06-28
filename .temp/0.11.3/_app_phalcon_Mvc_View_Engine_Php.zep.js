[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\View\\Engine",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Engine\\AbstractEngine",
                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                "line": 13,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Adapter to use PHP itself as templating engine\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Php",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractEngine",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 23,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 23,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "mustClean",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                "line": 23,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 23,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                    "line": 25,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                    "line": 25,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 27,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "mustClean",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                "line": 27,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "ob_clean",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                        "line": 28,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                    "line": 29,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 34,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                        "line": 34,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                    "line": 34,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                    "line": 34,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                "line": 34,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                        "line": 35,
                                        "char": 38
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "dynamic-variable",
                                                    "operator": "assign",
                                                    "variable": "key",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                                        "line": 36,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                                    "line": 36,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                            "line": 37,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                    "line": 38,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 43,
                            "char": 15
                        },
                        {
                            "type": "require",
                            "expr": {
                                "type": "variable",
                                "value": "path",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                "line": 43,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 45,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "mustClean",
                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                "line": 45,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                                "line": 46,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "view",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                                "line": 46,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                            "line": 46,
                                            "char": 24
                                        },
                                        "name": "setContent",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "ob_get_contents",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                                    "line": 46,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                                "line": 46,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                        "line": 46,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                                    "line": 47,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                            "line": 48,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a view using the template engine\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
                    "line": 23,
                    "last-line": 49,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/View\/Engine\/Php.zep",
        "line": 18,
        "char": 5
    }
]