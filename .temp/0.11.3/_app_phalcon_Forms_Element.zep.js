[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Forms",
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "InvalidArgumentException",
                "file": "\/app\/phalcon\/Forms\/Element.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag",
                "file": "\/app\/phalcon\/Forms\/Element.zep",
                "line": 14,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Forms\\Exception",
                "file": "\/app\/phalcon\/Forms\/Element.zep",
                "line": 15,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Forms\/Element.zep",
                "line": 16,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Messages",
                "file": "\/app\/phalcon\/Forms\/Element.zep",
                "line": 17,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\ValidatorInterface",
                "file": "\/app\/phalcon\/Forms\/Element.zep",
                "line": 18,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is a base class for form elements\n *",
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 23,
        "char": 8
    },
    {
        "type": "class",
        "name": "Element",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ElementInterface",
                "file": "\/app\/phalcon\/Forms\/Element.zep",
                "line": 24,
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
                    "name": "attributes",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 26,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "filters",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 27,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "form",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 28,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "label",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 29,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messages",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 30,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 31,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "validators",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 36,
                        "char": 30
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 38,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "value",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 45,
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
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 46,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 46,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 46,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "trim",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 48,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 48,
                                                "char": 29
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 48,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 48,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 50,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 50,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 50,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 50,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Form element name is required",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 53,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 53,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 53,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 54,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 56,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 56,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 56,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 57,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "attributes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 57,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 57,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 58,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "messages",
                                    "expr": {
                                        "type": "new",
                                        "class": "Messages",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 58,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 58,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Forms\\Element constructor\n     *\n     * @param string name       Attribute name (value of 'name' attribute of HTML element)\n     * @param array  attributes Additional HTML element attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 47,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 46,
                    "last-line": 63,
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
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 66,
                                    "char": 21
                                },
                                "name": "render",
                                "call-type": 3,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 66,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic method __toString renders the widget without attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 64,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addFilter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 72,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "filters",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 74,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 76,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filters",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 76,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "filters",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 76,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 76,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 76,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 78,
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
                                        "value": "filters",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 78,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 78,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 78,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 78,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "filters",
                                            "expr": {
                                                "type": "variable",
                                                "value": "filter",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 79,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 79,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "filters",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 81,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 81,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 81,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 81,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "filters",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "filters",
                                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                    "line": 82,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                "line": 82,
                                                                "char": 45
                                                            },
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "filter",
                                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                    "line": 82,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                "line": 82,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 82,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 82,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 83,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "filters",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "filter",
                                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                    "line": 84,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                "line": 84,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 84,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 84,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 85,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 86,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 88,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 88,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 89,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a filter to current list of filters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 73,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 73,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 73,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 72,
                    "last-line": 93,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addValidator",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "validator",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ValidatorInterface",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 94,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 94,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "validators",
                                    "expr": {
                                        "type": "variable",
                                        "value": "validator",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 96,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 96,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 98,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a validator to the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 95,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 95,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 95,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 94,
                    "last-line": 105,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addValidators",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "validators",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 106,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 106,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 106,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 108,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "validators",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                "line": 110,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "validators",
                                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                "line": 110,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 110,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 110,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "validators",
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 112,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 112,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 112,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 112,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 113,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 115,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "validators",
                                    "expr": {
                                        "type": "variable",
                                        "value": "validators",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 115,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 115,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 117,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 117,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a group of validators\n     *\n     * @param \\Phalcon\\Validation\\ValidatorInterface[] validators\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 107,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 107,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 107,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 106,
                    "last-line": 122,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "appendMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "MessageInterface",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 123,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 123,
                            "char": 61
                        }
                    ],
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
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 125,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 125,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 125,
                                    "char": 24
                                },
                                "name": "appendMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 125,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 125,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 125,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 127,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 127,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 128,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Appends a message to the internal message list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 124,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 124,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 124,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 123,
                    "last-line": 132,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "form",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 135,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "form",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 135,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 135,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 135,
                                    "char": 31
                                },
                                {
                                    "variable": "name",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 136,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 136,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 136,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 136,
                                    "char": 31
                                },
                                {
                                    "variable": "value",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 137,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 137,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 137,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 137,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 139,
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
                                        "value": "form",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 139,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 139,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 139,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 139,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "form",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 140,
                                            "char": 18
                                        },
                                        "name": "clear",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 140,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 140,
                                                "char": 29
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 140,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 141,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "scall",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Tag",
                                        "dynamic": 0,
                                        "name": "setDefault",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 142,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 142,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 142,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 142,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 142,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 143,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 145,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 145,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 146,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Clears element to its default value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 134,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 133,
                    "last-line": 150,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 151,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 151,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 151,
                            "char": 75
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 153,
                                    "char": 23
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 153,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 155,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "attributes",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 155,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 155,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 155,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 155,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 157,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 157,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 157,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "attribute",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 157,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 157,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 157,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 157,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 158,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 159,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 161,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 161,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 162,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the value of an attribute if present\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 152,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 152,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 151,
                    "last-line": 166,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAttributes",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 169,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 171,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "attributes",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 171,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 171,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 171,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 171,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 173,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "attributes",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 173,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 174,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default attributes for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 168,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 168,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 167,
                    "last-line": 178,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefault",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 181,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 181,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 181,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 182,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default value assigned to the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 180,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 180,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 179,
                    "last-line": 188,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFilters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 191,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "filters",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 191,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 191,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 192,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the element filters\n     *\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 189,
                    "last-line": 196,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getForm",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 199,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "form",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 199,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 199,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 200,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the parent form to the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 198,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 198,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 198,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 197,
                    "last-line": 204,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLabel",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 207,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "label",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 207,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 207,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 208,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the element label\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 206,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 206,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 205,
                    "last-line": 213,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 216,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "messages",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 216,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 216,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 217,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the messages that belongs to the element\n     * The element needs to be attached to a form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Messages",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 215,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 215,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 215,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 214,
                    "last-line": 221,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 224,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 224,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 224,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 225,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the element name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 223,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 223,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 222,
                    "last-line": 229,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUserOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 230,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 230,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 230,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 232,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 234,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 234,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 234,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 234,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 234,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "option",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 234,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 234,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 234,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 234,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 235,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 236,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 238,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 238,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 239,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the value of an option if present\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 231,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 231,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 230,
                    "last-line": 243,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUserOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 246,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 246,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 246,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 247,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the options for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 245,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 245,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 244,
                    "last-line": 251,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getValidators",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 254,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "validators",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 254,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 254,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 255,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the validators registered for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ValidatorInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 253,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 253,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 253,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 252,
                    "last-line": 259,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getValue",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 262,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 262,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 262,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 262,
                                    "char": 31
                                },
                                {
                                    "variable": "form",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 263,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "form",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 263,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 263,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 263,
                                    "char": 31
                                },
                                {
                                    "variable": "value",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 264,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 264,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 269,
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
                                        "value": "form",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 269,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 269,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 269,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 269,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "form",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 270,
                                            "char": 25
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 270,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 270,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 270,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 271,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 276,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Tag",
                                "dynamic": 0,
                                "name": "hasValue",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 276,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 276,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 276,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Tag",
                                                "dynamic": 0,
                                                "name": "getValue",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 277,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 277,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 277,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 277,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 278,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 284,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 284,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 284,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 284,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 285,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 285,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 285,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 285,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 286,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 288,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 288,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 289,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the element's value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 261,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 261,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 260,
                    "last-line": 293,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasMessages",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 296,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "messages",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 296,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 296,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 296,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 296,
                                    "char": 38
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 296,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 296,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 297,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether there are messages attached to the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 295,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 295,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 294,
                    "last-line": 301,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "label",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 302,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 302,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "internalAttributes",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 304,
                                    "char": 31
                                },
                                {
                                    "variable": "label",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 304,
                                    "char": 38
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 304,
                                    "char": 44
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 304,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 309,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "internalAttributes",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 309,
                                            "char": 39
                                        },
                                        "name": "getAttributes",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 309,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 309,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 311,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 311,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "internalAttributes",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 311,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 311,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 311,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 311,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 311,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "name",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 312,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 312,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 312,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 312,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 313,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 315,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 315,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "for",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 315,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 315,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 315,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 315,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "attributes",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "for",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 316,
                                                    "char": 31
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 316,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 316,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 317,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 319,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
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
                                                    "value": "<label",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 319,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 319,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 319,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 319,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 319,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 319,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 324,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "label",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 324,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "label",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 324,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 324,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 324,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 326,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "variable",
                                    "value": "label",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 326,
                                    "char": 19
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "is_numeric",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "label",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 326,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 326,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 326,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 326,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": ">",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 327,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "label",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 327,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 327,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "<\/label>",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 327,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 327,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 327,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 328,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": ">",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 329,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 329,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 329,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "<\/label>",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 329,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 329,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 329,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 330,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 332,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 332,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 333,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate the HTML to label the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 303,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 303,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 302,
                    "last-line": 338,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "prepareAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 339,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 339,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "useChecked",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 339,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 339,
                            "char": 85
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 341,
                                    "char": 18
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 341,
                                    "char": 24
                                },
                                {
                                    "variable": "mergedAttributes",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 341,
                                    "char": 42
                                },
                                {
                                    "variable": "defaultAttributes",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 341,
                                    "char": 61
                                },
                                {
                                    "variable": "currentValue",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 341,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 343,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 343,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 343,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 343,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 343,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 345,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "attributes",
                                    "index-expr": [
                                        {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 345,
                                            "char": 25
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 345,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 345,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 350,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "defaultAttributes",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 350,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 350,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 350,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 350,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 352,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mergedAttributes",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "defaultAttributes",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 353,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 353,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 355,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 355,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 355,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 355,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 360,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 360,
                                            "char": 26
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 360,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 360,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 365,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 365,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 365,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 365,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "useChecked",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 366,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "currentValue",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 372,
                                                    "char": 64
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "mergedAttributes",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 372,
                                                        "char": 56
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 372,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 372,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 372,
                                                "char": 64
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "currentValue",
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 373,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 373,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 373,
                                                        "char": 46
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "mergedAttributes",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "string",
                                                                            "value": "checked",
                                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                            "line": 374,
                                                                            "char": 53
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "string",
                                                                        "value": "checked",
                                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                        "line": 374,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                    "line": 374,
                                                                    "char": 64
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 375,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 376,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 380,
                                                        "char": 30
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "mergedAttributes",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "string",
                                                                            "value": "checked",
                                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                            "line": 381,
                                                                            "char": 53
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "string",
                                                                        "value": "checked",
                                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                        "line": 381,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                    "line": 381,
                                                                    "char": 64
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 382,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 384,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "mergedAttributes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                    "line": 384,
                                                                    "char": 47
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                                "line": 384,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 384,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 385,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 386,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "mergedAttributes",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                            "line": 387,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                        "line": 387,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 387,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 388,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 389,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 391,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "mergedAttributes",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 391,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 392,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of prepared attributes for Phalcon\\Tag helpers\n     * according to the element parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 340,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 340,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 339,
                    "last-line": 396,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 397,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 397,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "attributes",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "attribute",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 399,
                                            "char": 39
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 399,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 399,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 401,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 401,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 402,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a default attribute for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 398,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 398,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 398,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 397,
                    "last-line": 406,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 407,
                            "char": 52
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
                                    "property": "attributes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 409,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 409,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 411,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 411,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 412,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets default attributes for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 408,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 408,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 408,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 407,
                    "last-line": 417,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefault",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 418,
                            "char": 41
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
                                    "property": "value",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 420,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 420,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 422,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 422,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 423,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a default value in case the form does not use an entity\n     * or there is no value available for the element in _POST\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 419,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 419,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 419,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 418,
                    "last-line": 429,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFilters",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 430,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "filters",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 432,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 432,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 432,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 432,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "filters",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 432,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 432,
                                                "char": 66
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 432,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 432,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 432,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 432,
                                    "char": 75
                                },
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 432,
                                "char": 75
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Wrong filter type added",
                                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                    "line": 433,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                                "line": 433,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 433,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 434,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 436,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "filters",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filters",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 436,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 436,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 438,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 438,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 439,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the element filters\n     *\n     * @param array|string filters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 431,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 431,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 431,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 430,
                    "last-line": 443,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setForm",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "form",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Form",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 444,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 444,
                            "char": 40
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
                                    "property": "form",
                                    "expr": {
                                        "type": "variable",
                                        "value": "form",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 446,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 446,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 448,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 448,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 449,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the parent form to the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 445,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 445,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 445,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 444,
                    "last-line": 453,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLabel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "label",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 454,
                            "char": 42
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
                                    "property": "label",
                                    "expr": {
                                        "type": "variable",
                                        "value": "label",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 456,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 456,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 458,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 458,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 459,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the element label\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 455,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 455,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 455,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 454,
                    "last-line": 463,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMessages",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "messages",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Messages",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 464,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 464,
                            "char": 52
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
                                    "property": "messages",
                                    "expr": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 466,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 466,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 468,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 468,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 469,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the validation messages related to the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 465,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 465,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 465,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 464,
                    "last-line": 473,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 474,
                            "char": 41
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
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 476,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 476,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 478,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 478,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 479,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the element name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 475,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 475,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 475,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 474,
                    "last-line": 483,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setUserOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 484,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 484,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "option",
                                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                                            "line": 486,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 486,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 486,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 488,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 488,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 489,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an option for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 485,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 485,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 485,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 484,
                    "last-line": 493,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setUserOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 494,
                            "char": 49
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
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                                        "line": 496,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 496,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 498,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 498,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Element.zep",
                            "line": 499,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets options for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                                    "line": 495,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Element.zep",
                                "line": 495,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Element.zep",
                        "line": 495,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Element.zep",
                    "line": 494,
                    "last-line": 500,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Forms\/Element.zep",
            "line": 23,
            "char": 14
        },
        "file": "\/app\/phalcon\/Forms\/Element.zep",
        "line": 23,
        "char": 14
    }
]