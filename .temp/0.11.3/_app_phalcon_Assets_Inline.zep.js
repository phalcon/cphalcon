[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Assets\/Inline.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Assets",
        "file": "\/app\/phalcon\/Assets\/Inline.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents an inline asset\n *\n *```php\n * $inline = new \\Phalcon\\Assets\\Inline(\"js\", \"alert('hello world');\");\n *```\n *",
        "file": "\/app\/phalcon\/Assets\/Inline.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Inline",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "AssetInterface",
                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                "line": 21,
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
                    "docblock": "**\n     * @var array | null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 25,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 29,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "content",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 30,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "filter",
                    "docblock": "**\n     * @var bool\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 35,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 40,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 44,
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
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 45,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 45,
                            "char": 60
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
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 45,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 45,
                            "char": 80
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 45,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 45,
                            "char": 103
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
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 47,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 47,
                                    "char": 30
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "content",
                                    "expr": {
                                        "type": "variable",
                                        "value": "content",
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 48,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 48,
                                    "char": 36
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "filter",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filter",
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 49,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 49,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "attributes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 50,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 50,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 51,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Assets\\Inline constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                        "line": 46,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 45,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAssetKey",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 58,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 60,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                                    "line": 60,
                                                    "char": 24
                                                },
                                                "name": "getType",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                                "line": 60,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": ":",
                                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                                "line": 60,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                            "line": 60,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                                "line": 60,
                                                "char": 46
                                            },
                                            "name": "getContent",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                            "line": 60,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 60,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 60,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 62,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "md5",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                            "line": 62,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 62,
                                        "char": 23
                                    }
                                ],
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 62,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 63,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the asset's key.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 57,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 56,
                    "last-line": 67,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 68,
                            "char": 51
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
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 70,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 70,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 72,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 72,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets extra HTML attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AssetInterface",
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 69,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 69,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                        "line": 69,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 68,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFilter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filter",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 78,
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
                                    "property": "filter",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filter",
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 80,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 80,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 82,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 82,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the asset must be filtered or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AssetInterface",
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 79,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 78,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 88,
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
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                        "line": 90,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 90,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 92,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 92,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Assets\/Inline.zep",
                            "line": 93,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the inline's type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AssetInterface",
                                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                    "line": 89,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Assets\/Inline.zep",
                                "line": 89,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Inline.zep",
                        "line": 89,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Inline.zep",
                    "line": 88,
                    "last-line": 94,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Assets\/Inline.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Assets\/Inline.zep",
        "line": 20,
        "char": 5
    }
]