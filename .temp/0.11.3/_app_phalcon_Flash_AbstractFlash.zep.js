[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Flash",
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                "line": 15,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\EscaperInterface",
                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                "line": 16,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Flash\\Exception",
                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                "line": 17,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 27,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Shows HTML notifications related to different circumstances. Classes can be\n * stylized using CSS\n *\n *```php\n * $flash->success(\"The record was successfully deleted\");\n * $flash->error(\"Cannot open the file\");\n *```\n *",
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 28,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractFlash",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "FlashInterface",
                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                "line": 28,
                "char": 55
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                "line": 29,
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
                    "name": "autoescape",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 33,
                        "char": 32
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 37,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "automaticHtml",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 38,
                        "char": 35
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 42,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "cssClasses",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 43,
                        "char": 30
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 47,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "customTemplate",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 48,
                        "char": 32
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 50,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 50,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 52,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "escaperService",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 52,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 56,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "implicitFlush",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 57,
                        "char": 35
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 59,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messages",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 59,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 63,
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
                            "name": "cssClasses",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 64,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 64,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "cssClasses",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 66,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 66,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 66,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 66,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "cssClasses",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "error",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 68,
                                                            "char": 22
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "errorMessage",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 68,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 68,
                                                        "char": 38
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "notice",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 69,
                                                            "char": 23
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "noticeMessage",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 69,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 69,
                                                        "char": 39
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "success",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 70,
                                                            "char": 24
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "successMessage",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 70,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 70,
                                                        "char": 40
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "warning",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 71,
                                                            "char": 24
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "warningMessage",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 72,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 72,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 72,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 72,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 75,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "cssClasses",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cssClasses",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 75,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 75,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 76,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Flash constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 64,
                    "last-line": 80,
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
                                    "property": "messages",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 83,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 83,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Clears accumulated messages when implicit flush is disabled\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 82,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 81,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "error",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 93,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 95,
                                    "char": 21
                                },
                                "name": "message",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "error",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 95,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 95,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 95,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 95,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 95,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 96,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML error message\n     *\n     *```php\n     * $flash->error(\"This is an error\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 94,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 94,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 93,
                    "last-line": 100,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAutoescape",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 103,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "autoescape",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 103,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 103,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 104,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the autoescape mode in generated html\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 102,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 102,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 101,
                    "last-line": 108,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCustomTemplate",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 111,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "customTemplate",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 111,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 111,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 112,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the custom template set\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 110,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 110,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 109,
                    "last-line": 116,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "di",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 119,
                                    "char": 15
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 121,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "di",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 121,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 121,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 121,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 121,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 123,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "di",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 123,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 123,
                                    "char": 23
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 123,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 123,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "di",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Di",
                                                "dynamic": 0,
                                                "name": "getDefault",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 124,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 124,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 125,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 127,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "di",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 127,
                                "char": 18
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 128,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 118,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 118,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 118,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 117,
                    "last-line": 132,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEscaperService",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "escaper",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 135,
                                    "char": 20
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 135,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 137,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escaper",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 137,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "escaperService",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 137,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 137,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 137,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 139,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "escaper",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 139,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 139,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 139,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 139,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "container",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "DiInterface",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 140,
                                                    "char": 56
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 140,
                                                        "char": 48
                                                    },
                                                    "name": "getDI",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 140,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 140,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 140,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 142,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escaper",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "EscaperInterface",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 142,
                                                    "char": 75
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 142,
                                                        "char": 56
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "escaper",
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 142,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 142,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 142,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 142,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 142,
                                            "char": 75
                                        },
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "escaperService",
                                            "expr": {
                                                "type": "variable",
                                                "value": "escaper",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 143,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 143,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 144,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 146,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "escaper",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 146,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 147,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the Escaper Service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EscaperInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 134,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 133,
                    "last-line": 154,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notice",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 155,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 157,
                                    "char": 21
                                },
                                "name": "message",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "notice",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 157,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 157,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 157,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 157,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 157,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 158,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML notice\/information message\n     *\n     *```php\n     * $flash->notice(\"This is an information\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 156,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 156,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 155,
                    "last-line": 162,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAutoescape",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "autoescape",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 163,
                            "char": 50
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
                                    "property": "autoescape",
                                    "expr": {
                                        "type": "variable",
                                        "value": "autoescape",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 165,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 165,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 167,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 167,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 168,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the autoescape mode in generated html\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Flash",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 164,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 164,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 164,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 163,
                    "last-line": 172,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAutomaticHtml",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "automaticHtml",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 173,
                            "char": 56
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
                                    "property": "automaticHtml",
                                    "expr": {
                                        "type": "variable",
                                        "value": "automaticHtml",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 175,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 175,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 177,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 177,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 178,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set if the output must be implicitly formatted with HTML\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FlashInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 174,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 174,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 174,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 173,
                    "last-line": 182,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCssClasses",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cssClasses",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 183,
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
                                    "property": "cssClasses",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cssClasses",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 185,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 185,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 187,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 187,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 188,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set an array with CSS classes to format the messages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FlashInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 184,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 183,
                    "last-line": 192,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCustomTemplate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "customTemplate",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 193,
                            "char": 61
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
                                    "property": "customTemplate",
                                    "expr": {
                                        "type": "variable",
                                        "value": "customTemplate",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 195,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 195,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 197,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 197,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 198,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set an custom template for showing the messages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FlashInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 194,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 194,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 194,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 193,
                    "last-line": 202,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDI",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 203,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 203,
                            "char": 50
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
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 205,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 205,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 207,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 207,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 208,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FlashInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 204,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 204,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 204,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 203,
                    "last-line": 212,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEscaperService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "escaperService",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "EscaperInterface",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 213,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 213,
                            "char": 72
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
                                    "property": "escaperService",
                                    "expr": {
                                        "type": "variable",
                                        "value": "escaperService",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 215,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 215,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 217,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 217,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 218,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the Escaper Service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FlashInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 214,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 214,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 214,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 213,
                    "last-line": 223,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setImplicitFlush",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "implicitFlush",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 224,
                            "char": 56
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
                                    "property": "implicitFlush",
                                    "expr": {
                                        "type": "variable",
                                        "value": "implicitFlush",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 226,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 226,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 228,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 228,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 229,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set whether the output must be implicitly flushed to the output or\n     * returned as string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FlashInterface",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 225,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 225,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 225,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 224,
                    "last-line": 237,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "success",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 238,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 240,
                                    "char": 21
                                },
                                "name": "message",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "success",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 240,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 240,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 240,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 240,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 240,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 241,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML success message\n     *\n     *```php\n     * $flash->success(\"The process was finished successfully\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 239,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 239,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 238,
                    "last-line": 252,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "outputMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 253,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 253,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "implicitFlush",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 255,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 256,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 256,
                                    "char": 20
                                },
                                {
                                    "variable": "msg",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 256,
                                    "char": 25
                                },
                                {
                                    "variable": "htmlMessage",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 256,
                                    "char": 38
                                },
                                {
                                    "variable": "preparedMsg",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 256,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 258,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "implicitFlush",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 258,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "implicitFlush",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 258,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 258,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 258,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 258,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 260,
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
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 260,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 260,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 260,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 260,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "implicitFlush",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 264,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 264,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "content",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 265,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 265,
                                                    "char": 31
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 266,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 271,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 271,
                                        "char": 32
                                    },
                                    "value": "msg",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "preparedMsg",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 275,
                                                            "char": 40
                                                        },
                                                        "name": "prepareEscapedMessage",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "msg",
                                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                    "line": 275,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 275,
                                                                "char": 66
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 275,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 275,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 280,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "htmlMessage",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 280,
                                                            "char": 40
                                                        },
                                                        "name": "prepareHtmlMessage",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                    "line": 280,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 280,
                                                                "char": 64
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "preparedMsg",
                                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                    "line": 280,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 280,
                                                                "char": 77
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 280,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 280,
                                                    "char": 78
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 282,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "implicitFlush",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 282,
                                                "char": 34
                                            },
                                            "statements": [
                                                {
                                                    "type": "echo",
                                                    "expressions": [
                                                        {
                                                            "type": "variable",
                                                            "value": "htmlMessage",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 283,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 284,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "content",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "htmlMessage",
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 285,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 285,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 286,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-append",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "messages",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "htmlMessage",
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 286,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 286,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 287,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 288,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 294,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "implicitFlush",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 294,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 294,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "content",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 295,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 296,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 297,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "preparedMsg",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 301,
                                                    "char": 36
                                                },
                                                "name": "prepareEscapedMessage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 301,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 301,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 301,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 301,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 306,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "htmlMessage",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 306,
                                                    "char": 36
                                                },
                                                "name": "prepareHtmlMessage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "type",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 306,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 306,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "preparedMsg",
                                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                            "line": 306,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 306,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 306,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 306,
                                            "char": 74
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 312,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "implicitFlush",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 312,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "echo",
                                            "expressions": [
                                                {
                                                    "type": "variable",
                                                    "value": "htmlMessage",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 313,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 314,
                                            "char": 13
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
                                                    "property": "messages",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "htmlMessage",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 315,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 315,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 317,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "htmlMessage",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 317,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 318,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 319,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 320,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Outputs a message formatting it with HTML\n     *\n     *```php\n     * $flash->outputMessage(\"error\", $message);\n     *```\n     *\n     * @param string|array message\n     * @return string|void\n     *",
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 253,
                    "last-line": 328,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "warning",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 329,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 331,
                                    "char": 21
                                },
                                "name": "message",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "warning",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 331,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 331,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 331,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 331,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 331,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 332,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Shows a HTML warning message\n     *\n     *```php\n     * $flash->warning(\"Hey, this is important\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 330,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 330,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 329,
                    "last-line": 335,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getTemplate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cssClassses",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 335,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 337,
                                    "char": 15
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 337,
                                        "char": 22
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "customTemplate",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 337,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 337,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 337,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "string",
                                            "value": "",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 338,
                                            "char": 19
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cssClassses",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 338,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 338,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "<div>%message%<\/div>",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 339,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 339,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 339,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 340,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "<div class=\\\"%cssClass%\\\">%message%<\/div>",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 341,
                                                    "char": 66
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 341,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 341,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 342,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 343,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 345,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 345,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "customTemplate",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 345,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 345,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 346,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 336,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 336,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 335,
                    "last-line": 351,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "prepareEscapedMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 352,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "autoEscape",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 354,
                                    "char": 23
                                },
                                {
                                    "variable": "escaper",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 354,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 356,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "autoEscape",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 356,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "autoescape",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 356,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 356,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 356,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 356,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 358,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "autoEscape",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 358,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 358,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 359,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 360,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 362,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escaper",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 362,
                                            "char": 28
                                        },
                                        "name": "getEscaperService",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 362,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 362,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 364,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "escaper",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 364,
                                    "char": 24
                                },
                                "name": "escapeHtml",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 364,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 364,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 364,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 365,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the message escaped if the autoEscape is true, otherwise the\n     * original message is returned\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 353,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 353,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 352,
                    "last-line": 370,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "prepareHtmlMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 371,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 371,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "classes",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 373,
                                    "char": 20
                                },
                                {
                                    "variable": "cssClasses",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 373,
                                    "char": 32
                                },
                                {
                                    "variable": "typeClasses",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 373,
                                    "char": 45
                                },
                                {
                                    "variable": "automaticHtml",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 373,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 375,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "automaticHtml",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 375,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "automaticHtml",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 375,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 375,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 375,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 375,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 377,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "automaticHtml",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 377,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 377,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 378,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 379,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 381,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "classes",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 381,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cssClasses",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 381,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 381,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 381,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 383,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "typeClasses",
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 383,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "classes",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 383,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 383,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 383,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 383,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "typeClasses",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 384,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 384,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 384,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 384,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "cssClasses",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "join",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": " ",
                                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                    "line": 385,
                                                                    "char": 40
                                                                },
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 385,
                                                                "char": 40
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "typeClasses",
                                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                    "line": 385,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                                "line": 385,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 385,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 385,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 386,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "cssClasses",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "typeClasses",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 387,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 387,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 388,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 389,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "cssClasses",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 390,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 390,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                    "line": 391,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 393,
                            "char": 14
                        },
                        {
                            "type": "return",
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
                                                        "value": "%cssClass%",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 395,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 395,
                                                    "char": 27
                                                },
                                                {
                                                    "value": {
                                                        "type": "string",
                                                        "value": "%message%",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 397,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 397,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 397,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 397,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "cssClasses",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 399,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 399,
                                                    "char": 27
                                                },
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "message",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 401,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 401,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 401,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 401,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                "line": 402,
                                                "char": 18
                                            },
                                            "name": "getTemplate",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "cssClasses",
                                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                        "line": 402,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                                    "line": 402,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                            "line": 403,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                        "line": 403,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 403,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                            "line": 404,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepares the HTML output for the message. If automaticHtml is not set\n     * then the original message is returned\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                                "line": 372,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                        "line": 372,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
                    "line": 371,
                    "last-line": 405,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
            "line": 28,
            "char": 14
        },
        "file": "\/app\/phalcon\/Flash\/AbstractFlash.zep",
        "line": 28,
        "char": 14
    }
]