[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Di.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Di.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Service",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 15,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Exception",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 16,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Exception\\ServiceResolutionException",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 17,
                "char": 52
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Adapter\\Php",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 18,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Adapter\\Yaml",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 19,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\ServiceInterface",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 20,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 21,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 22,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\ServiceProviderInterface",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 23,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Di.zep",
        "line": 62,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Di is a component that implements Dependency Injection\/Service\n * Location of services and it's itself a container for them.\n *\n * Since Phalcon is highly decoupled, Phalcon\\Di is essential to integrate the\n * different components of the framework. The developer can also use this\n * component to inject dependencies and manage global instances of the different\n * classes used in the application.\n *\n * Basically, this component implements the `Inversion of Control` pattern.\n * Applying this, the objects do not receive their dependencies using setters or\n * constructors, but requesting a service dependency injector. This reduces the\n * overall complexity, since there is only one way to get the required\n * dependencies within a component.\n *\n * Additionally, this pattern increases testability in the code, thus making it\n * less prone to errors.\n *\n *```php\n * use Phalcon\\Di;\n * use Phalcon\\Http\\Request;\n *\n * $di = new Di();\n *\n * \/\/ Using a string definition\n * $di->set(\"request\", Request::class, true);\n *\n * \/\/ Using an anonymous function\n * $di->setShared(\n *     \"request\",\n *     function () {\n *         return new Request();\n *     }\n * );\n *\n * $request = $di->getRequest();\n *```\n *",
        "file": "\/app\/phalcon\/Di.zep",
        "line": 63,
        "char": 5
    },
    {
        "type": "class",
        "name": "Di",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "DiInterface",
                "file": "\/app\/phalcon\/Di.zep",
                "line": 64,
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
                    "name": "services",
                    "docblock": "**\n     * List of registered services\n     *",
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 72,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sharedInstances",
                    "docblock": "**\n     * List of shared instances\n     *",
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 79,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "docblock": "**\n     * Events Manager\n     *\n     * @var ManagerInterface\n     *",
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 84,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "_default",
                    "docblock": "**\n     * Latest DI build\n     *",
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 89,
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
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 92,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "_default",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 92,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 92,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 92,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "_default",
                                            "expr": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 93,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 93,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 94,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Di constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 91,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 90,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__call",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 100,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 100,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 100,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "instance",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 102,
                                    "char": 21
                                },
                                {
                                    "variable": "possibleService",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 102,
                                    "char": 38
                                },
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 102,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 108,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "starts_with",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 108,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 108,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "get",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 108,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 108,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 108,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "possibleService",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "lcfirst",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "substr",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "method",
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 109,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 109,
                                                                    "char": 56
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "int",
                                                                        "value": "3",
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 109,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 109,
                                                                    "char": 59
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 109,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 109,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 109,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 109,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 111,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 111,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "services",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 111,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 111,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "possibleService",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 111,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 111,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 111,
                                        "char": 54
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "instance",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 112,
                                                            "char": 37
                                                        },
                                                        "name": "get",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "possibleService",
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 112,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 112,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "arguments",
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 112,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 112,
                                                                "char": 68
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 112,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 112,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 114,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "instance",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 114,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 115,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 116,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 122,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "starts_with",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 122,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 122,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "set",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 122,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 122,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 122,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 123,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "arguments",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 123,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 123,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 123,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 123,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 124,
                                                    "char": 22
                                                },
                                                "name": "set",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "lcfirst",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "fcall",
                                                                        "name": "substr",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "method",
                                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                                    "line": 126,
                                                                                    "char": 38
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                                "line": 126,
                                                                                "char": 38
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "int",
                                                                                    "value": "3",
                                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                                    "line": 126,
                                                                                    "char": 41
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                                "line": 126,
                                                                                "char": 41
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 127,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 127,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 127,
                                                            "char": 22
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 127,
                                                        "char": 22
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "definition",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 129,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 129,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 129,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 131,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 131,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 132,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 133,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 138,
                            "char": 13
                        },
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
                                                    "value": "Call to undefined method or service '",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 139,
                                                    "char": 51
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 139,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 139,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "'",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 140,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 140,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 140,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 140,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 141,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic method to get or set services using setters\/getters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 100,
                                "char": 73
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 101,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 100,
                    "last-line": 147,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "attempt",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 148,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 148,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "shared",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 148,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 148,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 150,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 150,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 150,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 150,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 150,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 150,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 151,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 152,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 154,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "services",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 154,
                                            "char": 32
                                        }
                                    ],
                                    "expr": {
                                        "type": "new",
                                        "class": "Service",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "definition",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 154,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 154,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "shared",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 154,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 154,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 154,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 154,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 156,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 156,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 156,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 156,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 156,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 156,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 157,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Attempts to register a service in the services container\n     * Only is successful if a service hasn't been registered previously\n     * with the same name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 148,
                                    "char": 98
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 148,
                                "char": 98
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 149,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 149,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 148,
                    "last-line": 161,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 162,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 162,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 162,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 164,
                                    "char": 20
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 164,
                                    "char": 35
                                },
                                {
                                    "variable": "isShared",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 164,
                                    "char": 45
                                },
                                {
                                    "variable": "instance",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 164,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 164,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 170,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "service",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 170,
                                    "char": 48
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 170,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 170,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 170,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 170,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 170,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 170,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "isShared",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "service",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 171,
                                                    "char": 36
                                                },
                                                "name": "isShared",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 171,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 171,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 173,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "variable",
                                            "value": "isShared",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 173,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 173,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "sharedInstances",
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 173,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 173,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 173,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 173,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 173,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 173,
                                        "char": 62
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 174,
                                                        "char": 29
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "sharedInstances",
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 174,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 174,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 174,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 174,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 175,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 176,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 178,
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
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 178,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 178,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 178,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 178,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 178,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 178,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 184,
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
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 184,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 184,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 184,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 184,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "instance",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 185,
                                                    "char": 42
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "di:beforeServiceResolve",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 186,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 186,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 187,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 187,
                                                        "char": 21
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "name",
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 189,
                                                                        "char": 25
                                                                    },
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "name",
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 189,
                                                                        "char": 37
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 189,
                                                                    "char": 37
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "parameters",
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 190,
                                                                        "char": 31
                                                                    },
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "parameters",
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 191,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 191,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 192,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 192,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 192,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 192,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 193,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 195,
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
                                        "value": "instance",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 195,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 195,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 195,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 195,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "service",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 196,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 196,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 196,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "try-catch",
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "instance",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "service",
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 199,
                                                                    "char": 44
                                                                },
                                                                "name": "resolve",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "parameters",
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 199,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 199,
                                                                        "char": 63
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 199,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 199,
                                                                        "char": 69
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 199,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 199,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 200,
                                                    "char": 17
                                                }
                                            ],
                                            "catches": [
                                                {
                                                    "classes": [
                                                        {
                                                            "type": "variable",
                                                            "value": "ServiceResolutionException",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 200,
                                                            "char": 52
                                                        }
                                                    ],
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
                                                                                    "value": "Service '",
                                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                                    "line": 202,
                                                                                    "char": 35
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "name",
                                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                                    "line": 202,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                                "line": 202,
                                                                                "char": 42
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' cannot be resolved",
                                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                                "line": 203,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 203,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 203,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 203,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 204,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 207,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 207,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "isShared",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 207,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-array-index",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "sharedInstances",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 208,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "instance",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 208,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 208,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 209,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 210,
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
                                                        "type": "fcall",
                                                        "name": "class_exists",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 215,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 215,
                                                                "char": 47
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 215,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 215,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 215,
                                                "char": 49
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
                                                                            "value": "Service '",
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 217,
                                                                            "char": 35
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "name",
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 217,
                                                                            "char": 42
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 217,
                                                                        "char": 42
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "' wasn't found in the dependency injection container",
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 218,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di.zep",
                                                                    "line": 218,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 218,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 218,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 219,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 221,
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
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 221,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 221,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 221,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 221,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "count",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "parameters",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 221,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 221,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 221,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 221,
                                                "char": 68
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "instance",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "create_instance_params",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "name",
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 222,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 222,
                                                                        "char": 63
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "parameters",
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 222,
                                                                            "char": 75
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 222,
                                                                        "char": 75
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 222,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 222,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 223,
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
                                                            "variable": "instance",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "create_instance",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "name",
                                                                            "file": "\/app\/phalcon\/Di.zep",
                                                                            "line": 224,
                                                                            "char": 56
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di.zep",
                                                                        "line": 224,
                                                                        "char": 56
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 224,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 224,
                                                            "char": 57
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 225,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 226,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 227,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 233,
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
                                        "value": "instance",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 233,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 233,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 233,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 233,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "instance",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 234,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "InjectionAwareInterface",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 234,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 234,
                                        "char": 60
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "instance",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 235,
                                                    "char": 26
                                                },
                                                "name": "setDI",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 235,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 235,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 235,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 236,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 237,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 243,
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
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 243,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 243,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 243,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 243,
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
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 244,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "di:afterServiceResolve",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 245,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 245,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 246,
                                                    "char": 21
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 246,
                                                "char": 21
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 248,
                                                                "char": 25
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 248,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 248,
                                                            "char": 37
                                                        },
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "parameters",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 249,
                                                                "char": 31
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "parameters",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 249,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 249,
                                                            "char": 43
                                                        },
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "instance",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 250,
                                                                "char": 29
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "instance",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 251,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 251,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 252,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 252,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 252,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 253,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 255,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "instance",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 255,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 256,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolves the service based on its configuration\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 163,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 162,
                    "last-line": 260,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getDefault",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 263,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "_default",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 263,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 263,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 264,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the latest DI created\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 261,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 261,
                                "char": 58
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 262,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 262,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 261,
                    "last-line": 268,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getInternalEventsManager",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 271,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 271,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 271,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 272,
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
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 270,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 270,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 270,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 269,
                    "last-line": 276,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRaw",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 277,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 279,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 281,
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
                                            "value": "service",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 281,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 281,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "services",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 281,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 281,
                                                "char": 51
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 281,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 281,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 281,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 281,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 281,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Service '",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 283,
                                                            "char": 27
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 283,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 283,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' wasn't found in the dependency injection container",
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 284,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 284,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 284,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 284,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 285,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 287,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "service",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 287,
                                    "char": 24
                                },
                                "name": "getDefinition",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 287,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 288,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a service definition without resolving\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 278,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 278,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 277,
                    "last-line": 292,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 293,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 295,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 297,
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
                                            "value": "service",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 297,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 297,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "services",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 297,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 297,
                                                "char": 51
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 297,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 297,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 297,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 297,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 297,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Service '",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 299,
                                                            "char": 27
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 299,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 299,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' wasn't found in the dependency injection container",
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 300,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 300,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 300,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 300,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 301,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 303,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "service",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 303,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 304,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a Phalcon\\Di\\Service instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 294,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 294,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 294,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 293,
                    "last-line": 308,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getServices",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 311,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "services",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 311,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 311,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 312,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the services registered in the DI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 310,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 310,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 310,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 309,
                    "last-line": 317,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getShared",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 318,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 318,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 318,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "instance",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 320,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 323,
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
                                        "value": "instance",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 323,
                                        "char": 57
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 323,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "sharedInstances",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 323,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 323,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 323,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 323,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 323,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 323,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "instance",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 325,
                                                    "char": 33
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 325,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 325,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 325,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 325,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 325,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 325,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 328,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "sharedInstances",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 328,
                                                    "char": 43
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "instance",
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 328,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 328,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 329,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 331,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "instance",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 331,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 332,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolves a service, the resolved service is stored in the DI, subsequent\n     * requests for this service will return the same instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 319,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 319,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 318,
                    "last-line": 336,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "loadFromConfig",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "config",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Config",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 337,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 337,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "services",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 339,
                                    "char": 21
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 339,
                                    "char": 27
                                },
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 339,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 341,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "services",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 341,
                                            "char": 31
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 341,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 341,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 343,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "services",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 343,
                                "char": 39
                            },
                            "key": "name",
                            "value": "service",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 344,
                                            "char": 18
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 345,
                                                    "char": 21
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 345,
                                                "char": 21
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "service",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 346,
                                                    "char": 24
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 346,
                                                "char": 24
                                            },
                                            {
                                                "parameter": {
                                                    "type": "and",
                                                    "left": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "service",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 347,
                                                                "char": 30
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "shared",
                                                                "file": "\/app\/phalcon\/Di.zep",
                                                                "line": 347,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 347,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 347,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "service",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 347,
                                                            "char": 49
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "shared",
                                                            "file": "\/app\/phalcon\/Di.zep",
                                                            "line": 347,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Di.zep",
                                                        "line": 348,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 348,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 348,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 348,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 349,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 350,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Loads services from a Config object.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 338,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 337,
                    "last-line": 383,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "loadFromPhp",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 384,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "services",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 386,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 388,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "services",
                                    "expr": {
                                        "type": "new",
                                        "class": "Php",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filePath",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 388,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 388,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 388,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 388,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 390,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 390,
                                    "char": 14
                                },
                                "name": "loadFromConfig",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 390,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 390,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 390,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 391,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Loads services from a php config file.\n     *\n     * ```php\n     * $di->loadFromPhp(\"path\/services.php\");\n     * ```\n     *\n     * And the services can be specified in the file as:\n     *\n     * ```php\n     * return [\n     *      'myComponent' => [\n     *          'className' => '\\Acme\\Components\\MyComponent',\n     *          'shared' => true,\n     *      ],\n     *      'group' => [\n     *          'className' => '\\Acme\\Group',\n     *          'arguments' => [\n     *              [\n     *                  'type' => 'service',\n     *                  'service' => 'myComponent',\n     *              ],\n     *          ],\n     *      ],\n     *      'user' => [\n     *          'className' => '\\Acme\\User',\n     *      ],\n     * ];\n     * ```\n     *\n     * @link https:\/\/docs.phalconphp.com\/en\/latest\/reference\/di.html\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 385,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 384,
                    "last-line": 425,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "loadFromYaml",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "filePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 426,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "callbacks",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 426,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 426,
                            "char": 75
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "services",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 428,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 430,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "services",
                                    "expr": {
                                        "type": "new",
                                        "class": "Yaml",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filePath",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 430,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 430,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "callbacks",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 430,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 430,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 430,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 430,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 432,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 432,
                                    "char": 14
                                },
                                "name": "loadFromConfig",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 432,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 432,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 432,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 433,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Loads services from a yaml file.\n     *\n     * ```php\n     * $di->loadFromYaml(\n     *     \"path\/services.yaml\",\n     *     [\n     *         \"!approot\" => function ($value) {\n     *             return dirname(__DIR__) . $value;\n     *         }\n     *     ]\n     * );\n     * ```\n     *\n     * And the services can be specified in the file as:\n     *\n     * ```php\n     * myComponent:\n     *     className: \\Acme\\Components\\MyComponent\n     *     shared: true\n     *\n     * group:\n     *     className: \\Acme\\Group\n     *     arguments:\n     *         - type: service\n     *           name: myComponent\n     *\n     * user:\n     *    className: \\Acme\\User\n     * ```\n     *\n     * @link https:\/\/docs.phalconphp.com\/en\/latest\/reference\/di.html\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 427,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 426,
                    "last-line": 437,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 438,
                            "char": 37
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
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 440,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 440,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 440,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 440,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 440,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 440,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 441,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the DI contains a service by a name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 439,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 439,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 438,
                    "last-line": 449,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 450,
                            "char": 39
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
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 452,
                                    "char": 21
                                },
                                "name": "getShared",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 452,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 452,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 452,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 453,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to obtain a shared service using the array syntax\n     *\n     *```php\n     * var_dump($di[\"request\"]);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 451,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 451,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 450,
                    "last-line": 457,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 458,
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
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 460,
                                    "char": 21
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 460,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 460,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 460,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 461,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a service is registered using the array syntax\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 459,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 459,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 458,
                    "last-line": 469,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetSet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 470,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 470,
                            "char": 55
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
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 472,
                                    "char": 14
                                },
                                "name": "setShared",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 472,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 472,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 472,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 472,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 472,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 473,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to register a shared service using the array syntax\n     *\n     *```php\n     * $di[\"request\"] = new \\Phalcon\\Http\\Request();\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 471,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 470,
                    "last-line": 477,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetUnset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 478,
                            "char": 41
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
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 480,
                                    "char": 14
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 480,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 480,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 480,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 481,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a service from the services container using the array syntax\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 479,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 478,
                    "last-line": 503,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "register",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "provider",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ServiceProviderInterface",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 504,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 504,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "provider",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 506,
                                    "char": 18
                                },
                                "name": "register",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 506,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 506,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 506,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 507,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Registers a service provider.\n     *\n     * ```php\n     * use Phalcon\\DiInterface;\n     * use Phalcon\\Di\\ServiceProviderInterface;\n     *\n     * class SomeServiceProvider implements ServiceProviderInterface\n     * {\n     *     public function register(DiInterface $di)\n     *     {\n     *         $di->setShared(\n     *             'service',\n     *             function () {\n     *                 \/\/ ...\n     *             }\n     *         );\n     *     }\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 505,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 504,
                    "last-line": 512,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 513,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 515,
                                        "char": 20
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 515,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 515,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 515,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 515,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 516,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 516,
                                        "char": 20
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "sharedInstances",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 516,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 516,
                                    "char": 36
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 516,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 516,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 517,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a service in the services container\n     * It also removes any shared instance created for the service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 514,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 513,
                    "last-line": 521,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "reset",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "_default",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 524,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 524,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 525,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets the internal default DI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 523,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 522,
                    "last-line": 529,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 530,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 530,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "shared",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 530,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 530,
                            "char": 74
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
                                    "property": "services",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 532,
                                            "char": 32
                                        }
                                    ],
                                    "expr": {
                                        "type": "new",
                                        "class": "Service",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "definition",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 532,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 532,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "shared",
                                                    "file": "\/app\/phalcon\/Di.zep",
                                                    "line": 532,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Di.zep",
                                                "line": 532,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 532,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 532,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 534,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 534,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 534,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 534,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 534,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 534,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 535,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Registers a service in the services container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 531,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 531,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 531,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 530,
                    "last-line": 540,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setDefault",
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
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 541,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 541,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "_default",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 543,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 543,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 544,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set a default dependency injection container to be obtained into static\n     * methods\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 542,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 541,
                    "last-line": 548,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setInternalEventsManager",
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
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 549,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 549,
                            "char": 78
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
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 551,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 551,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 552,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the internal event manager\n     *",
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 549,
                    "last-line": 556,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRaw",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 557,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "rawDefinition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ServiceInterface",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 557,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 557,
                            "char": 74
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
                                    "property": "services",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 559,
                                            "char": 32
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "rawDefinition",
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 559,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 559,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 561,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "rawDefinition",
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 561,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 562,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a service using a raw Phalcon\\Di\\Service definition\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 558,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 558,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 558,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 557,
                    "last-line": 566,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setShared",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 567,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 567,
                            "char": 59
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
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 569,
                                    "char": 21
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 569,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 569,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 569,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 569,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Di.zep",
                                            "line": 569,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Di.zep",
                                        "line": 569,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 569,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Di.zep",
                            "line": 570,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Registers an \"always shared\" service in the services container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ServiceInterface",
                                    "file": "\/app\/phalcon\/Di.zep",
                                    "line": 568,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di.zep",
                                "line": 568,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di.zep",
                        "line": 568,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di.zep",
                    "line": 567,
                    "last-line": 571,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Di.zep",
            "line": 63,
            "char": 5
        },
        "file": "\/app\/phalcon\/Di.zep",
        "line": 63,
        "char": 5
    }
]