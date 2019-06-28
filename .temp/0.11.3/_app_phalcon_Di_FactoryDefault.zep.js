[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Di",
        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\FilterFactory",
                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                "line": 13,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is a variant of the standard Phalcon\\Di. By default it automatically\n * registers all the services provided by the framework. Thanks to this, the\n * developer does not need to register each service individually providing a\n * full stack framework\n *",
        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "FactoryDefault",
        "abstract": 0,
        "final": 0,
        "extends": "\\Phalcon\\Di",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "filter",
                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                    "line": 28,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                            "line": 30,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                "line": 30,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                            "line": 32,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filter",
                                    "expr": {
                                        "type": "new",
                                        "class": "FilterFactory",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                        "line": 32,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                    "line": 32,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                            "line": 34,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "services",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "annotations",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 35,
                                                    "char": 24
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Annotations\\\\Adapter\\\\Memory",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 35,
                                                                "char": 82
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 35,
                                                            "char": 82
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 35,
                                                                "char": 88
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 35,
                                                            "char": 88
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 35,
                                                    "char": 89
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 35,
                                                "char": 89
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "assets",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 36,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Assets\\\\Manager",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 36,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 36,
                                                            "char": 69
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 36,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 36,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 36,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 36,
                                                "char": 76
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "crypt",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 37,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Crypt",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 37,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 37,
                                                            "char": 59
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 37,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 37,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 37,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 37,
                                                "char": 66
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "cookies",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 38,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Http\\\\Response\\\\Cookies",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 38,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 38,
                                                            "char": 77
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 38,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 38,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 38,
                                                    "char": 84
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 38,
                                                "char": 84
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "dispatcher",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 39,
                                                    "char": 23
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Mvc\\\\Dispatcher",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 39,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 39,
                                                            "char": 69
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 39,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 39,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 39,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 39,
                                                "char": 76
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "escaper",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 40,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Escaper",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 40,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 40,
                                                            "char": 61
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 40,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 40,
                                                            "char": 67
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 40,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 40,
                                                "char": 68
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 41,
                                                    "char": 26
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Events\\\\Manager",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 41,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 41,
                                                            "char": 69
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 41,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 41,
                                                            "char": 75
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 41,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 41,
                                                "char": 76
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "flash",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 42,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Flash\\\\Direct",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 42,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 42,
                                                            "char": 67
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 42,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 42,
                                                            "char": 73
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 42,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 42,
                                                "char": 74
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "flashSession",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 43,
                                                    "char": 25
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Flash\\\\Session",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 43,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 43,
                                                            "char": 68
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 43,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 43,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 43,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 43,
                                                "char": 75
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "filter",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 44,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "filter",
                                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                    "line": 44,
                                                                    "char": 52
                                                                },
                                                                "name": "newInstance",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 44,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 44,
                                                            "char": 66
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 44,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 44,
                                                            "char": 72
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 44,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 44,
                                                "char": 73
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "modelsManager",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 45,
                                                    "char": 26
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Mvc\\\\Model\\\\Manager",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 45,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 45,
                                                            "char": 73
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 45,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 45,
                                                            "char": 79
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 45,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 45,
                                                "char": 80
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "modelsMetadata",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 46,
                                                    "char": 27
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Mvc\\\\Model\\\\MetaData\\\\Memory",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 46,
                                                                "char": 82
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 46,
                                                            "char": 82
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 46,
                                                                "char": 88
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 46,
                                                            "char": 88
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 46,
                                                    "char": 89
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 46,
                                                "char": 89
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "request",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 47,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Http\\\\Request",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 47,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 47,
                                                            "char": 67
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 47,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 47,
                                                            "char": 73
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 47,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 47,
                                                "char": 74
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "response",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 48,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Http\\\\Response",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 48,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 48,
                                                            "char": 68
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 48,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 48,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 48,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 48,
                                                "char": 75
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "router",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 49,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Mvc\\\\Router",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 49,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 49,
                                                            "char": 65
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 49,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 49,
                                                            "char": 71
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 49,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 49,
                                                "char": 72
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "security",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 50,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Security",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 50,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 50,
                                                            "char": 62
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 50,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 50,
                                                            "char": 68
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 50,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 50,
                                                "char": 69
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "tag",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 51,
                                                    "char": 16
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Tag",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 51,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 51,
                                                            "char": 57
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 51,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 51,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 51,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 51,
                                                "char": 64
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "transactionManager",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 52,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Mvc\\\\Model\\\\Transaction\\\\Manager",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 52,
                                                                "char": 86
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 52,
                                                            "char": 86
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 52,
                                                                "char": 92
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 52,
                                                            "char": 92
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 52,
                                                    "char": 93
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 52,
                                                "char": 93
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "url",
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 53,
                                                    "char": 16
                                                },
                                                "value": {
                                                    "type": "new",
                                                    "class": "Service",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Url",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 53,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 53,
                                                            "char": 57
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                                "line": 53,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                            "line": 53,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                    "line": 54,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                                "line": 54,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                        "line": 54,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                                    "line": 54,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Di\\FactoryDefault constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                        "line": 27,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
                    "line": 26,
                    "last-line": 56,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Di\/FactoryDefault.zep",
        "line": 21,
        "char": 5
    }
]