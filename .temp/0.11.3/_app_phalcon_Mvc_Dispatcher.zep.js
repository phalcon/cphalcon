[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\DispatcherInterface",
                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Dispatcher\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                "line": 14,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                "line": 15,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\ResponseInterface",
                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                "line": 16,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ControllerInterface",
                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                "line": 17,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Dispatcher",
                "alias": "BaseDispatcher",
                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                "line": 18,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 39,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Dispatching is the process of taking the request object, extracting the\n * module name, controller name, action name, and optional parameters contained\n * in it, and then instantiating a controller and calling an action of that\n * controller.\n *\n *```php\n * $di = new \\Phalcon\\Di();\n *\n * $dispatcher = new \\Phalcon\\Mvc\\Dispatcher();\n *\n * $dispatcher->setDI($di);\n *\n * $dispatcher->setControllerName(\"posts\");\n * $dispatcher->setActionName(\"index\");\n * $dispatcher->setParams([]);\n *\n * $controller = $dispatcher->dispatch();\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 40,
        "char": 5
    },
    {
        "type": "class",
        "name": "Dispatcher",
        "abstract": 0,
        "final": 0,
        "extends": "BaseDispatcher",
        "implements": [
            {
                "type": "variable",
                "value": "DispatcherInterface",
                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                "line": 41,
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
                    "name": "defaultAction",
                    "default": {
                        "type": "string",
                        "value": "index",
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 42,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 44,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultHandler",
                    "default": {
                        "type": "string",
                        "value": "index",
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 44,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 46,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handlerSuffix",
                    "default": {
                        "type": "string",
                        "value": "Controller",
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 46,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
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
                    "name": "forward",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "forward",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 107,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 109,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 111,
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
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 111,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 111,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 111,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 111,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 111,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 111,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 113,
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
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 113,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 113,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 113,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 113,
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
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 114,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "dispatch:beforeForward",
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 114,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 114,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 114,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 114,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "forward",
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 114,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 114,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 114,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 115,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 117,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "forward",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "forward",
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 117,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 117,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 117,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Forwards the execution flow to another controller\/action.\n     *\n     * ```php\n     * use Phalcon\\Events\\Event;\n     * use Phalcon\\Mvc\\Dispatcher;\n     * use App\\Backend\\Bootstrap as Backend;\n     * use App\\Frontend\\Bootstrap as Frontend;\n     *\n     * \/\/ Registering modules\n     * $modules = [\n     *     \"frontend\" => [\n     *         \"className\" => Frontend::class,\n     *         \"path\"      => __DIR__ . \"\/app\/Modules\/Frontend\/Bootstrap.php\",\n     *         \"metadata\"  => [\n     *             \"controllersNamespace\" => \"App\\Frontend\\Controllers\",\n     *         ],\n     *     ],\n     *     \"backend\" => [\n     *         \"className\" => Backend::class,\n     *         \"path\"      => __DIR__ . \"\/app\/Modules\/Backend\/Bootstrap.php\",\n     *         \"metadata\"  => [\n     *             \"controllersNamespace\" => \"App\\Backend\\Controllers\",\n     *         ],\n     *     ],\n     * ];\n     *\n     * $application->registerModules($modules);\n     *\n     * \/\/ Setting beforeForward listener\n     * $eventsManager  = $di->getShared(\"eventsManager\");\n     *\n     * $eventsManager->attach(\n     *     \"dispatch:beforeForward\",\n     *     function(Event $event, Dispatcher $dispatcher, array $forward) use ($modules) {\n     *         $metadata = $modules[$forward[\"module\"]][\"metadata\"];\n     *\n     *         $dispatcher->setModuleName(\n     *             $forward[\"module\"]\n     *         );\n     *\n     *         $dispatcher->setNamespaceName(\n     *             $metadata[\"controllersNamespace\"]\n     *         );\n     *     }\n     * );\n     *\n     * \/\/ Forward\n     * $this->dispatcher->forward(\n     *     [\n     *         \"module\"     => \"backend\",\n     *         \"controller\" => \"posts\",\n     *         \"action\"     => \"index\",\n     *     ]\n     * );\n     * ```\n     *\n     * @param array forward\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 107,
                    "last-line": 122,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveController",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 125,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "activeHandler",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 125,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 125,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 126,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the active controller in the dispatcher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ControllerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 124,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 124,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 124,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 123,
                    "last-line": 131,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getControllerClass",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 134,
                                    "char": 21
                                },
                                "name": "getHandlerClass",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 134,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 135,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Possible controller class name that will be located to dispatch the\n     * request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 133,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 133,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 132,
                    "last-line": 139,
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
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 142,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handlerName",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 142,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 142,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets last dispatched controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 141,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 140,
                    "last-line": 147,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastController",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 150,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "lastHandler",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 150,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 150,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 151,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the latest dispatched controller\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ControllerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 149,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 149,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 149,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 148,
                    "last-line": 155,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPreviousActionName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 158,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "previousActionName",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 158,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 158,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 159,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets previous dispatched action name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 157,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 157,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 156,
                    "last-line": 163,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPreviousControllerName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 166,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "previousHandlerName",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 166,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 166,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 167,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets previous dispatched controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 165,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 165,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 164,
                    "last-line": 171,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPreviousNamespaceName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 174,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "previousNamespaceName",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 174,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 174,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 175,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets previous dispatched namespace name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 173,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                        "line": 173,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 172,
                    "last-line": 179,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setControllerName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 180,
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
                                    "property": "handlerName",
                                    "expr": {
                                        "type": "variable",
                                        "value": "controllerName",
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 182,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 182,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 183,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the controller name to be dispatched\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 180,
                    "last-line": 187,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setControllerSuffix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerSuffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 188,
                            "char": 65
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
                                    "property": "handlerSuffix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "controllerSuffix",
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 190,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 190,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 191,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default controller suffix\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 188,
                    "last-line": 195,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultController",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 196,
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
                                    "property": "defaultHandler",
                                    "expr": {
                                        "type": "variable",
                                        "value": "controllerName",
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 198,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 198,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 199,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default controller name\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 196,
                    "last-line": 203,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "handleException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "exception",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "\\Exception",
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 204,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 204,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 206,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 208,
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
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 208,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 208,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 208,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 208,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 208,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 208,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 210,
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
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 210,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 210,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 210,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 210,
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
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 211,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "dispatch:beforeException",
                                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                        "line": 211,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 211,
                                                    "char": 60
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                        "line": 211,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 211,
                                                    "char": 66
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "exception",
                                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                        "line": 211,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 211,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 211,
                                            "char": 81
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 211,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 211,
                                        "char": 89
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 212,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 213,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 214,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 215,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Handles a user exception\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 204,
                    "last-line": 219,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "throwDispatchException",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 220,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "exceptionCode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 220,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 220,
                            "char": 85
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 222,
                                    "char": 22
                                },
                                {
                                    "variable": "response",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 222,
                                    "char": 32
                                },
                                {
                                    "variable": "exception",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 222,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 224,
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
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 224,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 224,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 224,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 224,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 226,
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
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 226,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 226,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 226,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 226,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 226,
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
                                                                "value": "the 'response' service",
                                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                                "line": 228,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                            "line": 228,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 228,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 228,
                                                "char": 76
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "BaseDispatcher",
                                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                        "line": 230,
                                                        "char": 13
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EXCEPTION_NO_DI",
                                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                        "line": 230,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 230,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 230,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 230,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 231,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 233,
                            "char": 11
                        },
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
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 233,
                                            "char": 74
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 233,
                                                "char": 54
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "response",
                                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                        "line": 233,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 233,
                                                    "char": 73
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 233,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 233,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 233,
                                    "char": 74
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 238,
                            "char": 16
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "response",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 238,
                                    "char": 18
                                },
                                "name": "setStatusCode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "404",
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 238,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 238,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "Not Found",
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 238,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 238,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 238,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 243,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "exception",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 243,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 243,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "exceptionCode",
                                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                    "line": 243,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 243,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 243,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 243,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 245,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 245,
                                        "char": 17
                                    },
                                    "name": "handleException",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "exception",
                                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                                "line": 245,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                            "line": 245,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 245,
                                    "char": 47
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 245,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 245,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                        "line": 246,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                    "line": 247,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 252,
                            "char": 13
                        },
                        {
                            "type": "throw",
                            "expr": {
                                "type": "variable",
                                "value": "exception",
                                "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                                "line": 252,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                            "line": 253,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Throws an internal exception\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
                    "line": 220,
                    "last-line": 254,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
            "line": 40,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Dispatcher.zep",
        "line": 40,
        "char": 5
    }
]