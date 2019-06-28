[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 15,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 16,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 17,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Str",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 18,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Exception",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 19,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ViewInterface",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 20,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\View\\Engine\\Php",
                "alias": "PhpEngine",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 21,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 48,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\View\n *\n * Phalcon\\Mvc\\View is a class for working with the \"view\" portion of the\n * model-view-controller pattern. That is, it exists to help keep the view\n * script separate from the model and controller scripts. It provides a system\n * of helpers, output filters, and variable escaping.\n *\n * ```php\n * use Phalcon\\Mvc\\View;\n *\n * $view = new View();\n *\n * \/\/ Setting views directory\n * $view->setViewsDir(\"app\/views\/\");\n *\n * $view->start();\n *\n * \/\/ Shows recent posts view (app\/views\/posts\/recent.phtml)\n * $view->render(\"posts\", \"recent\");\n * $view->finish();\n *\n * \/\/ Printing views output\n * echo $view->getContent();\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 49,
        "char": 5
    },
    {
        "type": "class",
        "name": "View",
        "abstract": 0,
        "final": 0,
        "extends": "Injectable",
        "implements": [
            {
                "type": "variable",
                "value": "ViewInterface",
                "file": "\/app\/phalcon\/Mvc\/View.zep",
                "line": 50,
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
                    "name": "actionName",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 82,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeRenderPaths",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 83,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "basePath",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 83,
                        "char": 26
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 84,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "content",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 84,
                        "char": 25
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 85,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "controllerName",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 86,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "currentRenderLevel",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 86,
                        "char": 38
                    },
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 86,
                            "char": 44
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 87,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "disabled",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 87,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 88,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "disabledLevels",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 89,
                    "char": 13
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
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 89,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 90,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "layout",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 91,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "layoutsDir",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 91,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 92,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "mainView",
                    "default": {
                        "type": "string",
                        "value": "index",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 92,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 93,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 93,
                        "char": 27
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 94,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "params",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 95,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "pickView",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 96,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "partialsDir",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 96,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 97,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "registeredEngines",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 97,
                        "char": 38
                    },
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 97,
                            "char": 44
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 98,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "renderLevel",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 98,
                        "char": 31
                    },
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 98,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 99,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "templatesAfter",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 99,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 100,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "templatesBefore",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 100,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 101,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "viewsDirs",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 101,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 102,
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
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 102,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 106,
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
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 107,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 107,
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
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 109,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 109,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 110,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\View constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 107,
                    "last-line": 118,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 119,
                            "char": 38
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
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 121,
                                    "char": 21
                                },
                                "name": "getVar",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 121,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 121,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 121,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 122,
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
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 119,
                                "char": 47
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 120,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 120,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 119,
                    "last-line": 130,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__isset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 131,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 133,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "viewParams",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 133,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 133,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 133,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 133,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 133,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 134,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic method to retrieve if a variable is set in the view\n     *\n     *```php\n     * echo isset($this->view->products);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 132,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 132,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 131,
                    "last-line": 142,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 143,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 143,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 145,
                                    "char": 14
                                },
                                "name": "setVar",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 145,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 145,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 145,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 145,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 145,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 146,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic method to pass variables to the views\n     *\n     *```php\n     * $this->view->products = $products;\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 143,
                    "last-line": 150,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "cleanTemplateAfter",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "templatesAfter",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 153,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 153,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 155,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 155,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 156,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets any template before layouts\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 152,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 152,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 152,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 151,
                    "last-line": 160,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "cleanTemplateBefore",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "templatesBefore",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 163,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 163,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 165,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 165,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 166,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets any \"template before\" layouts\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 162,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 162,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 162,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 161,
                    "last-line": 177,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "disableLevel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "level",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 178,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "level",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 180,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 180,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 180,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 180,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "disabledLevels",
                                            "expr": {
                                                "type": "variable",
                                                "value": "level",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 181,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 181,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 182,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "disabledLevels",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "level",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 183,
                                                    "char": 43
                                                }
                                            ],
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 183,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 183,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 184,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 186,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 186,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 187,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Disables a specific level of rendering\n     *\n     *```php\n     * \/\/ Render all levels except ACTION level\n     * $this->view->disableLevel(\n     *     View::LEVEL_ACTION_VIEW\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ViewInterface",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 179,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 179,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 179,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 178,
                    "last-line": 191,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "disable",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "disabled",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 194,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 194,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 196,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 196,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 197,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Disables the auto-rendering process\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 193,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 193,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 193,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 192,
                    "last-line": 201,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "enable",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "disabled",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 204,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 204,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 206,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 206,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 207,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Enables the auto-rendering process\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 203,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 203,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 203,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 202,
                    "last-line": 211,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "exists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "view",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 212,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "basePath",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 214,
                                    "char": 21
                                },
                                {
                                    "variable": "viewsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 214,
                                    "char": 31
                                },
                                {
                                    "variable": "engines",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 214,
                                    "char": 40
                                },
                                {
                                    "variable": "extension",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 214,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 216,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "basePath",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 216,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "basePath",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 216,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 216,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 216,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "engines",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 217,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "registeredEngines",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 217,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 217,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 217,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 219,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "engines",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 219,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 219,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "engines",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": ".phtml",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 221,
                                                            "char": 23
                                                        },
                                                        "value": {
                                                            "type": "string",
                                                            "value": "Phalcon\\\\Mvc\\\\View\\\\Engine\\\\Php",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 222,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 222,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 222,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 222,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 224,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 224,
                                            "char": 18
                                        },
                                        "name": "registerEngines",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "engines",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 224,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 224,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 224,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 225,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 227,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 227,
                                    "char": 30
                                },
                                "name": "getViewsDirs",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 227,
                                "char": 46
                            },
                            "value": "viewsDir",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "engines",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 228,
                                        "char": 41
                                    },
                                    "key": "extension",
                                    "value": "_",
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
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "basePath",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 229,
                                                                        "char": 41
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "viewsDir",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 229,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 229,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "view",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 229,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 229,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "extension",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 229,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 229,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 229,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 229,
                                                "char": 72
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 230,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 231,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 232,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 233,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 235,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 235,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 236,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether view exists\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 213,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 213,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 212,
                    "last-line": 240,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "finish",
                    "statements": [
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_end_clean",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 243,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 245,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 245,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 246,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Finishes the render process by stopping the output buffering\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 242,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 242,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 242,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 241,
                    "last-line": 250,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActionName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 253,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "actionName",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 253,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 253,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 254,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the name of the action rendered\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 252,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 252,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 251,
                    "last-line": 258,
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
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "activeRenderPath",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 261,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 262,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "viewsDirsCount",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 262,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 264,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "viewsDirsCount",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 264,
                                                        "char": 41
                                                    },
                                                    "name": "getViewsDirs",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 264,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 264,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 264,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 264,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "activeRenderPath",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 265,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "activeRenderPaths",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 265,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 265,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 265,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 267,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "viewsDirsCount",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 267,
                                    "char": 29
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 267,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 267,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "activeRenderPath",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 268,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 268,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 268,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 268,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "count",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "activeRenderPath",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 268,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 268,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 268,
                                            "char": 76
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 268,
                                        "char": 76
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "activeRenderPath",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "activeRenderPath",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 269,
                                                            "char": 56
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 269,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 269,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 269,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 270,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 271,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 273,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "activeRenderPath",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 273,
                                    "char": 31
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 273,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 273,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "activeRenderPath",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 274,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 274,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 275,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 277,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "activeRenderPath",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 277,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 278,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the path (or paths) of the views that are currently rendered\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 259,
                                "char": 53
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 260,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 260,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 259,
                    "last-line": 282,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBasePath",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 285,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "basePath",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 285,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 285,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 286,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets base path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 284,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 284,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 283,
                    "last-line": 290,
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
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 293,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "content",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 293,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 293,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 294,
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
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 292,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 292,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 291,
                    "last-line": 298,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getControllerName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 301,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "controllerName",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 301,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 301,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 302,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the name of the controller rendered\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 300,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 300,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 299,
                    "last-line": 306,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLayout",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 309,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "layout",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 309,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 309,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 310,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the name of the main view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 308,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 308,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 307,
                    "last-line": 314,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLayoutsDir",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 317,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "layoutsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 317,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 317,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 318,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the current layouts sub-directory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 316,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 316,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 315,
                    "last-line": 322,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMainView",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 325,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "mainView",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 325,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 325,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 326,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the name of the main view\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 324,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 324,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 323,
                    "last-line": 330,
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
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 333,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "viewParams",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 333,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 333,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 334,
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
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 332,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 332,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 331,
                    "last-line": 353,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPartial",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "partialPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 354,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 354,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 354,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 358,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 360,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 360,
                                    "char": 14
                                },
                                "name": "partial",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "partialPath",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 360,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 360,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 360,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 360,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 360,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 362,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_get_clean",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 362,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 363,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a partial view\n     *\n     * ```php\n     * \/\/ Retrieve the contents of a partial\n     * echo $this->getPartial(\"shared\/footer\");\n     * ```\n     *\n     * ```php\n     * \/\/ Retrieve the contents of a partial with arguments\n     * echo $this->getPartial(\n     *     \"shared\/footer\",\n     *     [\n     *         \"content\" => $html,\n     *     ]\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 355,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 355,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 354,
                    "last-line": 367,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPartialsDir",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 370,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "partialsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 370,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 370,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 371,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the current partials sub-directory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 369,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 369,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 368,
                    "last-line": 387,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRender",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 388,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 388,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 388,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 388,
                            "char": 92
                        },
                        {
                            "type": "parameter",
                            "name": "configCallback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 388,
                                "char": 115
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 388,
                            "char": 115
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 390,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 395,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "view",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 395,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 395,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 395,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 400,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 400,
                                    "char": 14
                                },
                                "name": "reset",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 400,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 405,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 405,
                                    "char": 14
                                },
                                "name": "setVars",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 405,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 405,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 405,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 410,
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
                                        "value": "configCallback",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 410,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 410,
                                    "char": 35
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 410,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 410,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "call_user_func_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "configCallback",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 411,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 411,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "view",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 411,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 411,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 411,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 411,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 411,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 412,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 417,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 417,
                                    "char": 14
                                },
                                "name": "start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 417,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 422,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 422,
                                    "char": 14
                                },
                                "name": "render",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "controllerName",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 422,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 422,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "actionName",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 422,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 422,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 422,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 427,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 427,
                                    "char": 14
                                },
                                "name": "finish",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 427,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 432,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "view",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 432,
                                    "char": 21
                                },
                                "name": "getContent",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 432,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 433,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Perform the automatic rendering returning the output as a string\n     *\n     * ```php\n     * $template = $this->view->getRender(\n     *     \"products\",\n     *     \"show\",\n     *     [\n     *         \"products\" => $products,\n     *     ]\n     * );\n     * ```\n     *\n     * @param mixed configCallback\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 389,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 389,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 388,
                    "last-line": 437,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 438,
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
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 440,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 442,
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
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 442,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 442,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "viewParams",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 442,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 442,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 442,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 442,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 442,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 442,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 443,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 444,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 446,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 446,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 447,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a parameter previously set in the view\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 438,
                    "last-line": 451,
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
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 454,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "viewsDirs",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 454,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 454,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 455,
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
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 452,
                                "char": 45
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 453,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 453,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 452,
                    "last-line": 459,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getViewsDirs",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 462,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "viewsDirs",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 462,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 462,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 462,
                                    "char": 37
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 462,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 462,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 463,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "viewsDirs",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 463,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 463,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 463,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 463,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 464,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 466,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 466,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "viewsDirs",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 466,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 466,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 467,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets views directories\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 461,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 461,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 460,
                    "last-line": 471,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isDisabled",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 474,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "disabled",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 474,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 474,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 475,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Whether automatic rendering is enabled\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 473,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 473,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 472,
                    "last-line": 494,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 495,
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
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 495,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 495,
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
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 497,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 503,
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
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 503,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 503,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 503,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 503,
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
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 507,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "viewParams",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 507,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 507,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 507,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 508,
                                    "char": 15
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
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "viewParams",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 508,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 508,
                                                        "char": 58
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 508,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 508,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 508,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 508,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 513,
                                    "char": 31
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "create_symbol_table",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 513,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 514,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 523,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 523,
                                    "char": 14
                                },
                                "name": "engineRender",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 524,
                                                "char": 18
                                            },
                                            "name": "loadTemplateEngines",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 524,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 524,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 525,
                                                    "char": 18
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "partialsDir",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 525,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 525,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "partialPath",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 525,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 525,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 525,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 526,
                                            "char": 18
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 526,
                                        "char": 18
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 528,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 528,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 528,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 533,
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
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 533,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 533,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 533,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 533,
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
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 537,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 537,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 538,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 539,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a partial view\n     *\n     * ```php\n     * \/\/ Show a partial inside another view\n     * $this->partial(\"shared\/footer\");\n     * ```\n     *\n     * ```php\n     * \/\/ Show a partial inside another view with parameters\n     * $this->partial(\n     *     \"shared\/footer\",\n     *     [\n     *         \"content\" => $html,\n     *     ]\n     * );\n     * ```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 495,
                    "last-line": 558,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "pick",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "renderView",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 559,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "pickView",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 561,
                                    "char": 21
                                },
                                {
                                    "variable": "layout",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 561,
                                    "char": 29
                                },
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 561,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 563,
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
                                        "value": "renderView",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 563,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 563,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 563,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 563,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "pickView",
                                            "expr": {
                                                "type": "variable",
                                                "value": "renderView",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 564,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 564,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 565,
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
                                            "variable": "layout",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 566,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 566,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 568,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "memstr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "renderView",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 568,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 568,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 568,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 568,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 568,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "parts",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "explode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 569,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 569,
                                                                "char": 38
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "renderView",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 569,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 569,
                                                                "char": 50
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 569,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 569,
                                                    "char": 51
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "layout",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "parts",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 570,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 570,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 570,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 570,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 571,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 573,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "pickView",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "renderView",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 573,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 573,
                                                        "char": 39
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 573,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 573,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 575,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "layout",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 575,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 575,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 575,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "pickView",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "layout",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 576,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 576,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 577,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 578,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 580,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "pickView",
                                    "expr": {
                                        "type": "variable",
                                        "value": "pickView",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 580,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 580,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 582,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 582,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 583,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Choose a different view to render instead of last-controller\/last-action\n     *\n     * ```php\n     * use Phalcon\\Mvc\\Controller;\n     *\n     * class ProductsController extends Controller\n     * {\n     *     public function saveAction()\n     *     {\n     *         \/\/ Do some save stuff...\n     *\n     *         \/\/ Then show the list view\n     *         $this->view->pick(\"products\/list\");\n     *     }\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 560,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 560,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 560,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 559,
                    "last-line": 597,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 598,
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
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 600,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 600,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 602,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 602,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 603,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Register templating engines\n     *\n     * ```php\n     * $this->view->registerEngines(\n     *     [\n     *         \".phtml\" => \\Phalcon\\Mvc\\View\\Engine\\Php::class,\n     *         \".volt\"  => \\Phalcon\\Mvc\\View\\Engine\\Volt::class,\n     *         \".mhtml\" => \\MyCustomEngine::class,\n     *     ]\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 599,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 599,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 599,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 598,
                    "last-line": 612,
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
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 614,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 615,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 617,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 617,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 619,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 621,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 621,
                                            "char": 27
                                        },
                                        "name": "processRender",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "controllerName",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 621,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 621,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 621,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 621,
                                                "char": 68
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 621,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 621,
                                                "char": 76
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 621,
                                        "char": 77
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 621,
                                    "char": 77
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 623,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 623,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 623,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 624,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 625,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 627,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 627,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 628,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Executes render process from dispatching data\n     *\n     *```php\n     * \/\/ Shows recent posts view (app\/views\/posts\/recent.phtml)\n     * $view->start()->render(\"posts\", \"recent\")->finish();\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 617,
                                    "char": 17
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 617,
                                "char": 17
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 618,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 618,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 613,
                    "last-line": 632,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "disabled",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 635,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 635,
                                    "char": 42
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "engines",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 636,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 636,
                                    "char": 42
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "renderLevel",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 637,
                                            "char": 60
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "LEVEL_MAIN_LAYOUT",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 637,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 637,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 637,
                                    "char": 60
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "content",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 638,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 638,
                                    "char": 41
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "templatesBefore",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 639,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 639,
                                    "char": 39
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "templatesAfter",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 640,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 640,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 642,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 642,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 643,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets the view component to its factory default values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 634,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 634,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 634,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 633,
                    "last-line": 652,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBasePath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "basePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 653,
                            "char": 48
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
                                    "property": "basePath",
                                    "expr": {
                                        "type": "variable",
                                        "value": "basePath",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 655,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 655,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 657,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 657,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 658,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets base path. Depending of your platform, always add a trailing slash\n     * or backslash\n     *\n     * ```php\n     * $view->setBasePath(__DIR__ . \"\/\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 654,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 654,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 654,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 653,
                    "last-line": 666,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 667,
                            "char": 46
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
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 669,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 669,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 671,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 671,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 672,
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
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 668,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 668,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 668,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 667,
                    "last-line": 681,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLayout",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "layout",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 682,
                            "char": 44
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
                                    "property": "layout",
                                    "expr": {
                                        "type": "variable",
                                        "value": "layout",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 684,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 684,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 686,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 686,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 687,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Change the layout to be used instead of using the name of the latest\n     * controller name\n     *\n     * ```php\n     * $this->view->setLayout(\"main\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 683,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 683,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 683,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 682,
                    "last-line": 697,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLayoutsDir",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "layoutsDir",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 698,
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
                                    "property": "layoutsDir",
                                    "expr": {
                                        "type": "variable",
                                        "value": "layoutsDir",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 700,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 700,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 702,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 702,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 703,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the layouts sub-directory. Must be a directory under the views\n     * directory. Depending of your platform, always add a trailing slash or\n     * backslash\n     *\n     *```php\n     * $view->setLayoutsDir(\"..\/common\/layouts\/\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 699,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 699,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 699,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 698,
                    "last-line": 713,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMainView",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "viewPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 714,
                            "char": 48
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
                                    "property": "mainView",
                                    "expr": {
                                        "type": "variable",
                                        "value": "viewPath",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 716,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 716,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 718,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 718,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 719,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets default view name. Must be a file without extension in the views\n     * directory\n     *\n     * ```php\n     * \/\/ Renders as main view views-dir\/base.phtml\n     * $this->view->setMainView(\"base\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 715,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 715,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 715,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 714,
                    "last-line": 729,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPartialsDir",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "partialsDir",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 730,
                            "char": 54
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
                                    "property": "partialsDir",
                                    "expr": {
                                        "type": "variable",
                                        "value": "partialsDir",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 732,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 732,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 734,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 734,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 735,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a partials sub-directory. Must be a directory under the views\n     * directory. Depending of your platform, always add a trailing slash or\n     * backslash\n     *\n     *```php\n     * $view->setPartialsDir(\"..\/common\/partials\/\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 731,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 731,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 731,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 730,
                    "last-line": 743,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 744,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 744,
                            "char": 58
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
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 746,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 746,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 746,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 748,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 748,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 749,
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
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 745,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 745,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 745,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 744,
                    "last-line": 760,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRenderLevel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "level",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 761,
                            "char": 45
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
                                    "property": "renderLevel",
                                    "expr": {
                                        "type": "variable",
                                        "value": "level",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 763,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 763,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 765,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 765,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 766,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the render level for the view\n     *\n     * ```php\n     * \/\/ Render the view related to the controller only\n     * $this->view->setRenderLevel(\n     *     View::LEVEL_LAYOUT\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ViewInterface",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 762,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 762,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 762,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 761,
                    "last-line": 770,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTemplateAfter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "templateAfter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 771,
                            "char": 55
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
                                        "value": "templateAfter",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 773,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 773,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 773,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 773,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "templatesAfter",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "templateAfter",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 774,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 774,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 774,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 774,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 775,
                                    "char": 9
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
                                            "property": "templatesAfter",
                                            "expr": {
                                                "type": "variable",
                                                "value": "templateAfter",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 776,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 776,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 777,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 779,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 779,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 780,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a \"template after\" controller layout\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 772,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 772,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 772,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 771,
                    "last-line": 784,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTemplateBefore",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "templateBefore",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 785,
                            "char": 57
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
                                        "value": "templateBefore",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 787,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 787,
                                    "char": 35
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 787,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 787,
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
                                            "property": "templatesBefore",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "templateBefore",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 788,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 788,
                                                        "char": 56
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 788,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 788,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 789,
                                    "char": 9
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
                                            "property": "templatesBefore",
                                            "expr": {
                                                "type": "variable",
                                                "value": "templateBefore",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 790,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 790,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 791,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 793,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 793,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 794,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a template before the controller layout\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 786,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 786,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 786,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 785,
                    "last-line": 802,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 803,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 803,
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
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 805,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 805,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 805,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 807,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 807,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 808,
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
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 804,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 804,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 804,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 803,
                    "last-line": 820,
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
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 821,
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
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 821,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 821,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 823,
                                "char": 18
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
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 824,
                                                                "char": 53
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "viewParams",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 824,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 824,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 824,
                                                        "char": 64
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 824,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 824,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 824,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 824,
                                            "char": 73
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 825,
                                    "char": 9
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
                                            "property": "viewParams",
                                            "expr": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 826,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 826,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 827,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 829,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 829,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 830,
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
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 822,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 822,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 822,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 821,
                    "last-line": 835,
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
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 836,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 838,
                                    "char": 21
                                },
                                {
                                    "variable": "directory",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 838,
                                    "char": 32
                                },
                                {
                                    "variable": "newViewsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 838,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 840,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "viewsDir",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 840,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 840,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 840,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 840,
                                    "char": 39
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "viewsDir",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 840,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 840,
                                        "char": 58
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 840,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 840,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 840,
                                "char": 66
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
                                                    "value": "Views directory must be a string or an array",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 841,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 841,
                                                "char": 77
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 841,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 842,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 844,
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
                                        "value": "viewsDir",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 844,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 844,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 844,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 844,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "viewsDirs",
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
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 845,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 845,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 845,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 845,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 846,
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
                                            "variable": "newViewsDir",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 847,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 847,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 849,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "viewsDir",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 849,
                                        "char": 49
                                    },
                                    "key": "position",
                                    "value": "directory",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "directory",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 850,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 850,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 850,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 850,
                                                "char": 47
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
                                                                    "value": "Views directory item must be a string",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 853,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 853,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 853,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 854,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 856,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "newViewsDir",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "position",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 856,
                                                            "char": 41
                                                        }
                                                    ],
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
                                                                    "value": "directory",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 856,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 856,
                                                                "char": 72
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 856,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 856,
                                                    "char": 73
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 857,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 859,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "viewsDirs",
                                            "expr": {
                                                "type": "variable",
                                                "value": "newViewsDir",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 859,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 859,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 860,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 862,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 862,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 863,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the views directory. Depending of your platform,\n     * always add a trailing slash or backslash\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 837,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 837,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 837,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 836,
                    "last-line": 867,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "start",
                    "statements": [
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "ob_start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 870,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 872,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "content",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 872,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 872,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 874,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 874,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 875,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Starts rendering process enabling the output buffering\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "View",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 869,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 869,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 869,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 868,
                    "last-line": 879,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toString",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 881,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 882,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 884,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 884,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 886,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 888,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 888,
                                    "char": 14
                                },
                                "name": "start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 888,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 890,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 890,
                                            "char": 27
                                        },
                                        "name": "processRender",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "controllerName",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 891,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 891,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 892,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 892,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 893,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 893,
                                                "char": 19
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 895,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 895,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 895,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 895,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 897,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 897,
                                    "char": 14
                                },
                                "name": "finish",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 897,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 899,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "result",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 899,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 899,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 900,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 901,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 903,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 903,
                                    "char": 21
                                },
                                "name": "getContent",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 903,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 904,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders the view and returns it as a string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 885,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 885,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 880,
                    "last-line": 908,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "engineRender",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "engines",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 910,
                            "char": 22
                        },
                        {
                            "type": "parameter",
                            "name": "viewPath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 911,
                            "char": 24
                        },
                        {
                            "type": "parameter",
                            "name": "silence",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 912,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "mustClean",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 914,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 914,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "notExists",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 915,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 916,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "basePath",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 916,
                                    "char": 21
                                },
                                {
                                    "variable": "engine",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 916,
                                    "char": 29
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 916,
                                    "char": 44
                                },
                                {
                                    "variable": "extension",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 916,
                                    "char": 55
                                },
                                {
                                    "variable": "viewsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 916,
                                    "char": 65
                                },
                                {
                                    "variable": "viewsDirPath",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 916,
                                    "char": 79
                                },
                                {
                                    "variable": "viewEnginePath",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 917,
                                    "char": 27
                                },
                                {
                                    "variable": "viewEnginePaths",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 917,
                                    "char": 44
                                },
                                {
                                    "variable": "viewParams",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 917,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 919,
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
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 919,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 919,
                                    "char": 35
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "basePath",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 920,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "basePath",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 920,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 920,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 920,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "viewParams",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 921,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "viewParams",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 921,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 921,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 921,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "ManagerInterface",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 922,
                                            "char": 69
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 922,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 922,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 922,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 922,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 922,
                                    "char": 69
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "viewEnginePaths",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 923,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 923,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 925,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 925,
                                    "char": 30
                                },
                                "name": "getViewsDirs",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 925,
                                "char": 46
                            },
                            "value": "viewsDir",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 926,
                                                "char": 22
                                            },
                                            "name": "isAbsolutePath",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "viewPath",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 926,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 926,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 926,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 926,
                                        "char": 48
                                    },
                                    "statements": [
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "basePath",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 927,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "viewsDir",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 927,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 927,
                                                            "char": 56
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "viewPath",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 927,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 927,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 927,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 928,
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
                                                    "variable": "viewsDirPath",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "viewPath",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 929,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 929,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 930,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 935,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "engines",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 935,
                                        "char": 46
                                    },
                                    "key": "extension",
                                    "value": "engine",
                                    "reverse": 0,
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
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 936,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "extension",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 936,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 936,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 936,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 938,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "file_exists",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "viewEnginePath",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 938,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 938,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 938,
                                                "char": 48
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
                                                                "value": "eventsManager",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 943,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 943,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 943,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 943,
                                                        "char": 55
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "activeRenderPaths",
                                                                    "expr": {
                                                                        "type": "array",
                                                                        "left": [
                                                                            {
                                                                                "value": {
                                                                                    "type": "variable",
                                                                                    "value": "viewEnginePath",
                                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                    "line": 944,
                                                                                    "char": 70
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 944,
                                                                                "char": 70
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 944,
                                                                        "char": 71
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 944,
                                                                    "char": 71
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 946,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "identical",
                                                                "left": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "eventsManager",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 946,
                                                                        "char": 42
                                                                    },
                                                                    "name": "fire",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "view:beforeRenderView",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 946,
                                                                                "char": 69
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 946,
                                                                            "char": 69
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 946,
                                                                                "char": 75
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 946,
                                                                            "char": 75
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "viewEnginePath",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 946,
                                                                                "char": 91
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 946,
                                                                            "char": 91
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 946,
                                                                    "char": 95
                                                                },
                                                                "right": {
                                                                    "type": "bool",
                                                                    "value": "false",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 946,
                                                                    "char": 103
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 946,
                                                                "char": 103
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "continue",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 948,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 949,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 951,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "engine",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 951,
                                                            "char": 28
                                                        },
                                                        "name": "render",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "viewEnginePath",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 951,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 951,
                                                                "char": 50
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "viewParams",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 951,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 951,
                                                                "char": 62
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "mustClean",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 951,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 951,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 951,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 957,
                                                    "char": 23
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
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 957,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 957,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 959,
                                                    "char": 22
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
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 959,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 959,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 959,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 959,
                                                        "char": 55
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "eventsManager",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 960,
                                                                    "char": 39
                                                                },
                                                                "name": "fire",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "view:afterRenderView",
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 960,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 960,
                                                                        "char": 65
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 960,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 960,
                                                                        "char": 71
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 960,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 961,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 962,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 963,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 965,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "viewEnginePaths",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "viewEnginePath",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 965,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 965,
                                                    "char": 55
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 966,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 967,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 969,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "notExists",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 969,
                                "char": 22
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
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 973,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 973,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 973,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 973,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "activeRenderPaths",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "viewEnginePaths",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 974,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 974,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 976,
                                            "char": 29
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 976,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "view:notFoundView",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 976,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 976,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 976,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 976,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "viewEnginePath",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 976,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 976,
                                                        "char": 76
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 976,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 977,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 979,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "silence",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 979,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 979,
                                        "char": 25
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
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 981,
                                                                    "char": 28
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "viewPath",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 981,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 981,
                                                                "char": 39
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "' was not found in any of the views directory",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 982,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 982,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 982,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 982,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 983,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 984,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 985,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether view exists on registered extensions and render it\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 909,
                    "last-line": 989,
                    "char": 22
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "isAbsolutePath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 990,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "constant",
                                    "value": "PHP_OS",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 992,
                                    "char": 20
                                },
                                "right": {
                                    "type": "string",
                                    "value": "WINNT",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 992,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 992,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "and",
                                            "left": {
                                                "type": "greater-equal",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strlen",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "path",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 993,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 993,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 993,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "3",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 993,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 993,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "path",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 993,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 993,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 993,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "char",
                                                    "value": ":",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 993,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 993,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 993,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 993,
                                                    "char": 61
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 993,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 993,
                                                "char": 66
                                            },
                                            "right": {
                                                "type": "char",
                                                "value": "\\\\",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 993,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 993,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 993,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 994,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 996,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "greater-equal",
                                    "left": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 996,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 996,
                                                "char": 27
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 996,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 996,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 996,
                                    "char": 34
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "path",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 996,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 996,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 996,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "char",
                                        "value": "\/",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 996,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 996,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 996,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 997,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a path is absolute or not\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 990,
                    "last-line": 1001,
                    "char": 28
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
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1004,
                                    "char": 20
                                },
                                {
                                    "variable": "di",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1004,
                                    "char": 24
                                },
                                {
                                    "variable": "registeredEngines",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1004,
                                    "char": 43
                                },
                                {
                                    "variable": "engineService",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1004,
                                    "char": 58
                                },
                                {
                                    "variable": "extension",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1004,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1006,
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
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1006,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "engines",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1006,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1006,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1006,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1011,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "engines",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1011,
                                    "char": 22
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1011,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1011,
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
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "DiInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1012,
                                                    "char": 51
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1012,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1012,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1012,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1012,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1012,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1014,
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
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1014,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1014,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1015,
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
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1015,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "registeredEngines",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1015,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1015,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1015,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1017,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "registeredEngines",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1017,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1017,
                                        "char": 40
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
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1021,
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
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1021,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1021,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "di",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1021,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1021,
                                                                "char": 61
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1021,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1021,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1022,
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
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1023,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1023,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1023,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1023,
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
                                                                                "value": "application services",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1027,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1027,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1028,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1028,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1028,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1029,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1031,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "registeredEngines",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1031,
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
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1032,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1032,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1032,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1032,
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
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1036,
                                                                    "char": 51
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "Closure",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1036,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1036,
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
                                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                            "line": 1038,
                                                                                            "char": 46
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                        "line": 1038,
                                                                                        "char": 46
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "di",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                            "line": 1040,
                                                                                            "char": 29
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                        "line": 1040,
                                                                                        "char": 29
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1040,
                                                                                "char": 30
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1040,
                                                                            "char": 30
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1042,
                                                                    "char": 31
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
                                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                    "line": 1042,
                                                                                    "char": 50
                                                                                }
                                                                            ],
                                                                            "expr": {
                                                                                "type": "fcall",
                                                                                "name": "call_user_func",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "engineService",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                            "line": 1043,
                                                                                            "char": 46
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                        "line": 1043,
                                                                                        "char": 46
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "this",
                                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                            "line": 1045,
                                                                                            "char": 29
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                        "line": 1045,
                                                                                        "char": 29
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1045,
                                                                                "char": 30
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1045,
                                                                            "char": 30
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1046,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "else_statements": [
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
                                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                    "line": 1047,
                                                                                    "char": 50
                                                                                }
                                                                            ],
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "engineService",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1047,
                                                                                "char": 67
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1047,
                                                                            "char": 67
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1048,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1049,
                                                            "char": 21
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
                                                                        "value": "engineService",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1053,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1053,
                                                                    "char": 50
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "string",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1053,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1053,
                                                                "char": 59
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
                                                                                        "type": "string",
                                                                                        "value": "Invalid template engine registration for extension: ",
                                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                        "line": 1055,
                                                                                        "char": 86
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "extension",
                                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                        "line": 1056,
                                                                                        "char": 29
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                    "line": 1056,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1056,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1056,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1057,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1059,
                                                            "char": 27
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
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1059,
                                                                            "char": 46
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "di",
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1059,
                                                                            "char": 53
                                                                        },
                                                                        "name": "getShared",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "engineService",
                                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                    "line": 1060,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1060,
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
                                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                                "line": 1061,
                                                                                                "char": 34
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                            "line": 1061,
                                                                                            "char": 34
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                    "line": 1062,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1062,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1062,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1062,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1063,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1064,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1065,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1067,
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
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1067,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1067,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1068,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1070,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "engines",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1070,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1071,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Loads registered template engines, if none is registered it will use\n     * Phalcon\\Mvc\\View\\Engine\\Php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1003,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 1003,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 1002,
                    "last-line": 1075,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "processRender",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1077,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "actionName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1078,
                            "char": 27
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1079,
                                "char": 26
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1079,
                            "char": 26
                        },
                        {
                            "type": "parameter",
                            "name": "fireEvents",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1081,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1081,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "silence",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1083,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1084,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "renderLevel",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1084,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1085,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "layoutsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1085,
                                    "char": 23
                                },
                                {
                                    "variable": "layout",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1085,
                                    "char": 31
                                },
                                {
                                    "variable": "pickView",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1085,
                                    "char": 41
                                },
                                {
                                    "variable": "layoutName",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1085,
                                    "char": 53
                                },
                                {
                                    "variable": "engines",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1085,
                                    "char": 62
                                },
                                {
                                    "variable": "renderView",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1085,
                                    "char": 74
                                },
                                {
                                    "variable": "pickViewAction",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1086,
                                    "char": 27
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1086,
                                    "char": 42
                                },
                                {
                                    "variable": "disabledLevels",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1086,
                                    "char": 58
                                },
                                {
                                    "variable": "templatesBefore",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1086,
                                    "char": 75
                                },
                                {
                                    "variable": "templatesAfter",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1087,
                                    "char": 27
                                },
                                {
                                    "variable": "templateBefore",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1087,
                                    "char": 43
                                },
                                {
                                    "variable": "templateAfter",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1087,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1089,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "currentRenderLevel",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1089,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1089,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1095,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1095,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "disabled",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1095,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1095,
                                    "char": 29
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1095,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1095,
                                "char": 37
                            },
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
                                                "type": "fcall",
                                                "name": "ob_get_contents",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1096,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1096,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1098,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1098,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1099,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1101,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "controllerName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "controllerName",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1101,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1101,
                                    "char": 50
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "actionName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionName",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1102,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1102,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1104,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1104,
                                    "char": 14
                                },
                                "name": "setVars",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1104,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1104,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1104,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1109,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "layoutsDir",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1109,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "layoutsDir",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1109,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1109,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1109,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1111,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "layoutsDir",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1111,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1111,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "layoutsDir",
                                            "expr": {
                                                "type": "string",
                                                "value": "layouts\/",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1112,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1112,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1113,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1118,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "layout",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1118,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "layout",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1118,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1118,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1118,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1120,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "layout",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1120,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "layoutName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "layout",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1121,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1121,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1122,
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
                                            "variable": "layoutName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "controllerName",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1123,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1123,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1124,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1129,
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
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1129,
                                            "char": 28
                                        },
                                        "name": "loadTemplateEngines",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1129,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1129,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1134,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pickView",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1134,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "pickView",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1134,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1134,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1134,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1136,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "pickView",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1136,
                                    "char": 23
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1136,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1136,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "renderView",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "controllerName",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1137,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\/",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1137,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1137,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1137,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1137,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1137,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1138,
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
                                            "variable": "renderView",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "pickView",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1143,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1143,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1143,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1143,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1145,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "layoutName",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1145,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1145,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1145,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "pickViewAction",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1146,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "pickView",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1146,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1146,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1146,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1146,
                                                "char": 54
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "layoutName",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "pickViewAction",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1147,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1147,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1148,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1149,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1150,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1152,
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
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "ManagerInterface",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1152,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1152,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1152,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1152,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1152,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1152,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1158,
                            "char": 27
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "create_symbol_table",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1158,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1163,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "variable",
                                    "value": "fireEvents",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1163,
                                    "char": 24
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1163,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1163,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1163,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1163,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1163,
                                "char": 57
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
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1164,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "view:beforeRender",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1164,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1164,
                                                    "char": 53
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1164,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1164,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1164,
                                            "char": 63
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1164,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1164,
                                        "char": 71
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1165,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1166,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1167,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1173,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "content",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "ob_get_contents",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1173,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1173,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "silence",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1174,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1174,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1179,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "disabledLevels",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1179,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "disabledLevels",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1179,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1179,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1179,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1184,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "renderLevel",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1184,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "renderLevel",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1184,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1184,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1184,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1184,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1186,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "renderLevel",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1186,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "renderLevel",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1190,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1190,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "LEVEL_ACTION_VIEW",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1190,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1190,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1190,
                                        "char": 54
                                    },
                                    "statements": [
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
                                                            "value": "disabledLevels",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1191,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "self",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1191,
                                                                "char": 65
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "LEVEL_ACTION_VIEW",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1191,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1191,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1191,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1191,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1191,
                                                "char": 67
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "currentRenderLevel",
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "self",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1192,
                                                                    "char": 75
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "LEVEL_ACTION_VIEW",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1192,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1192,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1192,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1194,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1194,
                                                            "char": 26
                                                        },
                                                        "name": "engineRender",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "engines",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1195,
                                                                    "char": 32
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1195,
                                                                "char": 32
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "renderView",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1196,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1196,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "silence",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1198,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1198,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1198,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1199,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1200,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1205,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "renderLevel",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1205,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1205,
                                                "char": 59
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "LEVEL_BEFORE_TEMPLATE",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1205,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1205,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1205,
                                        "char": 59
                                    },
                                    "statements": [
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
                                                            "value": "disabledLevels",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1206,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "self",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1206,
                                                                "char": 69
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "LEVEL_BEFORE_TEMPLATE",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1206,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1206,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1206,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1206,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1206,
                                                "char": 71
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "currentRenderLevel",
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "self",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1207,
                                                                    "char": 79
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "LEVEL_BEFORE_TEMPLATE",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1207,
                                                                    "char": 79
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1207,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1207,
                                                            "char": 79
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "templatesBefore",
                                                            "expr": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1208,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "templatesBefore",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1208,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1208,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1208,
                                                            "char": 73
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "silence",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1209,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1209,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1211,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "templatesBefore",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1211,
                                                        "char": 59
                                                    },
                                                    "value": "templateBefore",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1212,
                                                                    "char": 30
                                                                },
                                                                "name": "engineRender",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "engines",
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1213,
                                                                            "char": 36
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1213,
                                                                        "char": 36
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "layoutsDir",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1214,
                                                                                "char": 40
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "templateBefore",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1214,
                                                                                "char": 56
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1214,
                                                                            "char": 56
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1214,
                                                                        "char": 56
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "silence",
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1216,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1216,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1216,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1217,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1219,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "silence",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1219,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1219,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1220,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1221,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1226,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "renderLevel",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1226,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1226,
                                                "char": 49
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "LEVEL_LAYOUT",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1226,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1226,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1226,
                                        "char": 49
                                    },
                                    "statements": [
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
                                                            "value": "disabledLevels",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1227,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "self",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1227,
                                                                "char": 60
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "LEVEL_LAYOUT",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1227,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1227,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1227,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1227,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1227,
                                                "char": 62
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "currentRenderLevel",
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "self",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1228,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "LEVEL_LAYOUT",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1228,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1228,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1228,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1230,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1230,
                                                            "char": 26
                                                        },
                                                        "name": "engineRender",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "engines",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1231,
                                                                    "char": 32
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1231,
                                                                "char": 32
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "layoutsDir",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1232,
                                                                        "char": 36
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "layoutName",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1232,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1232,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1232,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "silence",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1234,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1234,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1234,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1235,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1236,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1241,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "renderLevel",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1241,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1241,
                                                "char": 57
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "LEVEL_AFTER_TEMPLATE",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1241,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1241,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1241,
                                        "char": 57
                                    },
                                    "statements": [
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
                                                            "value": "disabledLevels",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1242,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "self",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1242,
                                                                "char": 68
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "LEVEL_AFTER_TEMPLATE",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1242,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1242,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1242,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1242,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1242,
                                                "char": 70
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "currentRenderLevel",
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "self",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1243,
                                                                    "char": 78
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "LEVEL_AFTER_TEMPLATE",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1243,
                                                                    "char": 78
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1243,
                                                                "char": 78
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1243,
                                                            "char": 78
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "templatesAfter",
                                                            "expr": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1244,
                                                                    "char": 57
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "templatesAfter",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1244,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1244,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1244,
                                                            "char": 72
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "silence",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1245,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1245,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1247,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "templatesAfter",
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1247,
                                                        "char": 57
                                                    },
                                                    "value": "templateAfter",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1248,
                                                                    "char": 30
                                                                },
                                                                "name": "engineRender",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "engines",
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1249,
                                                                            "char": 36
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1249,
                                                                        "char": 36
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "layoutsDir",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1250,
                                                                                "char": 40
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "templateAfter",
                                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                                "line": 1250,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1250,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1250,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "silence",
                                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                            "line": 1252,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1252,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1252,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1253,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1255,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "silence",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1255,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1255,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1256,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1257,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1262,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "renderLevel",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1262,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1262,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "LEVEL_MAIN_LAYOUT",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1262,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1262,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1262,
                                        "char": 54
                                    },
                                    "statements": [
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
                                                            "value": "disabledLevels",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1263,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "self",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1263,
                                                                "char": 65
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "LEVEL_MAIN_LAYOUT",
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1263,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1263,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1263,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1263,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1263,
                                                "char": 67
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "currentRenderLevel",
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "self",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1264,
                                                                    "char": 75
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "LEVEL_MAIN_LAYOUT",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1264,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1264,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1264,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1266,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                            "line": 1266,
                                                            "char": 26
                                                        },
                                                        "name": "engineRender",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "engines",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1267,
                                                                    "char": 32
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1267,
                                                                "char": 32
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1268,
                                                                        "char": 30
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "mainView",
                                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                        "line": 1268,
                                                                        "char": 39
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1268,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1268,
                                                                "char": 39
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "silence",
                                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                    "line": 1270,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                                "line": 1270,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                        "line": 1270,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1271,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1272,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1274,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "currentRenderLevel",
                                            "expr": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1274,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1274,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1275,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1280,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "variable",
                                    "value": "fireEvents",
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1280,
                                    "char": 24
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1280,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1280,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1280,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1280,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1280,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                                            "line": 1281,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "view:afterRender",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1281,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1281,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                    "line": 1281,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                                "line": 1281,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                                        "line": 1281,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                                    "line": 1282,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1284,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1284,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/View.zep",
                            "line": 1285,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Processes the view and templates; Fires events if needed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/View.zep",
                                "line": 1082,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 1082,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 1076,
                    "last-line": 1286,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "LEVEL_ACTION_VIEW",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 54,
                        "char": 32
                    },
                    "docblock": "**\n     * Render Level: To the action view\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 58,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "LEVEL_BEFORE_TEMPLATE",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 59,
                        "char": 36
                    },
                    "docblock": "**\n     * Render Level: To the templates \"before\"\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 63,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "LEVEL_LAYOUT",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 64,
                        "char": 27
                    },
                    "docblock": "**\n     * Render Level: To the controller layout\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 68,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "LEVEL_MAIN_LAYOUT",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 69,
                        "char": 32
                    },
                    "docblock": "**\n     * Render Level: To the main layout\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 73,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "LEVEL_NO_RENDER",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 74,
                        "char": 30
                    },
                    "docblock": "**\n     * Render Level: No render any view\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 78,
                    "char": 6
                },
                {
                    "type": "const",
                    "name": "LEVEL_AFTER_TEMPLATE",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Mvc\/View.zep",
                        "line": 79,
                        "char": 35
                    },
                    "docblock": "**\n     * Render Level: Render to the templates \"after\"\n     *",
                    "file": "\/app\/phalcon\/Mvc\/View.zep",
                    "line": 81,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/View.zep",
            "line": 49,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/View.zep",
        "line": 49,
        "char": 5
    }
]