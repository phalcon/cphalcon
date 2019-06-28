[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\View",
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 15,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 16,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Str",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 17,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Exception",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 18,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ViewBaseInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 19,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Engine\\EngineInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 20,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Engine\\Php",
                "alias": "PhpEngine",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 21,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 49,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\View\\Simple\n *\n * This component allows to render views without hierarchical levels\n *\n *```php\n * use Phalcon\\Mvc\\View\\Simple as View;\n *\n * $view = new View();\n *\n * \/\/ Render a view\n * echo $view->render(\n *     \"templates\/my-view\",\n *     [\n *         \"some\" => $param,\n *     ]\n * );\n *\n * \/\/ Or with filename with extension\n * echo $view->render(\n *     \"templates\/my-view.volt\",\n *     [\n *         \"parameter\" => $here,\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 50,
        "char": 5
    },
    {
        "type": "class",
        "name": "Simple",
        "abstract": 0,
        "final": 0,
        "extends": "Injectable",
        "implements": [
            {
                "type": "variable",
                "value": "ViewBaseInterface",
                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                "line": 51,
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
                    "name": "activeRenderPath",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 53,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "content",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 57,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "engines",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 58,
                        "char": 30
                    },
                    "docblock": "**\n     * @var \\Phalcon\\Mvc\\View\\EngineInterface[]|false\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 60,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 61,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "partialsDir",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 65,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "registeredEngines",
                    "docblock": "**\n     * @var array|null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 66,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 68,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "viewsDir",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 70,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "viewParams",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 70,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 74,
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
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 75,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 75,
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
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 77,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 77,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 78,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\View\\Simple constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 75,
                    "last-line": 86,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 87,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 89,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 91,
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
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 91,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 91,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "viewParams",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 91,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 91,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 91,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 91,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 91,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 91,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 92,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 95,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 95,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 96,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic method to retrieve a variable passed to the view\n     *\n     *```php\n     * echo $this->view->products;\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 87,
                                "char": 47
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 88,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 88,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 87,
                    "last-line": 104,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 105,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 105,
                            "char": 49
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
                                    "property": "viewParams",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 107,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 107,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 107,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 108,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic method to pass variables to the views\n     *\n     *```php\n     * $this->view->products = $products;\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 105,
                    "last-line": 112,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveRenderPath",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 115,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "activeRenderPath",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 115,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 115,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 116,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the path of the view that is currently rendered\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 114,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 114,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 113,
                    "last-line": 120,
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
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 123,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "content",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 123,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 123,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 124,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns output from another view stage\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 122,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 122,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 121,
                    "last-line": 128,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getParamsToView",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 131,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "viewParams",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 131,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 131,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 132,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns parameters to views\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 130,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 130,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 129,
                    "last-line": 136,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getVar",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 137,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 139,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 141,
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
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 141,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 141,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "viewParams",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 141,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 141,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 141,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 141,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 141,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 141,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 142,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 143,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 145,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 145,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 146,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a parameter previously set in the view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 137,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 138,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 138,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 137,
                    "last-line": 150,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getViewsDir",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 153,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "viewsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 153,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 153,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 154,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets views directory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 152,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 152,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 151,
                    "last-line": 173,
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
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 174,
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
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 174,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 174,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "viewParams",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 176,
                                    "char": 23
                                },
                                {
                                    "variable": "mergedParams",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 176,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 181,
                            "char": 16
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 181,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 187,
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
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 187,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 187,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 187,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 187,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "viewParams",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 188,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "viewParams",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 188,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 188,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 188,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 193,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "mergedParams",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "viewParams",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 193,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 193,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 193,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 193,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 193,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 193,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 198,
                                    "char": 31
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "create_symbol_table",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 198,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 199,
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
                                            "variable": "mergedParams",
                                            "expr": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 200,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 200,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 201,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 206,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 206,
                                    "char": 14
                                },
                                "name": "internalRender",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "partialPath",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 206,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 206,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "mergedParams",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 206,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 206,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 206,
                                "char": 56
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 211,
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
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 211,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 211,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 211,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 211,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "viewParams",
                                            "expr": {
                                                "type": "variable",
                                                "value": "viewParams",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 215,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 215,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 216,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 218,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_end_clean",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 218,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 223,
                            "char": 12
                        },
                        {
                            "type": "echo",
                            "expressions": [
                                {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 223,
                                        "char": 19
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "content",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 223,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 223,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 224,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a partial view\n     *\n     * ```php\n     * \/\/ Show a partial inside another view\n     * $this->partial(\"shared\/footer\");\n     * ```\n     *\n     * ```php\n     * \/\/ Show a partial inside another view with parameters\n     * $this->partial(\n     *     \"shared\/footer\",\n     *     [\n     *         \"content\" => $html,\n     *     ]\n     * );\n     * ```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 174,
                    "last-line": 238,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerEngines",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "engines",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 239,
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
                                    "property": "registeredEngines",
                                    "expr": {
                                        "type": "variable",
                                        "value": "engines",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 241,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 241,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 242,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Register templating engines\n     *\n     *```php\n     * $this->view->registerEngines(\n     *     [\n     *         \".phtml\" => \\Phalcon\\Mvc\\View\\Engine\\Php::class,\n     *         \".volt\"  => \\Phalcon\\Mvc\\View\\Engine\\Volt::class,\n     *         \".mhtml\" => \\MyCustomEngine::class,\n     *     ]\n     * );\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 239,
                    "last-line": 246,
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
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 247,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 247,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 247,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "mergedParams",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 249,
                                    "char": 25
                                },
                                {
                                    "variable": "viewParams",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 249,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 254,
                            "char": 27
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "create_symbol_table",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 254,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 256,
                            "char": 16
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 256,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 258,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "viewParams",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 258,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "viewParams",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 258,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 258,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 258,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 263,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mergedParams",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "viewParams",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 263,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 263,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 263,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 263,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 263,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 263,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 268,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 268,
                                    "char": 14
                                },
                                "name": "internalRender",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 268,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 268,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "mergedParams",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 268,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 268,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 268,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 270,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_end_clean",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 270,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 272,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 272,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "content",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 272,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 272,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 273,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 248,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 248,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 247,
                    "last-line": 281,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setContent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 282,
                            "char": 47
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
                                    "property": "content",
                                    "expr": {
                                        "type": "variable",
                                        "value": "content",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 284,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 284,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 286,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 286,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 287,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Externally sets the view content\n     *\n     *```php\n     * $this->view->setContent(\"<h1>hello<\/h1>\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Simple",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 283,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 283,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 283,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 282,
                    "last-line": 295,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setParamToView",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 296,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 296,
                            "char": 58
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
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 298,
                                    "char": 21
                                },
                                "name": "setVar",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 298,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 298,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 298,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 298,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 298,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 299,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds parameters to views (alias of setVar)\n     *\n     *```php\n     * $this->view->setParamToView(\"products\", $products);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Simple",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 297,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 297,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 297,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 296,
                    "last-line": 307,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setVar",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 308,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 308,
                            "char": 50
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
                                    "property": "viewParams",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 310,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 310,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 310,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 312,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 312,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 313,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set a single view parameter\n     *\n     *```php\n     * $this->view->setVar(\"products\", $products);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Simple",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 309,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 309,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 309,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 308,
                    "last-line": 325,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setVars",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 326,
                            "char": 42
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
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 326,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 326,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 328,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
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
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 329,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "viewParams",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 329,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 329,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 329,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 329,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 329,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 329,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 329,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 330,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 332,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "viewParams",
                                    "expr": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 332,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 332,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 334,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 334,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 335,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set all the render params\n     *\n     *```php\n     * $this->view->setVars(\n     *     [\n     *         \"products\" => $products,\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Simple",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 327,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 327,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 327,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 326,
                    "last-line": 339,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setViewsDir",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "viewsDir",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 340,
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
                                    "property": "viewsDir",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Str",
                                        "dynamic": 0,
                                        "name": "dirSeparator",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "viewsDir",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 342,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 342,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 342,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 342,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 343,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets views directory\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 340,
                    "last-line": 348,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "loadTemplateEngines",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "engines",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 351,
                                    "char": 20
                                },
                                {
                                    "variable": "di",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 351,
                                    "char": 24
                                },
                                {
                                    "variable": "registeredEngines",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 351,
                                    "char": 43
                                },
                                {
                                    "variable": "extension",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 351,
                                    "char": 54
                                },
                                {
                                    "variable": "engineService",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 351,
                                    "char": 69
                                },
                                {
                                    "variable": "engineObject",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 352,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 357,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "engines",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 357,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "engines",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 357,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 357,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 357,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 359,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "engines",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 359,
                                    "char": 22
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 359,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 359,
                                "char": 30
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 360,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 360,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 360,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 360,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 362,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "engines",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 362,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 362,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 364,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "registeredEngines",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 364,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "registeredEngines",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 364,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 364,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 364,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 366,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "registeredEngines",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 366,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 366,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 366,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 366,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "engines",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": ".phtml",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 371,
                                                            "char": 35
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "PhpEngine",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 371,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 371,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "di",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 371,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 371,
                                                                "char": 61
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 371,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 371,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 372,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "di",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 373,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 373,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 373,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 373,
                                                "char": 40
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
                                                                    "type": "scall",
                                                                    "dynamic-class": 0,
                                                                    "class": "Exception",
                                                                    "dynamic": 0,
                                                                    "name": "containerServiceNotFound",
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "the application services",
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 377,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                            "line": 377,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 378,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 378,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 378,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 379,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 381,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "registeredEngines",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 381,
                                                "char": 67
                                            },
                                            "key": "extension",
                                            "value": "engineService",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "engineService",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 382,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 382,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 382,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 382,
                                                        "char": 55
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "instanceof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "engineService",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 386,
                                                                    "char": 51
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "Closure",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 386,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 386,
                                                                "char": 61
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "engineService",
                                                                            "expr": {
                                                                                "type": "scall",
                                                                                "dynamic-class": 0,
                                                                                "class": "Closure",
                                                                                "dynamic": 0,
                                                                                "name": "bind",
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "engineService",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                            "line": 387,
                                                                                            "char": 76
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                        "line": 387,
                                                                                        "char": 76
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "di",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                            "line": 387,
                                                                                            "char": 80
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                        "line": 387,
                                                                                        "char": 80
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 387,
                                                                                "char": 81
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                            "line": 387,
                                                                            "char": 81
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 389,
                                                                    "char": 31
                                                                },
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "engineObject",
                                                                            "expr": {
                                                                                "type": "fcall",
                                                                                "name": "call_user_func",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "engineService",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                            "line": 389,
                                                                                            "char": 76
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                        "line": 389,
                                                                                        "char": 76
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "this",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                            "line": 389,
                                                                                            "char": 82
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                        "line": 389,
                                                                                        "char": 82
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 389,
                                                                                "char": 83
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                            "line": 389,
                                                                            "char": 83
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 390,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "engineObject",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "engineService",
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 391,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                            "line": 391,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 392,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 393,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "elseif_statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "typeof",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "engineService",
                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                        "line": 393,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 393,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "string",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 393,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 393,
                                                                "char": 61
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "engineObject",
                                                                            "expr": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "di",
                                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                    "line": 397,
                                                                                    "char": 47
                                                                                },
                                                                                "name": "getShared",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "engineService",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                            "line": 398,
                                                                                            "char": 42
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                        "line": 398,
                                                                                        "char": 42
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "array",
                                                                                            "left": [
                                                                                                {
                                                                                                    "value": {
                                                                                                        "type": "variable",
                                                                                                        "value": "this",
                                                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                                        "line": 401,
                                                                                                        "char": 29
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                                    "line": 401,
                                                                                                    "char": 29
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                            "line": 402,
                                                                                            "char": 25
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                        "line": 402,
                                                                                        "char": 25
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 402,
                                                                                "char": 26
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                            "line": 402,
                                                                            "char": 26
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 403,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 403,
                                                            "char": 26
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "throw",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "Exception",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "Invalid template engine registration for extension: ",
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 405,
                                                                                "char": 82
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "extension",
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 406,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                            "line": 406,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                        "line": 406,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 406,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 407,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 409,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "engines",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "extension",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 409,
                                                                    "char": 42
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "engineObject",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 409,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 409,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 410,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 411,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 413,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "engines",
                                            "expr": {
                                                "type": "variable",
                                                "value": "engines",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 413,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 413,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 414,
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
                                            "variable": "engines",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 415,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "engines",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 415,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 415,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 415,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 416,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 418,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "engines",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 418,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 419,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Loads registered template engines, if none are registered it will use\n     * Phalcon\\Mvc\\View\\Engine\\Php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 350,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                        "line": 350,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 349,
                    "last-line": 425,
                    "char": 22
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "internalRender",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 426,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 426,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 428,
                                    "char": 26
                                },
                                {
                                    "variable": "engines",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 428,
                                    "char": 35
                                },
                                {
                                    "variable": "extension",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 428,
                                    "char": 46
                                },
                                {
                                    "variable": "engine",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 428,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 429,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "notExists",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 429,
                                    "char": 23
                                },
                                {
                                    "variable": "mustClean",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 429,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 430,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "viewEnginePath",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 430,
                                    "char": 30
                                },
                                {
                                    "variable": "viewsDirPath",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 430,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 432,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 432,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 432,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 432,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 432,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 434,
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
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 434,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 434,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 434,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 434,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeRenderPath",
                                            "expr": {
                                                "type": "variable",
                                                "value": "path",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 435,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 435,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 436,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 441,
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
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 441,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 441,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 441,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 441,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 442,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "view:beforeRender",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 442,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 442,
                                                    "char": 53
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 442,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 442,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 442,
                                            "char": 63
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 442,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 442,
                                        "char": 71
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 443,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 444,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 445,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 447,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "notExists",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 447,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 447,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mustClean",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 448,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 448,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 450,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "viewsDirPath",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 450,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "viewsDir",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 450,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 450,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 450,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 450,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 450,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 455,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "engines",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 455,
                                            "char": 28
                                        },
                                        "name": "loadTemplateEngines",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 455,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 455,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 460,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "engines",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 460,
                                "char": 42
                            },
                            "key": "extension",
                            "value": "engine",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "file_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "viewsDirPath",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 461,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "extension",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 461,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 461,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 461,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 461,
                                        "char": 54
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "viewEnginePath",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "viewsDirPath",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 462,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "extension",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 462,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 462,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 462,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 463,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "substr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "viewsDirPath",
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 463,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 463,
                                                                "char": 41
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "minus",
                                                                    "left": {
                                                                        "type": "fcall",
                                                                        "name": "strlen",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "extension",
                                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                    "line": 463,
                                                                                    "char": 60
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                                "line": 463,
                                                                                "char": 60
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                        "line": 463,
                                                                        "char": 61
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                    "line": 463,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 463,
                                                                "char": 61
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 463,
                                                        "char": 64
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "extension",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 463,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 463,
                                                    "char": 77
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "file_exists",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "viewsDirPath",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 463,
                                                                "char": 103
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 463,
                                                            "char": 103
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 463,
                                                    "char": 105
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 463,
                                                "char": 105
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "viewEnginePath",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "viewsDirPath",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 468,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 468,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 469,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 469,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 471,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 476,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 476,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 476,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 476,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 476,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "eventsManager",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 477,
                                                        "char": 34
                                                    },
                                                    "name": "fire",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "view:beforeRenderView",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 477,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 477,
                                                            "char": 61
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 477,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 477,
                                                            "char": 67
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "viewEnginePath",
                                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                                "line": 477,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 477,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 477,
                                                    "char": 87
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 477,
                                                    "char": 95
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 477,
                                                "char": 95
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 479,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 480,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 482,
                                    "char": 18
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "engine",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 482,
                                            "char": 20
                                        },
                                        "name": "render",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "viewEnginePath",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 482,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 482,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 482,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 482,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "mustClean",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 482,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 482,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 482,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 484,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "notExists",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 484,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 484,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 489,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 489,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 489,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 489,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 489,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 490,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "view:afterRenderView",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 490,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 490,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 490,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 490,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 490,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 491,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 493,
                                    "char": 17
                                },
                                {
                                    "type": "break",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 494,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 499,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "notExists",
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 499,
                                "char": 22
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "View '",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 501,
                                                            "char": 24
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "viewsDirPath",
                                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                            "line": 501,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 501,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' was not found in the views directory",
                                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                        "line": 502,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 502,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 502,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 502,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 503,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 508,
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
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 508,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 508,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 508,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                "line": 508,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                            "line": 509,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "view:afterRender",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 509,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 509,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                    "line": 509,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                                "line": 509,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                        "line": 509,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                                    "line": 510,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                            "line": 511,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Tries to render the view with every engine registered in the component\n     *\n     * @param array  params\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
                    "line": 426,
                    "last-line": 512,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
            "line": 50,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/View\/Simple.zep",
        "line": 50,
        "char": 5
    }
]