[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Forms\\Element",
        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Forms\\Element",
                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag\\Select",
                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Forms\\Element\\Select\n *\n * Component SELECT (choice) for forms\n *",
        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "Select",
        "abstract": 0,
        "final": 0,
        "extends": "Element",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "optionsValues",
                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                    "line": 30,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 31,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 31,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 31,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 31,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 31,
                            "char": 79
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
                                    "property": "optionsValues",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 33,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 33,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 35,
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
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                            "line": 35,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 35,
                                        "char": 33
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                            "line": 35,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 35,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 35,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 36,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Forms\\Element constructor\n     *\n     * @param object|array options\n     * @param array        attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                        "line": 32,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                    "line": 31,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 43,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 45,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 45,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 47,
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
                                        "value": "option",
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 47,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 47,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 47,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 47,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "option",
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 48,
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
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "optionsValues",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                            "line": 49,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                        "line": 49,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                    "line": 49,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                            "line": 50,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 51,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "optionsValues",
                                            "expr": {
                                                "type": "variable",
                                                "value": "option",
                                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                "line": 52,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                            "line": 52,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 53,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 55,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 55,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 56,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an option to the current options\n     *\n     * @param array option\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Element",
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 44,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 44,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                        "line": 44,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                    "line": 43,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 65,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "optionsValues",
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 65,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 65,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 66,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the choices' options\n     *\n     * @return array|object\n     *",
                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                    "line": 63,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 71,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 71,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Select",
                                "dynamic": 0,
                                "name": "selectField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                "line": 77,
                                                "char": 18
                                            },
                                            "name": "prepareAttributes",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                        "line": 77,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                    "line": 77,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                            "line": 77,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 77,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                "line": 78,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "optionsValues",
                                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                                "line": 79,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                            "line": 79,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 79,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 79,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 80,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders the element widget returning html\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 72,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                    "line": 71,
                    "last-line": 86,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 87,
                            "char": 43
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
                                    "property": "optionsValues",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                        "line": 89,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 89,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 91,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 91,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                            "line": 92,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the choice's options\n     *\n     * @param array|object options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Element",
                                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                    "line": 88,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                                "line": 88,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                        "line": 88,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
                    "line": 87,
                    "last-line": 93,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Forms\/Element\/Select.zep",
        "line": 21,
        "char": 5
    }
]