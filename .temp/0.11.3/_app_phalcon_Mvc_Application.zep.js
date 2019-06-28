[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Application\\AbstractApplication",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 15,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ViewInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 16,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\RouterInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\ResponseInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 18,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 19,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\DispatcherInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 20,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Application\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 21,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\RouteInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 22,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModuleDefinitionInterface",
                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                "line": 23,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 70,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Application\n *\n * This component encapsulates all the complex operations behind instantiating\n * every component needed and integrating it with the rest to allow the MVC\n * pattern to operate as desired.\n *\n *```php\n * use Phalcon\\Mvc\\Application;\n *\n * class MyApp extends Application\n * {\n *     \/**\n *      * Register the services here to make them general or register\n *      * in the ModuleDefinition to make them module-specific\n *      *\\\/\n *     protected function registerServices()\n *     {\n *\n *     }\n *\n *     \/**\n *      * This method registers all the modules in the application\n *      *\\\/\n *     public function main()\n *     {\n *         $this->registerModules(\n *             [\n *                 \"frontend\" => [\n *                     \"className\" => \"Multiple\\\\Frontend\\\\Module\",\n *                     \"path\"      => \"..\/apps\/frontend\/Module.php\",\n *                 ],\n *                 \"backend\" => [\n *                     \"className\" => \"Multiple\\\\Backend\\\\Module\",\n *                     \"path\"      => \"..\/apps\/backend\/Module.php\",\n *                 ],\n *             ]\n *         );\n *     }\n * }\n *\n * $application = new MyApp();\n *\n * $application->main();\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 71,
        "char": 5
    },
    {
        "type": "class",
        "name": "Application",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractApplication",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "implicitView",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                        "line": 73,
                        "char": 34
                    },
                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                    "line": 75,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sendCookies",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                        "line": 75,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                    "line": 77,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sendHeaders",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                        "line": 77,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                    "line": 81,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "handle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 82,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 84,
                                    "char": 22
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 84,
                                    "char": 37
                                },
                                {
                                    "variable": "router",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 84,
                                    "char": 45
                                },
                                {
                                    "variable": "dispatcher",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 84,
                                    "char": 57
                                },
                                {
                                    "variable": "response",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 84,
                                    "char": 67
                                },
                                {
                                    "variable": "view",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 84,
                                    "char": 73
                                },
                                {
                                    "variable": "module",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 85,
                                    "char": 19
                                },
                                {
                                    "variable": "moduleObject",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 85,
                                    "char": 33
                                },
                                {
                                    "variable": "moduleName",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 85,
                                    "char": 45
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 85,
                                    "char": 56
                                },
                                {
                                    "variable": "path",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 85,
                                    "char": 62
                                },
                                {
                                    "variable": "implicitView",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 85,
                                    "char": 76
                                },
                                {
                                    "variable": "returnedResponse",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 86,
                                    "char": 29
                                },
                                {
                                    "variable": "controller",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 86,
                                    "char": 41
                                },
                                {
                                    "variable": "possibleResponse",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 86,
                                    "char": 59
                                },
                                {
                                    "variable": "renderStatus",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 86,
                                    "char": 73
                                },
                                {
                                    "variable": "matchedRoute",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 87,
                                    "char": 25
                                },
                                {
                                    "variable": "match",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 87,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 89,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 89,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 89,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 89,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 89,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 91,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 91,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 91,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 91,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 91,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 91,
                                "char": 48
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
                                                                "value": "internal services",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 93,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 93,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 94,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 94,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 94,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 95,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 97,
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
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 97,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 97,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 97,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 97,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 97,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 97,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 103,
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
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 103,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 103,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 103,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 103,
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
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 104,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "application:boot",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 104,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 104,
                                                    "char": 52
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 104,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 104,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 104,
                                            "char": 62
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 104,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 104,
                                        "char": 70
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 105,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 106,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 107,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 109,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "router",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "RouterInterface",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 109,
                                            "char": 68
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 109,
                                                "char": 50
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "router",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 109,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 109,
                                                    "char": 67
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 109,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 109,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 109,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 114,
                            "char": 14
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "router",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 114,
                                    "char": 16
                                },
                                "name": "handle",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 114,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 114,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 114,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 120,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "matchedRoute",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "router",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 120,
                                            "char": 35
                                        },
                                        "name": "getMatchedRoute",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 120,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 120,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 122,
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
                                        "value": "matchedRoute",
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 122,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 122,
                                    "char": 33
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 122,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 122,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "match",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "matchedRoute",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 123,
                                                    "char": 38
                                                },
                                                "name": "getMatch",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 123,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 123,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 125,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "match",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 125,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 125,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 125,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "instanceof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "match",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 126,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "Closure",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 126,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 126,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "match",
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
                                                                            "value": "match",
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 127,
                                                                            "char": 52
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 127,
                                                                        "char": 52
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "container",
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 127,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 127,
                                                                        "char": 63
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 127,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 127,
                                                            "char": 64
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 128,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 133,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "possibleResponse",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "call_user_func_array",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "match",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 134,
                                                                    "char": 26
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 134,
                                                                "char": 26
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "router",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 135,
                                                                        "char": 28
                                                                    },
                                                                    "name": "getParams",
                                                                    "call-type": 1,
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 136,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 136,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 136,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 136,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 141,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "possibleResponse",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 141,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 141,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 141,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 141,
                                                "char": 54
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "response",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "ResponseInterface",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 142,
                                                                    "char": 86
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 142,
                                                                        "char": 66
                                                                    },
                                                                    "name": "getShared",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "response",
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 142,
                                                                                "char": 85
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 142,
                                                                            "char": 85
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 142,
                                                                    "char": 86
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 142,
                                                                "char": 86
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 142,
                                                            "char": 86
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 144,
                                                    "char": 28
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "response",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 144,
                                                            "char": 30
                                                        },
                                                        "name": "setContent",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "possibleResponse",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 144,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 144,
                                                                "char": 58
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 144,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 146,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "response",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 146,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 147,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 153,
                                            "char": 18
                                        },
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
                                                            "value": "possibleResponse",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 153,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 153,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 153,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 153,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "instanceof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "possibleResponse",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 153,
                                                        "char": 83
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "ResponseInterface",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 153,
                                                        "char": 103
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 153,
                                                    "char": 103
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 153,
                                                "char": 103
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "possibleResponse",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 154,
                                                            "char": 38
                                                        },
                                                        "name": "sendHeaders",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 154,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 155,
                                                    "char": 36
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "possibleResponse",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 155,
                                                            "char": 38
                                                        },
                                                        "name": "sendCookies",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 155,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 157,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "possibleResponse",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 157,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 158,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 159,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 160,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 165,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "moduleName",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "router",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 165,
                                            "char": 33
                                        },
                                        "name": "getModuleName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 165,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 165,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 167,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "moduleName",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 167,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 167,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "moduleName",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 168,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultModule",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 168,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 168,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 168,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 169,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 171,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "moduleObject",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 171,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 171,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 176,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "moduleName",
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 176,
                                "char": 23
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
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 177,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 177,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 177,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 177,
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
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 178,
                                                        "char": 34
                                                    },
                                                    "name": "fire",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "application:beforeStartModule",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 178,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 178,
                                                            "char": 69
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 178,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 178,
                                                            "char": 75
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "moduleName",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 178,
                                                                "char": 87
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 178,
                                                            "char": 87
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 178,
                                                    "char": 91
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 178,
                                                    "char": 99
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 178,
                                                "char": 99
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 179,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 180,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 181,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 186,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "module",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 186,
                                                    "char": 31
                                                },
                                                "name": "getModule",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "moduleName",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 186,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 186,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 186,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 186,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 191,
                                    "char": 14
                                },
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
                                                            "value": "module",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 191,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 191,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 191,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 191,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "module",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 191,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 191,
                                                        "char": 67
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 191,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 191,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 191,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 191,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 191,
                                        "char": 77
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
                                                            "value": "Invalid module definition",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 192,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 192,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 192,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 193,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 199,
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
                                                "value": "module",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 199,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 199,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 199,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 199,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fetch",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 203,
                                                        "char": 56
                                                    },
                                                    "right": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "module",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 203,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "className",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 203,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 203,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 203,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 203,
                                                "char": 56
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "className",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "Module",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 204,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 204,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 205,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 210,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "path",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 210,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "module",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 210,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "path",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 210,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 210,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 210,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "not",
                                                            "left": {
                                                                "type": "fcall",
                                                                "name": "file_exists",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "path",
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 211,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 211,
                                                                        "char": 50
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 211,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 211,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 211,
                                                        "char": 52
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
                                                                                    "value": "Module definition path '",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                    "line": 213,
                                                                                    "char": 54
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "path",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                    "line": 213,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 213,
                                                                                "char": 61
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' doesn't exist",
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 214,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 214,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 214,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 214,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 215,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 217,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "class_exists",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "className",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 217,
                                                                        "char": 47
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 217,
                                                                    "char": 47
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 217,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 217,
                                                                    "char": 54
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 217,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 217,
                                                        "char": 56
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "require",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "path",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 218,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 219,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 220,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 222,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "moduleObject",
                                                    "expr": {
                                                        "type": "type-hint",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "ModuleDefinitionInterface",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 222,
                                                            "char": 89
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "container",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 222,
                                                                "char": 74
                                                            },
                                                            "name": "get",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "className",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 222,
                                                                        "char": 88
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 222,
                                                                    "char": 88
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 222,
                                                            "char": 89
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 222,
                                                        "char": 89
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 222,
                                                    "char": 89
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 228,
                                            "char": 28
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "moduleObject",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 228,
                                                    "char": 30
                                                },
                                                "name": "registerAutoloaders",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 228,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 228,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 228,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 229,
                                            "char": 28
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "moduleObject",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 229,
                                                    "char": 30
                                                },
                                                "name": "registerServices",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 229,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 229,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 229,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 230,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "instanceof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "module",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 234,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "Closure",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 234,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 234,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 234,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 234,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 234,
                                                "char": 58
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
                                                                    "value": "Invalid module definition",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 235,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 235,
                                                                "char": 66
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 235,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 236,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 238,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "moduleObject",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "call_user_func_array",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "module",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 239,
                                                                    "char": 27
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 239,
                                                                "char": 27
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array",
                                                                    "left": [
                                                                        {
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "container",
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 242,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 242,
                                                                            "char": 21
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 243,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 243,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 243,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 243,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 244,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 249,
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
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 249,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 249,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 249,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 249,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 250,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "application:afterStartModule",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 250,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 250,
                                                        "char": 65
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 250,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 250,
                                                        "char": 71
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "moduleObject",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 250,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 250,
                                                        "char": 85
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 250,
                                                "char": 86
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 251,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 252,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 257,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "implicitView",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 257,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "implicitView",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 257,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 257,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 257,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 259,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "implicitView",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 259,
                                    "char": 27
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 259,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 259,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "view",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "ViewInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 260,
                                                    "char": 66
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 260,
                                                        "char": 50
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "view",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 260,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 260,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 260,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 260,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 260,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 261,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 267,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dispatcher",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "DispatcherInterface",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 267,
                                            "char": 80
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 267,
                                                "char": 58
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "dispatcher",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 267,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 267,
                                                    "char": 79
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 267,
                                            "char": 80
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 267,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 267,
                                    "char": 80
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 269,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "dispatcher",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 269,
                                    "char": 20
                                },
                                "name": "setModuleName",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "router",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 269,
                                                "char": 42
                                            },
                                            "name": "getModuleName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 269,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 269,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 269,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 270,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "dispatcher",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 270,
                                    "char": 20
                                },
                                "name": "setNamespaceName",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "router",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 270,
                                                "char": 45
                                            },
                                            "name": "getNamespaceName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 270,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 270,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 270,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 271,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "dispatcher",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 271,
                                    "char": 20
                                },
                                "name": "setControllerName",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "router",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 271,
                                                "char": 46
                                            },
                                            "name": "getControllerName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 271,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 271,
                                        "char": 66
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 271,
                                "char": 67
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 272,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "dispatcher",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 272,
                                    "char": 20
                                },
                                "name": "setActionName",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "router",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 272,
                                                "char": 42
                                            },
                                            "name": "getActionName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 272,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 272,
                                        "char": 58
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 272,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 273,
                            "char": 18
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "dispatcher",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 273,
                                    "char": 20
                                },
                                "name": "setParams",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "router",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 273,
                                                "char": 38
                                            },
                                            "name": "getParams",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 273,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 273,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 273,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 278,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "implicitView",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 278,
                                    "char": 27
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 278,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 278,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "view",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 279,
                                            "char": 18
                                        },
                                        "name": "start",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 279,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 280,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 285,
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
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 285,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 285,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 285,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 285,
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
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 286,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "application:beforeHandleRequest",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 286,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 286,
                                                    "char": 67
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 286,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 286,
                                                    "char": 73
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "dispatcher",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 286,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 286,
                                                    "char": 85
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 286,
                                            "char": 89
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 286,
                                            "char": 97
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 286,
                                        "char": 97
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 287,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 288,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 289,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 294,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "controller",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dispatcher",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 294,
                                            "char": 37
                                        },
                                        "name": "dispatch",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 294,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 294,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 299,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "possibleResponse",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "dispatcher",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 299,
                                            "char": 43
                                        },
                                        "name": "getReturnedValue",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 299,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 299,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 304,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "possibleResponse",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 304,
                                    "char": 31
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 304,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 304,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "response",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "ResponseInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 305,
                                                    "char": 78
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 305,
                                                        "char": 58
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "response",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 305,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 305,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 305,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 305,
                                                "char": 78
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 305,
                                            "char": 78
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 306,
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
                                                "value": "possibleResponse",
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 310,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 310,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 310,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 310,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "response",
                                                    "expr": {
                                                        "type": "type-hint",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "ResponseInterface",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 311,
                                                            "char": 82
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "container",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 311,
                                                                "char": 62
                                                            },
                                                            "name": "getShared",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "response",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 311,
                                                                        "char": 81
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 311,
                                                                    "char": 81
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 311,
                                                            "char": 82
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 311,
                                                        "char": 82
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 311,
                                                    "char": 82
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 313,
                                            "char": 24
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "response",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 313,
                                                    "char": 26
                                                },
                                                "name": "setContent",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "possibleResponse",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 313,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 313,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 313,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 314,
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
                                                    "variable": "returnedResponse",
                                                    "expr": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "and",
                                                            "left": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "equals",
                                                                    "left": {
                                                                        "type": "typeof",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "possibleResponse",
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 318,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 318,
                                                                        "char": 67
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "object",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 318,
                                                                        "char": 75
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 318,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 318,
                                                                "char": 78
                                                            },
                                                            "right": {
                                                                "type": "list",
                                                                "left": {
                                                                    "type": "instanceof",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "possibleResponse",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 318,
                                                                        "char": 107
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "ResponseInterface",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 318,
                                                                        "char": 126
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 318,
                                                                    "char": 126
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 318,
                                                                "char": 127
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 318,
                                                            "char": 127
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 318,
                                                        "char": 128
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 318,
                                                    "char": 128
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 323,
                                            "char": 18
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
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 323,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 323,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 323,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 323,
                                                "char": 51
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "eventsManager",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 324,
                                                            "char": 35
                                                        },
                                                        "name": "fire",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "application:afterHandleRequest",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 324,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 324,
                                                                "char": 71
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 324,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 324,
                                                                "char": 77
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "controller",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 324,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 324,
                                                                "char": 89
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 324,
                                                        "char": 90
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 325,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 331,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "returnedResponse",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 331,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 331,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 331,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "implicitView",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 331,
                                                        "char": 65
                                                    },
                                                    "right": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 331,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 331,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 331,
                                                "char": 72
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
                                                                "value": "controller",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 332,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 332,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 332,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 332,
                                                        "char": 52
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "renderStatus",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 333,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 333,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 338,
                                                            "char": 26
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
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 338,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 338,
                                                                    "char": 50
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "object",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 338,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 338,
                                                                "char": 59
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "renderStatus",
                                                                            "expr": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "eventsManager",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                    "line": 339,
                                                                                    "char": 62
                                                                                },
                                                                                "name": "fire",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "string",
                                                                                            "value": "application:viewRender",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                            "line": 339,
                                                                                            "char": 90
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                        "line": 339,
                                                                                        "char": 90
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "this",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                            "line": 339,
                                                                                            "char": 96
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                        "line": 339,
                                                                                        "char": 96
                                                                                    },
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "view",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                            "line": 339,
                                                                                            "char": 102
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                        "line": 339,
                                                                                        "char": 102
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 339,
                                                                                "char": 103
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 339,
                                                                            "char": 103
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 340,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 346,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "not-identical",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "renderStatus",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 346,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "bool",
                                                                    "value": "false",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 346,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 346,
                                                                "char": 51
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "mcall",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "view",
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 352,
                                                                            "char": 34
                                                                        },
                                                                        "name": "render",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "dispatcher",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                        "line": 353,
                                                                                        "char": 44
                                                                                    },
                                                                                    "name": "getControllerName",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                    "line": 353,
                                                                                    "char": 64
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 353,
                                                                                "char": 64
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "dispatcher",
                                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                        "line": 354,
                                                                                        "char": 44
                                                                                    },
                                                                                    "name": "getActionName",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                    "line": 355,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 355,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 355,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 356,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 357,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 358,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 363,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "implicitView",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 363,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 363,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 363,
                                                "char": 42
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "view",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 364,
                                                            "char": 26
                                                        },
                                                        "name": "finish",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 364,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 365,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 367,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "returnedResponse",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 367,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 367,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 367,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "response",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "possibleResponse",
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 372,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 372,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 373,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "response",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "ResponseInterface",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 374,
                                                                    "char": 86
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 374,
                                                                        "char": 66
                                                                    },
                                                                    "name": "getShared",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "response",
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 374,
                                                                                "char": 85
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 374,
                                                                            "char": 85
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 374,
                                                                    "char": 86
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 374,
                                                                "char": 86
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 374,
                                                            "char": 86
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 376,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "implicitView",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 376,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 376,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                        "line": 376,
                                                        "char": 46
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "response",
                                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                    "line": 381,
                                                                    "char": 34
                                                                },
                                                                "name": "setContent",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "view",
                                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                                "line": 382,
                                                                                "char": 34
                                                                            },
                                                                            "name": "getContent",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                            "line": 383,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                        "line": 383,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                                "line": 383,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                            "line": 384,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 385,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 386,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 387,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 392,
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
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 392,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 392,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 392,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 392,
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
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 393,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "application:beforeSendResponse",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 393,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 393,
                                                "char": 63
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 393,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 393,
                                                "char": 69
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "response",
                                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                    "line": 393,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                                "line": 393,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 393,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 394,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 399,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 399,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "sendHeaders",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 399,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 399,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "response",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 400,
                                            "char": 22
                                        },
                                        "name": "sendHeaders",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 400,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 401,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 406,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 406,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "sendCookies",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 406,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 406,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "response",
                                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                            "line": 407,
                                            "char": 22
                                        },
                                        "name": "sendCookies",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 407,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 408,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 413,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "response",
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 413,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 414,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Handles a MVC request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ResponseInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 82,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 82,
                                "char": 64
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 83,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                        "line": 83,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                    "line": 82,
                    "last-line": 418,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sendCookiesOnHandleRequest",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sendCookies",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 419,
                            "char": 64
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
                                    "property": "sendCookies",
                                    "expr": {
                                        "type": "variable",
                                        "value": "sendCookies",
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 421,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 421,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 423,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 423,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 424,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Enables or disables sending cookies by each request handling\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Application",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 420,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 420,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                        "line": 420,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                    "line": 419,
                    "last-line": 429,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sendHeadersOnHandleRequest",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sendHeaders",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 430,
                            "char": 64
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
                                    "property": "sendHeaders",
                                    "expr": {
                                        "type": "variable",
                                        "value": "sendHeaders",
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 432,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 432,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 434,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 434,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 435,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Enables or disables sending headers by each request handling\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Application",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 431,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 431,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                        "line": 431,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                    "line": 430,
                    "last-line": 440,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useImplicitView",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "implicitView",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 441,
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
                                    "property": "implicitView",
                                    "expr": {
                                        "type": "variable",
                                        "value": "implicitView",
                                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                        "line": 443,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 443,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 445,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 445,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Application.zep",
                            "line": 446,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * By default. The view is implicitly buffering all the output\n     * You can full disable the view component using this method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Application",
                                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                    "line": 442,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Application.zep",
                                "line": 442,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Application.zep",
                        "line": 442,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Application.zep",
                    "line": 441,
                    "last-line": 447,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Application.zep",
            "line": 71,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Application.zep",
        "line": 71,
        "char": 5
    }
]