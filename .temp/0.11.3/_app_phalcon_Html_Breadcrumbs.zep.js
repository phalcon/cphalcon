[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html",
        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Breadcrumbs\n *\n * This component offers an easy way to create breadcrumbs for your application.\n * The resulting HTML when calling `render()` will have each breadcrumb enclosed\n * in `<dt>` tags, while the whole string is enclosed in `<dl>` tags.\n *",
        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
        "line": 22,
        "char": 5
    },
    {
        "type": "class",
        "name": "Breadcrumbs",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "elements",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 29,
                        "char": 26
                    },
                    "docblock": "**\n     * Keeps all the breadcrumbs\n     *\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "separator",
                    "default": {
                        "type": "string",
                        "value": " \/ ",
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 36,
                        "char": 29
                    },
                    "docblock": "**\n     * Crumb separator\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 36,
                            "char": 34
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 36,
                            "char": 40
                        }
                    ],
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 42,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "template",
                    "default": {
                        "type": "string",
                        "value": "<dt><a href=\\\"%link%\\\">%label%<\/a><\/dt>",
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 43,
                        "char": 63
                    },
                    "docblock": "**\n     * The HTML template to use to render the breadcrumbs.\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 55,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "add",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "label",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 56,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "link",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 56,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 56,
                            "char": 53
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
                                    "property": "elements",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "link",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 58,
                                            "char": 32
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "label",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 58,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 58,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 60,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 60,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a new crumb.\n     *\n     * ```php\n     * \/\/ Adding a crumb with a link\n     * $breadcrumbs->add(\"Home\", \"\/\");\n     *\n     * \/\/ Adding a crumb without a link (normally the last one)\n     * $breadcrumbs->add(\"Users\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Breadcrumbs",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 57,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 57,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 56,
                    "last-line": 69,
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
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "elements",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 72,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 72,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Clears the crumbs\n     *\n     * ```php\n     * $breadcrumbs->clear()\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 70,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "remove",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "link",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 85,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "elements",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 87,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 89,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "elements",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 89,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 89,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 89,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 89,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 91,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "elements",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 91,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "link",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 91,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 91,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 91,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 93,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "elements",
                                    "expr": {
                                        "type": "variable",
                                        "value": "elements",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 93,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 93,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 94,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes crumb by url.\n     *\n     * ```php\n     * $breadcrumbs->remove(\"\/admin\/user\/create\");\n     *\n     * \/\/ remove a crumb without an url (last link)\n     * $breadcrumbs->remove();\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 86,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 85,
                    "last-line": 102,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 20
                                },
                                {
                                    "variable": "elements",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 30
                                },
                                {
                                    "variable": "lastLabel",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 41
                                },
                                {
                                    "variable": "lastUrl",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 50
                                },
                                {
                                    "variable": "output",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 58
                                },
                                {
                                    "variable": "template",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 68
                                },
                                {
                                    "variable": "url",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 73
                                },
                                {
                                    "variable": "urls",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 105,
                                    "char": 79
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 107,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "output",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 107,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 107,
                                    "char": 27
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "elements",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 108,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 108,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 108,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 108,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "template",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 109,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "template",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 109,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 109,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 109,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "urls",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_keys",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "elements",
                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                    "line": 110,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 110,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 110,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 110,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "lastUrl",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "end",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "urls",
                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                    "line": 111,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 111,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 111,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 111,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "lastLabel",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 112,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "lastUrl",
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 112,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 112,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 112,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 114,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "elements",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 114,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "lastUrl",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 114,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 114,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 114,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 116,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "elements",
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 116,
                                "char": 38
                            },
                            "key": "url",
                            "value": "element",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "str_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "string",
                                                                        "value": "%label%",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 119,
                                                                        "char": 28
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 119,
                                                                    "char": 28
                                                                },
                                                                {
                                                                    "value": {
                                                                        "type": "string",
                                                                        "value": "%link%",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 121,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 121,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 121,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 121,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "element",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 123,
                                                                        "char": 28
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 123,
                                                                    "char": 28
                                                                },
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "url",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 125,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 125,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 125,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 125,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "template",
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 127,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 127,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 127,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 127,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 128,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 133,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 133,
                                    "char": 16
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "elements",
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 133,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 133,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 133,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 133,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "<dt>",
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 134,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "lastLabel",
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 134,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                    "line": 134,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "<\/dt>",
                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                    "line": 134,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 134,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 134,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 135,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "str_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "string",
                                                                        "value": "%label%",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 138,
                                                                        "char": 28
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 138,
                                                                    "char": 28
                                                                },
                                                                {
                                                                    "value": {
                                                                        "type": "string",
                                                                        "value": "%link%",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 140,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 140,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 140,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 140,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "lastLabel",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 142,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 142,
                                                                    "char": 30
                                                                },
                                                                {
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "lastUrl",
                                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                        "line": 144,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                    "line": 144,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 144,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 144,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "template",
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 146,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 146,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 146,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                            "line": 146,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 147,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 149,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "<dl>",
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 149,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "implode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<dt>",
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 149,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                "line": 149,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "separator",
                                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                                "line": 149,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                            "line": 149,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 149,
                                                        "char": 54
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "<\/dt>",
                                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                        "line": 149,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                    "line": 149,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 149,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "output",
                                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                    "line": 149,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                                "line": 149,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                        "line": 149,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 149,
                                    "char": 71
                                },
                                "right": {
                                    "type": "string",
                                    "value": "<\/dl>",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 149,
                                    "char": 78
                                },
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 149,
                                "char": 78
                            },
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 150,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders and outputs breadcrumbs based on previously set template.\n     *\n     * ```php\n     * echo $breadcrumbs->render();\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 104,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 104,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 103,
                    "last-line": 154,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 157,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "elements",
                                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                    "line": 157,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 157,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                            "line": 158,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal breadcrumbs array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                                "line": 156,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                        "line": 156,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
                    "line": 155,
                    "last-line": 159,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
            "line": 22,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/Breadcrumbs.zep",
        "line": 22,
        "char": 5
    }
]