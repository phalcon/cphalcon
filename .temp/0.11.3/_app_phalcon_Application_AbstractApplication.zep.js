[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Application",
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Application\\Exception",
                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                "line": 15,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                "line": 16,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                "line": 17,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Base class for Phalcon\\Cli\\Console and Phalcon\\Mvc\\Application.\n *",
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 22,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractApplication",
        "abstract": 1,
        "final": 0,
        "extends": "Injectable",
        "implements": [
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                "line": 23,
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
                    "name": "container",
                    "docblock": "**\n     * @var DiInterface\n     *",
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 31,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultModule",
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 36,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "docblock": "**\n     * @var null | ManagerInterface\n     *",
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 41,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "modules",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 42,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 46,
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
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 47,
                                "char": 55
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 47,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 47,
                            "char": 63
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                        "line": 49,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 49,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 49,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 49,
                                "char": 39
                            },
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
                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                "line": 50,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                            "line": 50,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 51,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 52,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\AbstractApplication constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 48,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 47,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultModule",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 59,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "defaultModule",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 59,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 59,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 60,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default module name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 58,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 58,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 57,
                    "last-line": 64,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEventsManager",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 67,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 67,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 67,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 68,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 66,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 66,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 66,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 65,
                    "last-line": 72,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModule",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 73,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "module",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 75,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 77,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "module",
                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                            "line": 77,
                                            "char": 56
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                    "line": 77,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "modules",
                                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                    "line": 77,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                "line": 77,
                                                "char": 49
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                "line": 77,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                            "line": 77,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                        "line": 77,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 77,
                                    "char": 56
                                },
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 77,
                                "char": 56
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
                                                            "value": "Module '",
                                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                            "line": 79,
                                                            "char": 26
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                            "line": 79,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                        "line": 79,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' isn't registered in the application container",
                                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                        "line": 80,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                    "line": 80,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                "line": 80,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                        "line": 80,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 81,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 83,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "module",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 83,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the module definition registered in the application via module name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 73,
                                "char": 54
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 74,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 74,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 73,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModules",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 91,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "modules",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 91,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 91,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 92,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the modules registered in the application\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 90,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 89,
                    "last-line": 96,
                    "char": 19
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "handle",
                    "docblock": "**\n     * Handles a request\n     *",
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 97,
                    "last-line": 116,
                    "char": 28
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerModules",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "modules",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 117,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 117,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 117,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 119,
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
                                            "property": "modules",
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
                                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                                "line": 120,
                                                                "char": 50
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "modules",
                                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                                "line": 120,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                            "line": 120,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                        "line": 120,
                                                        "char": 58
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "modules",
                                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                            "line": 120,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                        "line": 120,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                "line": 120,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                            "line": 120,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 121,
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
                                            "property": "modules",
                                            "expr": {
                                                "type": "variable",
                                                "value": "modules",
                                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                                "line": 122,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                            "line": 122,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 123,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 125,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 125,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 126,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Register an array of modules present in the application\n     *\n     * ```php\n     * $this->registerModules(\n     *     [\n     *         \"frontend\" => [\n     *             \"className\" => \\Multiple\\Frontend\\Module::class,\n     *             \"path\"      => \"..\/apps\/frontend\/Module.php\",\n     *         ],\n     *         \"backend\" => [\n     *             \"className\" => \\Multiple\\Backend\\Module::class,\n     *             \"path\"      => \"..\/apps\/backend\/Module.php\",\n     *         ],\n     *     ]\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Application",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 118,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 118,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 118,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 117,
                    "last-line": 130,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultModule",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "defaultModule",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 131,
                            "char": 59
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
                                    "property": "defaultModule",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultModule",
                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                        "line": 133,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 133,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 135,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 135,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 136,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the module name to be used if the router doesn't return a valid module\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Application",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 132,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 132,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 132,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 131,
                    "last-line": 140,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEventsManager",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventsManager",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ManagerInterface",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 141,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 141,
                            "char": 70
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
                                    "property": "eventsManager",
                                    "expr": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                        "line": 143,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 143,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 145,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 145,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                            "line": 146,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Application",
                                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                    "line": 142,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                                "line": 142,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                        "line": 142,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
                    "line": 141,
                    "last-line": 147,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
            "line": 22,
            "char": 14
        },
        "file": "\/app\/phalcon\/Application\/AbstractApplication.zep",
        "line": 22,
        "char": 14
    }
]